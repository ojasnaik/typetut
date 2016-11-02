/*
 *  typespeed - measures your typing speed
 *  Copyright (C) 2016   Ojas Naik <naikojas@gmail.com>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#ifndef __GLOBALS2_H
#define __GLOBALS2_H
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4
extern int ymax, xmax, y11, x1, y2, x2, y3, x3, x4, x5, y4, y5;
extern int  height, width, height1, width1;
extern int startx6, starty6, startx7, starty7;
extern int i1, i2, i3, i4, i5, i6, i7;
extern int check1, check2, check3, check4, check5, check6, check7; 
extern int fd, istartx, istarty, istartx1, istarty1, istartx2, istarty2, istartx3, istarty3;
extern int l1, l2, l3, l4, l5, l6, l7;
extern int i, j, k, l, m;
extern int speed;
extern int FPS;
extern char ch, ch1, ch2, str1[80];

extern int startx1, starty1, startx2, starty2, startx3, starty3;
extern int startx4, starty4, startx5, starty5;
extern char string1[50], string2[50], string3[50], string4[50], string5[50], string6[50], string7[50];
extern int countright, countwrong;
void scoredisplay(int);
int movetext(char*, char*);
void timer1();
void setuptimer1();
#endif

