#include <iostream>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>
#include "dxl.hpp"
using namespace std;
bool ctrl_c_pressed = false;
void ctrlc(int) { ctrl_c_pressed= true; }
int main(void)
{
    Dxl mx;
    struct timeval start, end1;
    int leftspeed, rightspeed;
    double time1;
    signal(SIGINT, ctrlc); //시그널핸들러지정
    if(!mx.open()) { cout<< "dynamixelopen error"<<endl; return-1; } //장치열기

    while(true)
    {
        gettimeofday(&start,NULL);  //시작시간 저장
        cout<<"left speed:";
        cin>>leftspeed;
        cout<<"right speed:";
        cin>>rightspeed;
        mx.setVelocity(leftspeed, rightspeed); //속도명령전송
        usleep(20*1000); //20msec sleep 
        if(ctrl_c_pressed) break; //Ctrl+c누르면탈출
        gettimeofday(&end1,NULL);
        //실행시간 = 종료시간 - 시작시간
        time1=end1.tv_sec-start.tv_sec+(end1.tv_usec-start.tv_usec)/1000000.0;
        cout << "time:" << time1 << endl; //실행시간출력 (단위 : 초)
    }
    mx.close(); //장치닫기
    return 0;
}