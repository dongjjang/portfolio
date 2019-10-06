pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;  // 스레드 초기화

/* 락을 획득하는 사실을 정의하는 함수 */
void acquire(lock *mutex){
    while(!available);          // 바쁜 대기 상태 == spinlock이 걸린 상태
    available = false;          // acquire() 함수로의 진입이 허가된다면(락을 획득)
}                               // 사용 가능상태는 false가 됨.

/* 락을 반환하는 사실을 정의하는 함수 */
void release(lock *mutex){
    available = true;           // 임계구역을 탈출한 프로세스는 다른 프로세스로
}                               // 락을 반환

/* 1. test_and_set을 사용하는 방안 */
do{
    while(test_and_set(&lock));
    available = 0;
} while(1)

/* compare_and_swap을 사용하는 방안 */
do{
    while(compare_and_swap(&lock, 0, 1) != 0);
    available = 0;
} while(1);
