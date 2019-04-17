#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <windows.h>
#include <mmsystem.h>
int isJumping=0;
int sc=1;
int lives=3;
void dispBg();

int marioJumping[16][16]={
    {9,9,9,9,9,4,4,4,4,9,9,14,14,14,9,9},
    {9,9,9,9,4,4,4,4,4,4,4,4,4,14,14,9},
    {9,9,9,9,6,6,6,14,14,0,14,9,4,4,4,9},
    {9,9,9,6,14,6,14,14,14,0,14,14,14,4,4,9},
    {9,9,9,6,14,6,6,14,14,14,0,14,14,14,4,9},
    {9,9,9,9,9,14,14,14,14,14,14,14,4,4,9,9},
    {9,9,4,4,4,4,5,4,4,4,5,4,4,9,9,6},
    {14,14,4,4,4,4,4,5,4,4,4,5,9,9,6,6},
    {14,14,14,4,4,4,4,5,5,5,5,15,5,5,6,6},
    {9,14,9,9,5,4,5,5,15,5,5,5,5,5,6,6},
    {9,9,6,6,6,5,5,5,5,5,5,5,5,5,6,6},
    {9,6,6,6,5,5,5,5,5,5,9,9,9,9,9,9},
    {9,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

int marioStanding[16][16]={
    {9,9,9,9,9,4,4,4,4,9,9,14,14,14,9,9},
    {9,9,9,9,4,4,4,4,4,4,4,4,4,14,14,9},
    {9,9,9,9,6,6,6,14,14,0,14,9,4,4,4,9},
    {9,9,9,6,14,6,14,14,14,0,14,14,14,4,4,9},
    {9,9,9,6,14,6,6,14,14,14,0,14,14,14,4,9},
    {9,9,9,9,9,14,14,14,14,14,14,14,4,4,9,9},
    {9,9,4,4,4,4,5,4,4,4,5,4,4,9,9,6},
    {14,14,4,4,4,4,4,5,4,4,4,5,9,9,6,6},
    {14,14,14,4,4,4,4,5,5,5,5,15,5,5,6,6},
    {9,14,9,9,5,4,5,5,15,5,5,5,5,5,6,6},
    {9,9,6,6,6,5,5,5,5,5,5,5,5,5,6,6},
    {9,6,6,6,5,5,5,5,5,5,9,9,9,9,9,9},
    {9,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9},
    {9,6,6,9,9,9,9,9,9,9,9,9,9,9,9,9},
};

void disp16(int x,int y,int size,int colorMatrix[16][16]){
    for(int i=0;i<16;i++){
        for(int j=0;j<16;j++){
            setfillstyle(1,colorMatrix[i][j]);
            bar(x+(j*size),i*size+y,x+((j+1)*size),((i+1)*size)+y);
        }
    }
}

void dispMarioStand(int x1,int y1,int x2,int y2){
    setfillstyle(1,9);
    bar(x1+0 ,0 +y1,x1+6 ,6 +y1);
    setfillstyle(1,9);
    bar(x1+6 ,0 +y1,x1+12,6 +y1);
    setfillstyle(1,9);
    bar(x1+12,0 +y1,x1+18,6 +y1);
    setfillstyle(1,9);
    bar(x1+18,0 +y1,x1+24,6 +y1);
    setfillstyle(1,4);
    bar(x1+24,0 +y1,x1+30,6 +y1);
    setfillstyle(1,4);
    bar(x1+30,0 +y1,x1+36,6 +y1);
    setfillstyle(1,4);
    bar(x1+36,0 +y1,x1+42,6 +y1);
    setfillstyle(1,4);
    bar(x1+42,0 +y1,x1+48,6 +y1);
    setfillstyle(1,4);
    bar(x1+48,0 +y1,x1+54,6 +y1);
    setfillstyle(1,9);
    bar(x1+54,0 +y1,x1+60,6 +y1);
    setfillstyle(1,9);
    bar(x1+60,0 +y1,x1+66,6 +y1);
    setfillstyle(1,9);
    bar(x1+66,0 +y1,x1+72,6 +y1);
    setfillstyle(1,9);
    bar(x1+72,0 +y1,x1+78,6 +y1);
    setfillstyle(1,9);
    bar(x1+78,0 +y1,x1+84,6 +y1);
    setfillstyle(1,9);
    bar(x1+84,0 +y1,x1+90,6 +y1);
    setfillstyle(1,9);
    bar(x1+90,0 +y1,x1+96,6 +y1);

    // two
    setfillstyle(1,9);
    bar(x1+0 ,6 +y1,x1+6 ,12+y1);
    setfillstyle(1,9);
    bar(x1+6 ,6 +y1,x1+12,12+y1);
    setfillstyle(1,9);
    bar(x1+12,6 +y1,x1+18,12+y1);
    setfillstyle(1,9);
    bar(x1+18,6 +y1,x1+24,12+y1);
    setfillstyle(1,4);
    bar(x1+24,6 +y1,x1+30,12+y1);
    setfillstyle(1,4);
    bar(x1+30,6 +y1,x1+36,12+y1);
    setfillstyle(1,4);
    bar(x1+36,6 +y1,x1+42,12+y1);
    setfillstyle(1,4);
    bar(x1+42,6 +y1,x1+48,12+y1);
    setfillstyle(1,4);
    bar(x1+48,6 +y1,x1+54,12+y1);
    setfillstyle(1,4);
    bar(x1+54,6 +y1,x1+60,12+y1);
    setfillstyle(1,4);
    bar(x1+60,6 +y1,x1+66,12+y1);
    setfillstyle(1,4);
    bar(x1+66,6 +y1,x1+72,12+y1);
    setfillstyle(1,4);
    bar(x1+72,6 +y1,x1+78,12+y1);
    setfillstyle(1,9);
    bar(x1+78,6 +y1,x1+84,12+y1);
    setfillstyle(1,9);
    bar(x1+84,6 +y1,x1+90,12+y1);
    setfillstyle(1,9);
    bar(x1+90,6 +y1,x1+96,12+y1);

    // three
    setfillstyle(1,9);
    bar(x1+0 ,12+y1,x1+6 ,18+y1);
    setfillstyle(1,9);
    bar(x1+6 ,12+y1,x1+12,18+y1);
    setfillstyle(1,9);
    bar(x1+12,12+y1,x1+18,18+y1);
    setfillstyle(1,9);
    bar(x1+18,12+y1,x1+24,18+y1);
    setfillstyle(1,6);
    bar(x1+24,12+y1,x1+30,18+y1);
    setfillstyle(1,6);
    bar(x1+30,12+y1,x1+36,18+y1);
    setfillstyle(1,6);
    bar(x1+36,12+y1,x1+42,18+y1);
    setfillstyle(1,14);
    bar(x1+42,12+y1,x1+48,18+y1);
    setfillstyle(1,14);
    bar(x1+48,12+y1,x1+54,18+y1);
    setfillstyle(1,0);
    bar(x1+54,12+y1,x1+60,18+y1);
    setfillstyle(1,14);
    bar(x1+60,12+y1,x1+66,18+y1);
    setfillstyle(1,9);
    bar(x1+66,12+y1,x1+72,18+y1);
    setfillstyle(1,9);
    bar(x1+72,12+y1,x1+78,18+y1);
    setfillstyle(1,9);
    bar(x1+78,12+y1,x1+84,18+y1);
    setfillstyle(1,9);
    bar(x1+84,12+y1,x1+90,18+y1);
    setfillstyle(1,9);
    bar(x1+90,12+y1,x1+96,18+y1);

    // four
    setfillstyle(1,9);
    bar(x1+0 ,18+y1,x1+6,24+y1);
    setfillstyle(1,9);
    bar(x1+6 ,18+y1,x1+12,24+y1);
    setfillstyle(1,9);
    bar(x1+12,18+y1,x1+18,24+y1);
    setfillstyle(1,6);
    bar(x1+18,18+y1,x1+24,24+y1);
    setfillstyle(1,14);
    bar(x1+24,18+y1,x1+30,24+y1);
    setfillstyle(1,6);
    bar(x1+30,18+y1,x1+36,24+y1);
    setfillstyle(1,14);
    bar(x1+36,18+y1,x1+42,24+y1);
    setfillstyle(1,14);
    bar(x1+42,18+y1,x1+48,24+y1);
    setfillstyle(1,14);
    bar(x1+48,18+y1,x1+54,24+y1);
    setfillstyle(1,0);
    bar(x1+54,18+y1,x1+60,24+y1);
    setfillstyle(1,14);
    bar(x1+60,18+y1,x1+66,24+y1);
    setfillstyle(1,14);
    bar(x1+66,18+y1,x1+72,24+y1);
    setfillstyle(1,14);
    bar(x1+72,18+y1,x1+78,24+y1);
    setfillstyle(1,9);
    bar(x1+78,18+y1,x1+84,24+y1);
    setfillstyle(1,9);
    bar(x1+84,18+y1,x1+90,24+y1);
    setfillstyle(1,9);
    bar(x1+90,18+y1,x1+96,24+y1);

    // five
    setfillstyle(1,9);
    bar(x1+0 ,24+y1,x1+6,30+y1);
    setfillstyle(1,9);
    bar(x1+6 ,24+y1,x1+12,30+y1);
    setfillstyle(1,9);
    bar(x1+12,24+y1,x1+18,30+y1);
    setfillstyle(1,6);
    bar(x1+18,24+y1,x1+24,30+y1);
    setfillstyle(1,14);
    bar(x1+24,24+y1,x1+30,30+y1);
    setfillstyle(1,6);
    bar(x1+30,24+y1,x1+36,30+y1);
    setfillstyle(1,6);
    bar(x1+36,24+y1,x1+42,30+y1);
    setfillstyle(1,14);
    bar(x1+42,24+y1,x1+48,30+y1);
    setfillstyle(1,14);
    bar(x1+48,24+y1,x1+54,30+y1);
    setfillstyle(1,14);
    bar(x1+54,24+y1,x1+60,30+y1);
    setfillstyle(1,0);
    bar(x1+60,24+y1,x1+66,30+y1);
    setfillstyle(1,14);
    bar(x1+66,24+y1,x1+72,30+y1);
    setfillstyle(1,14);
    bar(x1+72,24+y1,x1+78,30+y1);
    setfillstyle(1,14);
    bar(x1+78,24+y1,x1+84,30+y1);
    setfillstyle(1,9);
    bar(x1+84,24+y1,x1+90,30+y1);
    setfillstyle(1,9);
    bar(x1+90,24+y1,x1+96,30+y1);

    // six
    setfillstyle(1,9);
    bar(x1+0 ,30+y1,x1+6,36+y1);
    setfillstyle(1,9);
    bar(x1+6 ,30+y1,x1+12,36+y1);
    setfillstyle(1,9);
    bar(x1+12,30+y1,x1+18,36+y1);
    setfillstyle(1,9);
    bar(x1+18,30+y1,x1+24,36+y1);
    setfillstyle(1,6);
    bar(x1+24,30+y1,x1+30,36+y1);
    setfillstyle(1,14);
    bar(x1+30,30+y1,x1+36,36+y1);
    setfillstyle(1,14);
    bar(x1+36,30+y1,x1+42,36+y1);
    setfillstyle(1,14);
    bar(x1+42,30+y1,x1+48,36+y1);
    setfillstyle(1,14);
    bar(x1+48,30+y1,x1+54,36+y1);
    setfillstyle(1,0);
    bar(x1+54,30+y1,x1+60,36+y1);
    setfillstyle(1,0);
    bar(x1+60,30+y1,x1+66,36+y1);
    setfillstyle(1,0);
    bar(x1+66,30+y1,x1+72,36+y1);
    setfillstyle(1,0);
    bar(x1+72,30+y1,x1+78,36+y1);
    setfillstyle(1,9);
    bar(x1+78,30+y1,x1+84,36+y1);
    setfillstyle(1,9);
    bar(x1+84,30+y1,x1+90,36+y1);
    setfillstyle(1,9);
    bar(x1+90,30+y1,x1+96,36+y1);

    // seven
    setfillstyle(1,9);
    bar(x1+0 ,36+y1,x1+6,42+y1);
    setfillstyle(1,9);
    bar(x1+6 ,36+y1,x1+12,42+y1);
    setfillstyle(1,9);
    bar(x1+12,36+y1,x1+18,42+y1);
    setfillstyle(1,9);
    bar(x1+18,36+y1,x1+24,42+y1);
    setfillstyle(1,9);
    bar(x1+24,36+y1,x1+30,42+y1);
    setfillstyle(1,14);
    bar(x1+30,36+y1,x1+36,42+y1);
    setfillstyle(1,14);
    bar(x1+36,36+y1,x1+42,42+y1);
    setfillstyle(1,14);
    bar(x1+42,36+y1,x1+48,42+y1);
    setfillstyle(1,14);
    bar(x1+48,36+y1,x1+54,42+y1);
    setfillstyle(1,14);
    bar(x1+54,36+y1,x1+60,42+y1);
    setfillstyle(1,14);
    bar(x1+60,36+y1,x1+66,42+y1);
    setfillstyle(1,14);
    bar(x1+66,36+y1,x1+72,42+y1);
    setfillstyle(1,9);
    bar(x1+72,36+y1,x1+78,42+y1);
    setfillstyle(1,9);
    bar(x1+78,36+y1,x1+84,42+y1);
    setfillstyle(1,9);
    bar(x1+84,36+y1,x1+90,42+y1);
    setfillstyle(1,9);
    bar(x1+90,36+y1,x1+96,42+y1);

    // eight
    setfillstyle(1,9);
    bar(x1+0 ,42+y1,x1+6,48+y1);
    setfillstyle(1,9);
    bar(x1+6 ,42+y1,x1+12,48+y1);
    setfillstyle(1,9);
    bar(x1+12,42+y1,x1+18,48+y1);
    setfillstyle(1,9);
    bar(x1+18,42+y1,x1+24,48+y1);
    setfillstyle(1,4);
    bar(x1+24,42+y1,x1+30,48+y1);
    setfillstyle(1,4);
    bar(x1+30,42+y1,x1+36,48+y1);
    setfillstyle(1,5);
    bar(x1+36,42+y1,x1+42,48+y1);
    setfillstyle(1,4);
    bar(x1+42,42+y1,x1+48,48+y1);
    setfillstyle(1,4);
    bar(x1+48,42+y1,x1+54,48+y1);
    setfillstyle(1,5);
    bar(x1+54,42+y1,x1+60,48+y1);
    setfillstyle(1,4);
    bar(x1+60,42+y1,x1+66,48+y1);
    setfillstyle(1,4);
    bar(x1+66,42+y1,x1+72,48+y1);
    setfillstyle(1,9);
    bar(x1+72,42+y1,x1+78,48+y1);
    setfillstyle(1,9);
    bar(x1+78,42+y1,x1+84,48+y1);
    setfillstyle(1,9);
    bar(x1+84,42+y1,x1+90,48+y1);
    setfillstyle(1,9);
    bar(x1+90,42+y1,x1+96,48+y1);

    // nine
    setfillstyle(1,9);
    bar(x1+0 ,48+y1,x1+6,54+y1);
    setfillstyle(1,9);
    bar(x1+6 ,48+y1,x1+12,54+y1);
    setfillstyle(1,9);
    bar(x1+12,48+y1,x1+18,54+y1);
    setfillstyle(1,4);
    bar(x1+18,48+y1,x1+24,54+y1);
    setfillstyle(1,4);
    bar(x1+24,48+y1,x1+30,54+y1);
    setfillstyle(1,4);
    bar(x1+30,48+y1,x1+36,54+y1);
    setfillstyle(1,5);
    bar(x1+36,48+y1,x1+42,54+y1);
    setfillstyle(1,4);
    bar(x1+42,48+y1,x1+48,54+y1);
    setfillstyle(1,4);
    bar(x1+48,48+y1,x1+54,54+y1);
    setfillstyle(1,5);
    bar(x1+54,48+y1,x1+60,54+y1);
    setfillstyle(1,4);
    bar(x1+60,48+y1,x1+66,54+y1);
    setfillstyle(1,4);
    bar(x1+66,48+y1,x1+72,54+y1);
    setfillstyle(1,4);
    bar(x1+72,48+y1,x1+78,54+y1);
    setfillstyle(1,9);
    bar(x1+78,48+y1,x1+84,54+y1);
    setfillstyle(1,9);
    bar(x1+84,48+y1,x1+90,54+y1);
    setfillstyle(1,9);
    bar(x1+90,48+y1,x1+96,54+y1);

    // ten
    setfillstyle(1,9);
    bar(x1+0 ,54+y1,x1+6,60+y1);
    setfillstyle(1,9);
    bar(x1+6 ,54+y1,x1+12,60+y1);
    setfillstyle(1,14);
    bar(x1+12,54+y1,x1+18,60+y1);
    setfillstyle(1,14);
    bar(x1+18,54+y1,x1+24,60+y1);
    setfillstyle(1,4);
    bar(x1+24,54+y1,x1+30,60+y1);
    setfillstyle(1,5);
    bar(x1+30,54+y1,x1+36,60+y1);
    setfillstyle(1,8);
    bar(x1+36,54+y1,x1+42,60+y1);
    setfillstyle(1,5);
    bar(x1+42,54+y1,x1+48,60+y1);
    setfillstyle(1,5);
    bar(x1+48,54+y1,x1+54,60+y1);
    setfillstyle(1,8);
    bar(x1+54,54+y1,x1+60,60+y1);
    setfillstyle(1,5);
    bar(x1+60,54+y1,x1+66,60+y1);
    setfillstyle(1,4);
    bar(x1+66,54+y1,x1+72,60+y1);
    setfillstyle(1,14);
    bar(x1+72,54+y1,x1+78,60+y1);
    setfillstyle(1,14);
    bar(x1+78,54+y1,x1+84,60+y1);
    setfillstyle(1,9);
    bar(x1+84,54+y1,x1+90,60+y1);
    setfillstyle(1,9);
    bar(x1+90,54+y1,x1+96,60+y1);

    // eleven
    setfillstyle(1,9);
    bar(x1+0 ,60+y1,x1+6,66+y1);
    setfillstyle(1,9);
    bar(x1+6 ,60+y1,x1+12,66+y1);
    setfillstyle(1,14);
    bar(x1+12,60+y1,x1+18,66+y1);
    setfillstyle(1,14);
    bar(x1+18,60+y1,x1+24,66+y1);
    setfillstyle(1,14);
    bar(x1+24,60+y1,x1+30,66+y1);
    setfillstyle(1,4);
    bar(x1+30,60+y1,x1+36,66+y1);
    setfillstyle(1,5);
    bar(x1+36,60+y1,x1+42,66+y1);
    setfillstyle(1,5);
    bar(x1+42,60+y1,x1+48,66+y1);
    setfillstyle(1,5);
    bar(x1+48,60+y1,x1+54,66+y1);
    setfillstyle(1,5);
    bar(x1+54,60+y1,x1+60,66+y1);
    setfillstyle(1,5);
    bar(x1+60,60+y1,x1+66,66+y1);
    setfillstyle(1,14);
    bar(x1+66,60+y1,x1+72,66+y1);
    setfillstyle(1,14);
    bar(x1+72,60+y1,x1+78,66+y1);
    setfillstyle(1,14);
    bar(x1+78,60+y1,x1+84,66+y1);
    setfillstyle(1,9);
    bar(x1+84,60+y1,x1+90,66+y1);
    setfillstyle(1,9);
    bar(x1+90,60+y1,x1+96,66+y1);

    // tweleve
    setfillstyle(1,9);
    bar(x1+0 ,66+y1,x1+6,72+y1);
    setfillstyle(1,9);
    bar(x1+6 ,66+y1,x1+12,72+y1);
    setfillstyle(1,14);
    bar(x1+12,66+y1,x1+18,72+y1);
    setfillstyle(1,14);
    bar(x1+18,66+y1,x1+24,72+y1);
    setfillstyle(1,5);
    bar(x1+24,66+y1,x1+30,72+y1);
    setfillstyle(1,5);
    bar(x1+30,66+y1,x1+36,72+y1);
    setfillstyle(1,5);
    bar(x1+36,66+y1,x1+42,72+y1);
    setfillstyle(1,5);
    bar(x1+42,66+y1,x1+48,72+y1);
    setfillstyle(1,5);
    bar(x1+48,66+y1,x1+54,72+y1);
    setfillstyle(1,5);
    bar(x1+54,66+y1,x1+60,72+y1);
    setfillstyle(1,5);
    bar(x1+60,66+y1,x1+66,72+y1);
    setfillstyle(1,5);
    bar(x1+66,66+y1,x1+72,72+y1);
    setfillstyle(1,14);
    bar(x1+72,66+y1,x1+78,72+y1);
    setfillstyle(1,14);
    bar(x1+78,66+y1,x1+84,72+y1);
    setfillstyle(1,9);
    bar(x1+84,66+y1,x1+90,72+y1);
    setfillstyle(1,9);
    bar(x1+90,66+y1,x1+96,72+y1);

    // thirteen
    setfillstyle(1,9);
    bar(x1+0 ,72+y1,x1+6,78+y1);
    setfillstyle(1,9);
    bar(x1+6 ,72+y1,x1+12,78+y1);
    setfillstyle(1,9);
    bar(x1+12,72+y1,x1+18,78+y1);
    setfillstyle(1,9);
    bar(x1+18,72+y1,x1+24,78+y1);
    setfillstyle(1,5);
    bar(x1+24,72+y1,x1+30,78+y1);
    setfillstyle(1,5);
    bar(x1+30,72+y1,x1+36,78+y1);
    setfillstyle(1,5);
    bar(x1+36,72+y1,x1+42,78+y1);
    setfillstyle(1,9);
    bar(x1+42,72+y1,x1+48,78+y1);
    setfillstyle(1,9);
    bar(x1+48,72+y1,x1+54,78+y1);
    setfillstyle(1,5);
    bar(x1+54,72+y1,x1+60,78+y1);
    setfillstyle(1,5);
    bar(x1+60,72+y1,x1+66,78+y1);
    setfillstyle(1,5);
    bar(x1+66,72+y1,x1+72,78+y1);
    setfillstyle(1,9);
    bar(x1+72,72+y1,x1+78,78+y1);
    setfillstyle(1,9);
    bar(x1+78,72+y1,x1+84,78+y1);
    setfillstyle(1,9);
    bar(x1+84,72+y1,x1+90,78+y1);
    setfillstyle(1,9);
    bar(x1+90,72+y1,x1+96,78+y1);

    // fourteen
    setfillstyle(1,9);
    bar(x1+0 ,78+y1,x1+6,84+y1);
    setfillstyle(1,9);
    bar(x1+6 ,78+y1,x1+12,84+y1);
    setfillstyle(1,9);
    bar(x1+12,78+y1,x1+18,84+y1);
    setfillstyle(1,6);
    bar(x1+18,78+y1,x1+24,84+y1);
    setfillstyle(1,6);
    bar(x1+24,78+y1,x1+30,84+y1);
    setfillstyle(1,6);
    bar(x1+30,78+y1,x1+36,84+y1);
    setfillstyle(1,9);
    bar(x1+36,78+y1,x1+42,84+y1);
    setfillstyle(1,9);
    bar(x1+42,78+y1,x1+48,84+y1);
    setfillstyle(1,9);
    bar(x1+48,78+y1,x1+54,84+y1);
    setfillstyle(1,9);
    bar(x1+54,78+y1,x1+60,84+y1);
    setfillstyle(1,6);
    bar(x1+60,78+y1,x1+66,84+y1);
    setfillstyle(1,6);
    bar(x1+66,78+y1,x1+72,84+y1);
    setfillstyle(1,6);
    bar(x1+72,78+y1,x1+78,84+y1);
    setfillstyle(1,9);
    bar(x1+78,78+y1,x1+84,84+y1);
    setfillstyle(1,9);
    bar(x1+84,78+y1,x1+90,84+y1);
    setfillstyle(1,9);
    bar(x1+90,78+y1,x1+96,84+y1);

    // fifteen
    setfillstyle(1,9);
    bar(x1+0 ,84+y1,x1+6,90+y1);
    setfillstyle(1,9);
    bar(x1+6 ,84+y1,x1+12,90+y1);
    setfillstyle(1,6);
    bar(x1+12,84+y1,x1+18,90+y1);
    setfillstyle(1,6);
    bar(x1+18,84+y1,x1+24,90+y1);
    setfillstyle(1,6);
    bar(x1+24,84+y1,x1+30,90+y1);
    setfillstyle(1,6);
    bar(x1+30,84+y1,x1+36,90+y1);
    setfillstyle(1,9);
    bar(x1+36,84+y1,x1+42,90+y1);
    setfillstyle(1,9);
    bar(x1+42,84+y1,x1+48,90+y1);
    setfillstyle(1,9);
    bar(x1+48,84+y1,x1+54,90+y1);
    setfillstyle(1,9);
    bar(x1+54,84+y1,x1+60,90+y1);
    setfillstyle(1,6);
    bar(x1+60,84+y1,x1+66,90+y1);
    setfillstyle(1,6);
    bar(x1+66,84+y1,x1+72,90+y1);
    setfillstyle(1,6);
    bar(x1+72,84+y1,x1+78,90+y1);
    setfillstyle(1,6);
    bar(x1+78,84+y1,x1+84,90+y1);
    setfillstyle(1,9);
    bar(x1+84,84+y1,x1+90,90+y1);
    setfillstyle(1,9);
    bar(x1+90,84+y1,x1+96,90+y1);

    // sixteen
    // setfillstyle(1,9);
    // bar(x1+0 ,90+y1,x1+6,96+y1);
    // setfillstyle(1,9);
    // bar(x1+6 ,90+y1,x1+12,96+y1);
    // setfillstyle(1,9);
    // bar(x1+12,90+y1,x1+18,96+y1);
    // setfillstyle(1,9);
    // bar(x1+18,90+y1,x1+24,96+y1);
    // setfillstyle(1,9);
    // bar(x1+24,90+y1,x1+30,96+y1);
    // setfillstyle(1,9);
    // bar(x1+30,90+y1,x1+36,96+y1);
    // setfillstyle(1,9);
    // bar(x1+36,90+y1,x1+42,96+y1);
    // setfillstyle(1,9);
    // bar(x1+42,90+y1,x1+48,96+y1);
    // setfillstyle(1,9);
    // bar(x1+48,90+y1,x1+54,96+y1);
    // setfillstyle(1,9);
    // bar(x1+54,90+y1,x1+60,96+y1);
    // setfillstyle(1,9);
    // bar(x1+60,90+y1,x1+66,96+y1);
    // setfillstyle(1,9);
    // bar(x1+66,90+y1,x1+72,96+y1);
    // setfillstyle(1,9);
    // bar(x1+72,90+y1,x1+78,96+y1);
    // setfillstyle(1,9);
    // bar(x1+78,90+y1,x1+84,96+y1);
    // setfillstyle(1,9);
    // bar(x1+84,90+y1,x1+90,96+y1);
    // setfillstyle(1,9);
    // bar(x1+90,90+y1,x1+96,96+y1);
}

void dispStart(){
PlaySound(TEXT("./mario.wav"),NULL,SND_LOOP|SND_ASYNC);
readimagefile("./start_screen.jpg",0,0,1400,800);
while(1){
    if(GetAsyncKeyState(VK_SPACE)){
            cleardevice();
            dispBg();
            break;
        }
    }
}

void dispBg(){
    readimagefile("./bg.jpg",0,0,1400,400);
    //setfillstyle(1,9);
    //bar(0,0,1400,400);
    setfillstyle(1,10);
    bar(0,400,1400,800);
    if(lives==3){
        readimagefile("./lives.jpg",50,600,350,740);
    }
    else if(lives==2){
        readimagefile("./lives2.jpg",50,600,350,740);
    }
    else if(lives==1){
        readimagefile("./lives1.jpg",50,600,350,740);
    }
    readimagefile("./score1.jpg",930,650,1130,690);

}



void jumper(int x1,int y1,int x2,int y2){
    //setfillstyle(1,2);
    //bar(x1,y1,x2,y2);
    readimagefile("./jump.jpg",x1,y1,x2,y2);
}

void obs(int x1,int y1,int x2,int y2){
    //setfillstyle(1,15);
    //bar(x1,y1,x2,y2);
    readimagefile("./mushroom.jpg",x1,y1,x2,y2);
}

int main(){
    initwindow(1400,800,"Jumping");
    dispStart();
    //readimagefile("./stand.jpg",140,300,260,400);
    dispMarioStand(160,310,280,400);
    while(lives>=1){
    for(int i=0;i<=1260;i=i+70){
            if(GetAsyncKeyState(VK_SPACE) && i/float(140)<=8.50 && i/float(140)>=7.00){
                isJumping=1;
                char score[50];
                itoa(sc++,score,10);
                setcolor(WHITE);
                settextstyle(3,HORIZ_DIR,9);
                outtextxy(1150,620,score);
                //Hide
                setfillstyle(1,9);
                bar(140,300,280,400);

                //jumper(140,100,280,200);
                //dispMarioJump(140,100,280,200);
                disp16(140,100,6,marioJumping);

                setfillstyle(1,15);
                readimagefile("./mushroom.jpg",220,359,260,399);
                //bar(220,360,260,400);

                delay(150);

                setfillstyle(1,15);
                readimagefile("./mushroom.jpg",220,359,280,399);
                //bar(220,360,280,400);

                delay(10);

                setfillstyle(1,9);
                bar(200,300,300,400);

                i=i+150;

                setfillstyle(1,9);
                bar(140,100,280,200);
        }
        if(isJumping==0 && i/70>=16)
        {   //lives++;
            //if(lives==3)
            //{lives=0;
            //sc=1;}
            //readimagefile("./stand.jpg",140,300,260,400);
            dispMarioStand(160,310,280,400);
            obs(1300-i+60,360,1360-i+60,400);
            delay(2000);
            cleardevice();
            lives--;
            dispBg();
            break;
        }
        isJumping=0;
        //readimagefile("./stand.jpg",140,300,260,400);
        dispMarioStand(160,310,280,400);
        //jumper(140,300,280,400);
        obs(1300-i,360,1360-i,400);
        delay(60);

        //Hide obs
        setfillstyle(1,9);
        bar(1280-i,300,1380-i,400);
    }
    }
    readimagefile("./GO.jpg",0,0,1400,800);
    delay(2000);
    getch();
    closegraph();
}
