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
