#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <windows.h>

int isJumping=0;

void dispBg(){
    readimagefile("./bg.jpg",0,0,1400,400);
    //setfillstyle(1,9);
    //bar(0,0,1400,400);
    setfillstyle(1,10);
    bar(0,400,1400,800);
    readimagefile("./lives.jpg",50,600,350,740);
}

void jumper(int x1,int y1,int x2,int y2){
    //setfillstyle(1,2);
    //bar(x1,y1,x2,y2);
    readimagefile("./jump.jpg",x1,y1,x2,y2);
}

void obs(int x1,int y1,int x2,int y2){
    setfillstyle(1,15);
    bar(x1,y1,x2,y2);
}

int main(){
    initwindow(1400,800,"Jumping");
    dispBg();
    readimagefile("./stand.jpg",140,300,260,400);
    while(1){
    for(int i=0;i<=1260;i=i+70){
            if(GetAsyncKeyState(VK_SPACE) && i/float(140)<=8.50 && i/float(140)>=7.00){
                isJumping=1;
                //Hide
                setfillstyle(1,9);
                bar(140,300,280,400);

                jumper(140,100,280,200);

                setfillstyle(1,15);
                bar(220,360,260,400);

                delay(100);

                setfillstyle(1,15);
                bar(220,360,280,400);

                delay(10);

                setfillstyle(1,9);
                bar(200,300,300,400);

                i=i+150;

                setfillstyle(1,9);
                bar(140,100,280,200);
        }
        if(isJumping==0 && i/70>=16)
        {
            readimagefile("./stand.jpg",140,300,260,400);
            obs(1300-i+60,360,1360-i+60,400);
            delay(5000);
            cleardevice();
            dispBg();
            break;
        }
        isJumping=0;
        readimagefile("./stand.jpg",140,300,260,400);
        //jumper(140,300,280,400);
        obs(1300-i,360,1360-i,400);
        delay(60);

        //Hide obs
        setfillstyle(1,9);
        bar(1280-i,300,1380-i,400);
    }
    }
    getch();
    closegraph();
}
