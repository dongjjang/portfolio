monitor bounded_buffer {
    int items[MAX_ITEMS];       // 최대치 설정
    int numOfItems = 0;         // 버퍼의 갯수

    condition full, empty;      // 모니터 내부 버퍼의 상태;
    
    void produce(int v) {
        while (numOfItems == MAX_ITEMS)
            full.wait();        // 버퍼가 가득차면 대기시킴
        items[numItems++] = v;  // 그게 아니라면 버퍼를 채우고 값을 1을 더해줌
        empty.signal()            // 버퍼를 비우라는 신호를 보냄
    }

    int consume() {             
        int retVal;
        while (numOfItems == 0)   // 비울 버퍼가 없다면
            empty.wait();         // 비우는것을 대기시킴  
        retVal = items[--numItems]; // 버퍼를 비우고 값을 1씩 줄임
        full.signal();            // 버퍼를 채우라는 신호를 보냄

        return retVal;              // 상태값을 반환함.
    }
}
