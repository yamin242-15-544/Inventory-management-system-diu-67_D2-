#include <conio.h> // getch()
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // For sleep()
#include <windows.h>


void gotoxy(int x, int y) {
  COORD c;
  c.X = x;
  c.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
       }

 void slines(int a){
     printf("%c",201);
       for (int i = 0; i < a; i++) {
    printf("%c", 205);
   }
 printf("%c",187);
 }


  void mlines(int a){
     printf("%c",204);
       for (int i = 0; i < a; i++) {
    printf("%c", 205);
 }
 printf("%c",185);
 }


  void elines(int a){
     printf("%c",200);
       for (int i = 0; i < a; i++) {
    printf("%c", 205);
 }
 printf("%c",188);
 }


 void dashes_vline(int c) {
     printf("%c",186);
    for (int b = 0; b <= c; b++) {
        printf("-");
    }
    printf("%c",186);
}


int main(){
  printf("\e[5;41mthis happens!!\e[0m\n");
  printf("i am ok\n");
  gotoxy(0,10);
  printf("%c\n", 185);
  printf("%c\n", 187);
  printf("%c\n\n", 201);
  printf("%c\n\n", 200);
  printf("%c\n\n", 204);
  printf("%c\n\n", 205);
  printf("%c\n\n", 188);


      char a[50]="icecream";
      char b[50]="groceries";
      char c[50]="09-04-2025 17:02:54";
      int i=200;
      float j=3000;
      gotoxy(7,3);
      slines(98);
      gotoxy(7,4);
      printf("%c                                        categories: %-45s%c",186,b,186);
      gotoxy(7,5);
      mlines(98);
      gotoxy(7,6);
      printf("%-40c\e[1;31mNo items in this category.\e[0m%34c",186,186);
      gotoxy(7,7);
      mlines(98);
      gotoxy(7,8);
      printf("%c Name: %-14s | Quantity: %-8d | Price: %-11.2f | Added on: %-22s%C",186,a,i,j,c,186);
      gotoxy(7,9);
      dashes_vline(97);
      gotoxy(7,10);
      printf("%c\e[5;41m Name: %-14s | Quantity: %-8d | Price: %-11.2f | Added on: %-22s\e[0m%C",186,a,i,j,c,186);
      gotoxy(7,11);
//dashes_vline(97);
// gotoxy(7,8);
      elines(98);

      int num=6;
     for(int i=0;i<10;i++){
                              num++;
                          }
  
      printf("%d",num);

    return 0;
}
