#ifndef __GLOBALS_H
#define __GLOBALS_H
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4
int ymax, xmax, y11 = 0, x1 = 0 , y2 = 0, x2 = 0, y3 = 0, x3 = 0, x4 = 0, x5 = 0, y4 = 0, y5 = 0;
int  height, width, height1, width1;
int startx6 = 0, starty6 = 0, startx7 = 0, starty7 = 0;
int i1 = 1, i2 = 1, i3 = 1, i4 = 1, i5 = 1, i6 = 1, i7 = 1;
int check1 = 0, check2 = 0, check3 = 0, check4 = 0, check5 = 0, check6 = 0, check7 = 0; 
int fd, istartx, istarty, istartx1, istarty1, istartx2, istarty2, istartx3, istarty3;
int l1, l2, l3, l4, l5, l6, l7;
int i, j, k, l, m;
int speed = 1;
int FPS = 2;
FILE *fp;
char ch, ch1, ch2, str1[80];
int startx1 = 0, starty1 = 0, startx2 = 0, starty2 = 0, startx3 = 0, starty3 = 0;
int startx4 = 0, starty4 = 0, startx5 = 0, starty5 = 0;
char string1[50], string2[50], string3[50], string4[50], string5[50], string6[50], string7[50];
WINDOW *my_win1, *input_win, *my_win2, *my_win3, *my_win4, *my_win5, *my_win6, *my_win7;
int countright = 0, countwrong = 0;

int movetext(char*, char*);
void timer1();
void setuptimer1();
#endif

