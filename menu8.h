
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
#ifndef __MENU8_H
#define __MENU8_H
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4
ITEM **my_items, **my_items1, **my_items2;
int c;				
MENU *my_menu, *my_menu1, *my_menu2;
WINDOW *my_menu_win, *my_menu_win1, *my_menu_win2;
int n_choices, i, n_choices1, n_choices2;
char choice[50];

				
int mainmenu();			                  
void submenu();
void wordmenu();

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);
void func(char *name);
void func1(char *name);
void func2(char *name);
#endif
