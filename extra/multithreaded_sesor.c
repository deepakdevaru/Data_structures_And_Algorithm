#if 0 

Design a multi threaded sensor. 
1. Sensor sends in data at regular intercal to a HW 
2. HW stores the data 
3. At the same time there are 10 threads who are consuming the data.
Design a multi threaded system for this 

#endif //if 0

/**
 * a Bonded block queue to house data
 * a producer to produce the data and store it in bonded queue 
 * 10 consumers who will consume the data
 * 
 * producer and consumer will share the mutex
 * all consumers will share a semaphore of size 10
 * once all semaphores are in wait state , other threads will sleep
 * Once consumer is working on the data , producer can still pass the data onto queue , but the size should not overlap the consumers 
 * current processing 


 * a callback function for signal handling
 * 
 * 
 * 
*/



#include "stdio.h"
#include "signal.h"
#include "stdlib.h"
#include"string.h"
#include "semaphore.h"
#include"pthread.h"
#include "unistd.h"

#define MAX_BUFFER 20
#define MAX_CONSUMERS 10
#define MAX_SEMA 10

typedef char byte;

/**bonded queue structure*/
typedef struct bondedQueue{
    byte *data;
    int size;
    int head; //tracked at producer
    int tail; //tracked at consumer
    int capacity;
    int kill;
    pthread_mutex_t mutex; //shared b/w consumer and producer
    pthread_cond_t  enqueue_avail; 
    pthread_cond_t  dequeue_avail;
    sem_t sem_c;
    int max_consumers;
}bondedQueue;


typedef enum signal_cb_e{
    ENQUEUE_AVAIL = 1,
    DEQUEUE_AVAIL = 2,
    MAX_PROCESS
}sig_e;

typedef enum signal_type_cb{
    SIGNAL_WAIT = 1,
    SIGNAL_PROCESS = 2,
    SIGNAL_MAX
}signal_type_cb;

typedef enum failure_type{
    ERROR_NONE = 0,
    INVALID_ARG = 1,
    INSUFFICIENT_MEM_AVAIL
}failure_type;


failure_type signal_wait_cb(sig_e sig_type , bondedQueue *queue){
    switch(sig_type){
      case ENQUEUE_AVAIL:
          pthread_cond_wait(&queue->enqueue_avail,&queue->mutex);
          break;
      case DEQUEUE_AVAIL:
          pthread_cond_wait(&queue->dequeue_avail,&queue->mutex);
          break;
       default:
           return INVALID_ARG;
    }
    
      return ERROR_NONE;         
}


failure_type signal_process_cb(sig_e sig_type, bondedQueue *queue){

    switch(sig_type){
      case ENQUEUE_AVAIL:
          pthread_cond_signal(&queue->enqueue_avail);
          break;
      case DEQUEUE_AVAIL:
          pthread_cond_signal(&queue->dequeue_avail);
       default:
           return INVALID_ARG;
    }
    
      return ERROR_NONE;         
}

typedef failure_type (*send_signal_cb)(sig_e , bondedQueue* );
static send_signal_cb signal_cb_f[SIGNAL_MAX] = {
         &signal_wait_cb,
         &signal_process_cb
};

void dequeue(void *info);
void enqueue(void * info);
failure_type  initBondedQueue(bondedQueue *queue, int queue_Capacity , int max_consumers);
void producer_thread(bondedQueue *queue , byte data);
byte consumer_thread(bondedQueue *queue );


void enqueue(void *info){
    bondedQueue *queue = (bondedQueue*)info;

    int random = 1;
    int i = 0;
    while(i < 24){
        random = rand() * i / 10;
        producer_thread(queue,(byte)random);
        i++;
        sleep(2);
    }
    sleep(5);

    queue->kill = 1;

    pthread_exit(NULL);
    return;
}
void dequeue(void* info){
    bondedQueue *queue = (bondedQueue*)info;
    while(queue->kill ==0){
    byte ans = consumer_thread(queue);
    printf("dequeuing data from producer");
    }
    pthread_exit(NULL);
}

void producer_thread(bondedQueue *queue , byte data){

     while(queue->size == queue->capacity){
          signal_cb_f[SIGNAL_WAIT](ENQUEUE_AVAIL,queue);
     }
     pthread_mutex_lock(&queue->mutex);
     queue->data[queue->head] = data;
     queue->head = (queue->head+1) %10;
     queue->size++;
    signal_cb_f[SIGNAL_PROCESS](DEQUEUE_AVAIL,queue);
    pthread_mutex_unlock(&queue->mutex);
    return;
}

 byte consumer_thread( bondedQueue *queue){
    byte data ;

     while(queue->size == 0 && queue->kill ==0){
          signal_cb_f[SIGNAL_WAIT](ENQUEUE_AVAIL,queue);
     }
     if(queue->kill ==1 ){
        return data;
     }
    sem_wait(&queue->sem_c);
    pthread_mutex_lock(&queue->mutex);

     data= queue->data[queue->tail];
     queue->tail = (queue->tail+1) %10;
     queue->size--;
     signal_cb_f[SIGNAL_PROCESS](ENQUEUE_AVAIL,queue);

     pthread_mutex_unlock(&queue->mutex);
     sem_post(&queue->sem_c);
    return data;
}

/**------------------------------------------------------------*/
failure_type initBondedQueue(bondedQueue *queue, int queue_Capacity , int max_consumers){

    if(queue_Capacity == 0 || max_consumers== 0 ){
         return INVALID_ARG;
    }
    queue = (bondedQueue*)malloc(sizeof(bondedQueue));

    if(queue == NULL){
        return INSUFFICIENT_MEM_AVAIL;
    }
    memset(queue , 0 , sizeof(bondedQueue));

    queue -> data = (byte*)malloc(sizeof(byte)* queue_Capacity);
    if(queue ->data == NULL){
         return INSUFFICIENT_MEM_AVAIL;
    }
    memset (queue->data , 0 , sizeof(byte)*queue_Capacity);

    queue->size = 0;
    queue->tail = 0;
    queue->head = 0;
    queue->kill = 0;
    queue->capacity = queue_Capacity;
    queue->max_consumers = max_consumers;

    pthread_mutex_init(&queue->mutex, NULL);
    pthread_cond_init(&queue->enqueue_avail ,NULL );
    pthread_cond_init(&queue->dequeue_avail ,NULL );
    sem_init(&queue->sem_c,0,1);

    return ERROR_NONE;

}

void destroyBondedQueue(bondedQueue *queue){

    queue->capacity = 0;
    queue->size = 0;
    queue->head = 0;
    queue->tail = 0;

    free (queue->data);
    pthread_mutex_destroy(&queue->mutex);
    pthread_cond_destroy(&queue->enqueue_avail);
    pthread_cond_destroy(&queue->dequeue_avail);
    sem_destroy(&queue->sem_c);

    free(queue);

    return;


}

int main(){ 

    bondedQueue *queue = NULL;
    initBondedQueue(queue, MAX_BUFFER,MAX_CONSUMERS);
    pthread_t c_threads[MAX_CONSUMERS];
    pthread_t p_thread;

     pthread_create(&p_thread, NULL, (void*)enqueue, (void*)queue);

    int i = 0;
    while(i < MAX_CONSUMERS){
        pthread_create(&c_threads[i], NULL , (void*)dequeue, (void*)dequeue);
        i++;
    }

    pthread_join(p_thread, NULL);
    
    i = 0;
    while(i < MAX_CONSUMERS){
        pthread_join(c_threads[i], NULL);
        i++;
    }
    destroyBondedQueue(queue);
    return 1;
}


