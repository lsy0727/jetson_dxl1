# jetson_dxl1

## 설명

https://github.com/lsy0727/jetson_dxl1/blob/e88bf0d5db248863b0aeeaec26ce755e3232b7cc/main.cpp#L15

SIGINT신호 처리시 crtlc 함수 호출

https://github.com/lsy0727/jetson_dxl1/blob/154c783f4a53964c7807fa133fb1b4f60ab98f67/main.cpp#L20-L26

line 21~24 : 좌측 바퀴 속도와 우측 바퀴 속도를 입력

line 25 : 입력받은 속도값을 모터에 전송해 모터의 속도를 설정

line 26 : 모터를 원활하게 제어하기 위해 약간의 대기시간 설정

https://github.com/lsy0727/jetson_dxl1/blob/a9ec8372e777c62f764b1326ea73b1d9181b2dfb/main.cpp#L33

프로그램 종료시 반드시 close

## 실행결과

![image](https://github.com/user-attachments/assets/bd9ac33c-a278-4957-94a5-fbe2f1ef92a7)

## 문제점

1. ctrl+c 를 입력시 바로 종료되지 않는다.

-> ctrl+c를 입력해도 cin이 입력 대기중이기 때문에 while문이 멈춰있음. 따라서 cin 입력을 종료해야 프로그램이 종료됨.

2. 입력한 속도 명령값이 현재 모터의 속도와 차이가 클 때 소음과 진동이 발생한다.

-> (입력한 속도 명령값)과 (현재 모터의 속도) 차이를 계산하고, 한번에 변경가능한 속도를 정해 일정 시간의 딜레이를 주어 변경한다.
