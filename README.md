# SCC_CH2-5
## UE_LOG를 활용한 간단한 좌표이동 프로그램
결과물: MovingActor.h 와 MovingActor.cpp 파일

### 필수 기능
![image](https://github.com/user-attachments/assets/17463c78-556d-401f-b098-ea1ff9fa4043)
* 해당 UML을 참고하여 구현
* 구현된 기능
  * Step 함수 : FMath::RandRange 를 통해 0 또는 1의 값을 리턴해주는 함수
  * Move 함수 : Step 함수의 리턴 값을 통해 Actor의 position을 움직여주고, UE_LOG를 통해 현재 위치를 출력하는 함수
 
### 도전 기능
![image](https://github.com/user-attachments/assets/bf275278-f439-4649-a5d9-d42a25316c5c)
* 해당 UML을 참고하여 구현
* 구현된 기능
  * Distance 함수 : FVector2D 두개를 받아서 두 위치 사이의 거리를 구해 리턴하는 함수
  * CreateEvent 함수 : 50% 확률로 특정 이벤트를 발생하도록 하는 함수(해당 함수에서는 0 또는 1의 값을 리턴한 다음 main 로직에서 해당 값을 통해 이벤트가 발생했는지 여부를 확인하도록 구현)
 
### 실행 모습
![image](https://github.com/user-attachments/assets/74cf25b2-e532-43bb-864e-4cb9acc280cf)
