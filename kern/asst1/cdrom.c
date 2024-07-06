/* This file will contain your solution. Modify it as you wish. */
#include <types.h>
#include <lib.h>
#include <synch.h>
#include "cdrom.h"

#define RESULT_NOT_AVAILABLE -1
#define NO_BLOCK_NUM -1
#define FALSE 0
#define TRUE 1

typedef struct request {
  int block_num;
  int result;
  int is_available;
  int have_handler;
  struct cv *req_cv;
  struct lock *req_lock;
} request;

request requests[MAX_CONCURRENT_REQ];
struct lock *requests_lock;
struct cv *requests_cv;
int outstanding_req = 0;


/*
* cdrom_read: This is the client facing interface to the cdrom that makes
* requests to the cdrom system. 
* 
* Args :-
* block_num: The block number of the cdrom that the client is requesting the
* content from.
*
* This function makes a request to the cdrom system using the cdrom_block_request()
* function. cdrom_block_request() returns immediately before the request has completed.
* cdrom_read() then puts the current thread to sleep until the request completes,
* upon which, this thread needs to the woken up, the value from the specific block
* obtained, and the value is return to the requesting client.
*/
unsigned int cdrom_read(int block_num) {
  kprintf("Received request read block %d\n",block_num);
  request *free_req = NULL;

  // acquire lock to access the requests array
  lock_acquire(requests_lock);

  // put thread to sleep if too many outstanding request
  while(outstanding_req == MAX_CONCURRENT_REQ)
    cv_wait(requests_cv,requests_lock);
  outstanding_req++;
  // find the free request slot
  for(int i = 0; i < MAX_CONCURRENT_REQ; i++){
    if(requests[i].is_available){
      free_req = &requests[i];
      // claiming the free slot
      lock_acquire(free_req->req_lock);
      free_req->is_available = FALSE;
      free_req->block_num = block_num;
      free_req->have_handler = FALSE;
      lock_release(free_req->req_lock);
      break;
    }
  }
  lock_release(requests_lock);

  // make the request
  cdrom_block_request(block_num);

  lock_acquire(free_req->req_lock);
  // put thread to sleep if the result is not available yet
  while(free_req->result == RESULT_NOT_AVAILABLE){
    cv_wait(free_req->req_cv,free_req->req_lock);
  }
  int result = free_req->result;

  // change request back to being available
  free_req -> is_available = TRUE;
  free_req -> result = RESULT_NOT_AVAILABLE;
  free_req -> have_handler = FALSE;
  free_req->block_num = NO_BLOCK_NUM;
  lock_release(free_req->req_lock);

  lock_acquire(requests_lock);
  outstanding_req--;
  cv_signal(requests_cv,requests_lock);
  lock_release(requests_lock);
  return result;
}

/*
* cdrom_handler: This function is called by the system each time a cdrom block request
* has completed.
* 
* Args:-
* block_num: the number of the block originally requested from the cdrom.
* value: the content of the block, i.e. the data value retrieved by the request.
* 
* The cdrom_handler runs in its own thread. The handler needs to deliver the value 
* to the original requestor and wake the requestor waiting on the value.
*/

void cdrom_handler(int block_num, unsigned int value)
{
  request *req = NULL;
  int done_searching = FALSE;

  for(int i = 0; i < MAX_CONCURRENT_REQ && !done_searching; i++){
    if(!requests[i].have_handler && requests[i].block_num == block_num) {
      req = &requests[i];
      lock_acquire(req->req_lock);
      // if condition to check no other handler has already claim this request
      if(!req->have_handler && req->block_num == block_num){
        req->have_handler = TRUE;
        done_searching = TRUE;
        req->result = value;
        cv_signal(req->req_cv,req->req_lock);
      }
      lock_release(req->req_lock);
    }
  }

}

/*
* cdrom_startup: This is called at system initilisation time, 
* before the various threads are started. Use it to initialise 
* or allocate anything you need before the system starts.
*/
void cdrom_startup(void) {
  requests_lock = lock_create("requests lock");
  requests_cv = cv_create("requests cv");

  if(requests_cv == NULL || requests_lock == NULL)
    panic("error in creating lock or cv for requests");
  for(int i = 0; i < MAX_CONCURRENT_REQ; i++){
    requests[i].req_cv = cv_create("request cv");
    requests[i].req_lock = lock_create("request lock");
    if(requests[i].req_cv == NULL || requests->req_lock == NULL)
      panic("error in creating new cv or lock for request");
    requests[i].block_num = NO_BLOCK_NUM;
    requests[i].is_available = TRUE;
    requests[i].have_handler = FALSE;
    requests[i].result = RESULT_NOT_AVAILABLE;
  }
}

/*
* cdrom_shutdown: This is called after all the threads in the system
* have completed. Use this function to clean up and de-allocate anything
* you set up in cdrom_startup()
*/
void cdrom_shutdown(void) {
  lock_destroy(requests_lock);
  cv_destroy(requests_cv);
  for(int i = 0; i < MAX_CONCURRENT_REQ; i++){
    cv_destroy(requests[i].req_cv);
    lock_destroy(requests[i].req_lock);
  }
}

/* Just a sanity check to warn about including the internal header file 
   It contains nothing relevant to a correct solution and any use of 
   what is contained is likely to result in failure in our testing 
   */

#if defined(CDROM_TESTER_H) 
#error Do not include the cdrom_tester header file
#endif