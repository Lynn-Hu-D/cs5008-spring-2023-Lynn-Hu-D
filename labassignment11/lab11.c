//Enter your name here
//Enter your email here
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t chopstick[5];//lock variable

// Thread to be executed
void *philosopher(void *x)
{
 //Treat variable x as a pointer to an int and then extract the value into n
    int* a=(int*)x;
    int n=*a;
       /*-----Insert your code here----*/
    int leftlock = n%5;
    int rightlock = (n+1) % 5;
    if (leftlock > rightlock) {
      int tmp = leftlock;
      leftlock = rightlock;
      rightlock = tmp;
    }
    int eat = 0;
    while (eat == 0) 
    {
      printf("philosopher %d is thinking.\n", n+1);
      while (pthread_mutex_lock(&chopstick[leftlock])) {
        printf("philosopher %d is thinking.\n", n+1);
        sleep(2);
      };
      while (pthread_mutex_lock(&chopstick[rightlock])) {
        printf("philosopher %d is thinking.\n", n+1);
        sleep(2);
      };
      printf("philosopher %d is eating using chopstick[%d] and chopstick[%d].\n", n+1, leftlock, rightlock);
      sleep(2);
      printf("philosopher %d finished eating\n", n+1);
      eat = 1;
      pthread_mutex_unlock(&chopstick[leftlock]);
      pthread_mutex_unlock(&chopstick[rightlock]);
    }
    return 0;
}


/*------------ Main Program---------*/
int main()
{
  int i,val[5];
  pthread_t threads[5];  
//initializing the mutex (for chopsticks)
    for(i=0;i<5;i++){
       pthread_mutex_init(&chopstick[i],NULL); 
    }   
//create and run the thread
  for(i=0;i<5;i++){
    val[i]=i;
    pthread_create(&threads[i],NULL,(void *)philosopher,&val[i]);
  }  
    
//wait until all the threads are done
    for(i=0;i<5;i++){
        pthread_join(threads[i],NULL);
    }
    
// Destroying the mutex
    for(i=0;i<5;i++){
       pthread_mutex_destroy(&chopstick[i]);
    }
    
    return 0;
}
