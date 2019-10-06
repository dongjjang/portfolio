#include <pthread.h>            //윈도우로 코딩하고 Mac os로 컴파일하였음
#include <semaphore.h>
#include <stdio.h>

int buffer[10];  // 버퍼의 크기는 10으로 지정
int in = -1;    // 생산자가 생산한 물건을 넣을 인덱스
int out = -1;   // 소비자가 생산된 물건을 가져갈 인덱스

void *producer(void *param);    // 생산자 스레드 함수
void *consumer(void *param);    // 소비자 스레드 함수

sem_t empty_slot;
sem_t data_slot;

int main() {
    //생산자와 소비자의 스레드 아이디를 지정
    pthread_t threads[2];

    //생산자와 소비자 스레드를 각각 생성
    pthread_create(threads[0], NULL, producer, NULL);
    pthread_create(threads[1], NULL, consumer, NULL);

    // 2개의 스레드가 수행을 마치고 join되기를 기다림
    for(int i=0; i<2; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_exit(NULL);         // Thread를 소멸시킴

    /* 사용한 세마포어도 없애준다. */
    sem_destroy(&empty_slot);
    sem_destroy(&data_slot);

    return 0;
}

// 생산자 스레드
void *producer(void *param) {
    for(int i=0; i<10; i++) {               // 데이터 생산
        printf("생산된 데이터 = %d\n", i);  // 생산된 데이터 표기해줌

        sem_wait(&empty_slot);      // 빈 슬롯을 생길때까지 대기시킴.

        in++;
        in %= 10;
        buffer[in] = i;             // 생산한 물건을 버퍼에 넣음

        sem_post(&data_slot);      // 물건을 하나 생산했으므로 data_slot에 신호를 주고
    }                              // Consumer를 깨워준다.
}

// 소비자 스레드
void *consumer(void *param) {
    int data;

    for(int i=0; i<10; i++) {        // 데이터 소비
        sem_wait(&data_slot);      // 생산자가 데이터를 생산할때까지 기다리고있음.

        out++;
        out %= 10;
        data = buffer[out];         // 버퍼에서 물건을 가져옴.

        // 물건을 가져갔으므로 empty_slot에 신호를 주고 Producer를 깨워준다.
        sem_post(&empty_slot);

        printf("                   가져간 데이터 = %d\n", data);        
    }
}

