#include <menu.h>
#include <stdlib.h>
#include <string.h>
#include "menu8.h"
char word_choice2[50] = "c c++ keywords";
char word_choice[50] = "ckey.txt";
char diff_choice[50] = "Easy";
int gameinitiate = 0;
int cxmax, cymax;
int score;


WINDOW *choice_win ;
	
int cstartx1, cstartx2, cstartx3;
int cstarty1, cstarty2, cstarty3;
int cheight, cwidth;
int cstartx, cstarty;
char *choices[] = {
                        "new game",
                        "difficulty",
                        "words",
                        "how to play",
                        "Exit",
                        (char *)NULL,
                  };
char *difficulty[] = {
			"Easy",
			"Medium",
			"Hard",
			"Back",
			(char *)NULL,
		};
char *words[] = {
			"c c++ keywords",
			"csharp keywords",
			"dos commands",
			"unix commands",
			"Back",
			(char *)NULL,
		};

int mainmenu() {
	getmaxyx(stdscr, cymax, cxmax);
	cheight = 4;
	cwidth = cxmax;
	cstartx = 0;
	cstarty = cymax - 5;
	choice_win = newwin(cheight + 1, cwidth, cstarty, cstartx);
	cstartx1 = 1;
	cstarty1 = 2;
	box(choice_win, 0, 0);
	wrefresh(choice_win);
	mvwprintw(choice_win, cstarty1, cstartx1, "WORDS : ");
	wrefresh(choice_win);
	cstartx1 = 9;
	cstartx2 = cxmax / 2;
	cstarty2 = 2;
	mvwprintw(choice_win, cstarty2, cstartx2, "DIFFICULTY : ");
	wrefresh(choice_win);	
	cstartx2 = (cxmax / 2) + 14;
	cstartx3 = cxmax - 11;
	cstarty3 = 2;
	//mvwprintw(choices_win, cstarty3, cstartx3, "MISSES : ");
	//wrefresh(choices_win);
	cstartx3 = cxmax - 2;
	wrefresh(choice_win);
	mvwprintw(choice_win, cstarty1, cstartx1, "%s", word_choice2);
	wrefresh(choice_win);
	mvwprintw(choice_win, cstarty2, cstartx2, "%s", diff_choice);
	wrefresh(choice_win);

        n_choices = ARRAY_SIZE(choices);
        my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
        for(i = 0; i < n_choices; ++i) {
                my_items[i] = new_item(choices[i], NULL);
                set_item_userptr(my_items[i], func);
	}

	/* Crate menu */
	my_menu = new_menu((ITEM **)my_items);

	/* Create the window to be associated with the menu */
        my_menu_win = newwin(10, 40, 4, 4);
        keypad(my_menu_win, TRUE);
     
	/* Set main window and sub window */
        set_menu_win(my_menu, my_menu_win);
        set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));

	/* Set menu mark to the string " * " */
        set_menu_mark(my_menu, " * ");

	/* Print a border around the main window and print a title */
        box(my_menu_win, 0, 0);
	print_in_middle(my_menu_win, 1, 0, 40, "TYPERACER");
	mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
	mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
	//mvprintw(LINES - 2, 0, "F1 to exit");
	refresh();
        
	/* Post the menu */
	post_menu(my_menu);
	wrefresh(my_menu_win);

	while((c = wgetch(my_menu_win)) != KEY_F(1))
	{       switch(c)
	        {	case KEY_DOWN:
				menu_driver(my_menu, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu, REQ_UP_ITEM);
				break;
			case 10: /* Enter */
			{	
				ITEM *cur;
				void (*p)(char *);
				cur = current_item(my_menu);
				p = item_userptr(cur);
				p((char *)item_name(cur));
				pos_menu_cursor(my_menu);
				break;
			}
			break;		
		}
                wrefresh(my_menu_win);
	}	

	/* Unpost and free all the memory taken up */
        unpost_menu(my_menu);
        free_menu(my_menu);
        for(i = 0; i < n_choices; ++i)
                free_item(my_items[i]);
        return gameinitiate;        
}
void submenu(){
	n_choices1 = ARRAY_SIZE(difficulty);
        my_items1 = (ITEM **)calloc(n_choices1, sizeof(ITEM *));
        for(i = 0; i < n_choices1; ++i) {
                my_items1[i] = new_item(difficulty[i], NULL);
                set_item_userptr(my_items1[i], func1);
	}

	/* Create menu */
	my_menu1 = new_menu((ITEM **)my_items1);

	/* Create the window to be associated with the menu */
        my_menu_win1 = newwin(10, 40, 4, 4);
        keypad(my_menu_win1, TRUE);
     
	/* Set main window and sub window */
        set_menu_win(my_menu1, my_menu_win1);
        set_menu_sub(my_menu1, derwin(my_menu_win1, 6, 38, 3, 1));

	/* Set menu mark to the string " * " */
        set_menu_mark(my_menu1, " * ");

	/* Print a border around the main window and print a title */
        box(my_menu_win1, 0, 0);
	print_in_middle(my_menu_win1, 1, 0, 40, "Difficulty");
	mvwaddch(my_menu_win1, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win1, 2, 1, ACS_HLINE, 38);
	mvwaddch(my_menu_win1, 2, 39, ACS_RTEE);
	refresh();
        
	/* Post the menu */
	post_menu(my_menu1);
	wrefresh(my_menu_win1);

	while((c = wgetch(my_menu_win1)) != KEY_F(1))
	{       switch(c)
	        {	case KEY_DOWN:
				menu_driver(my_menu1, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu1, REQ_UP_ITEM);
				break;
			case 10: /* Enter */
			{	
				ITEM *cur1;
				void (*p1)(char *);
				cur1 = current_item(my_menu1);
				p1 = item_userptr(cur1);
				p1((char *)item_name(cur1));
				pos_menu_cursor(my_menu1);
				break;
			}
			break;		
		}
                wrefresh(my_menu_win1);
	}	

	/* Unpost and free all the memory taken up */
        unpost_menu(my_menu1);
        free_menu(my_menu1);
        for(i = 0; i < n_choices1; ++i)
                free_item(my_items1[i]);
}
	

void wordmenu(){
	n_choices2 = ARRAY_SIZE(words);
        my_items2 = (ITEM **)calloc(n_choices2, sizeof(ITEM *));
        for(i = 0; i < n_choices2; ++i) {
                my_items2[i] = new_item(words[i], NULL);
                set_item_userptr(my_items2[i], func2);
	}
	/* Create menu */
	my_menu2 = new_menu((ITEM **)my_items2);

	/* Create the window to be associated with the menu */
        my_menu_win2 = newwin(10, 40, 4, 4);
        keypad(my_menu_win2, TRUE);
     
	/* Set main window and sub window */
        set_menu_win(my_menu2, my_menu_win2);
        set_menu_sub(my_menu2, derwin(my_menu_win2, 6, 38, 3, 1));

	/* Set menu mark to the string " * " */
        set_menu_mark(my_menu2, " * ");

	/* Print a border around the main window and print a title */
        box(my_menu_win2, 0, 0);
	print_in_middle(my_menu_win2, 1, 0, 40, "Difficulty");
	mvwaddch(my_menu_win2, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win2, 2, 1, ACS_HLINE, 38);
	mvwaddch(my_menu_win2, 2, 39, ACS_RTEE);
	refresh();
        
	/* Post the menu */
	post_menu(my_menu2);
	wrefresh(my_menu_win2);

	while((c = wgetch(my_menu_win2)) != KEY_F(1))
	{       switch(c)
	        {	case KEY_DOWN:
				menu_driver(my_menu2, REQ_DOWN_ITEM);
				break;
			case KEY_UP:
				menu_driver(my_menu2, REQ_UP_ITEM);
				break;
			case 10: /* Enter */
			{	
				ITEM *cur2;
				void (*p2)(char *);
				cur2 = current_item(my_menu2);
				p2 = item_userptr(cur2);
				p2((char *)item_name(cur2));
				pos_menu_cursor(my_menu2);
				break;
			}
			break;		
		}
                wrefresh(my_menu_win2);
	}	

	/* Unpost and free all the memory taken up */
        unpost_menu(my_menu2);
        free_menu(my_menu2);
        for(i = 0; i < n_choices2; ++i)
                free_item(my_items2[i]);
}
	
void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string)
{	int length, x, y;
	float temp;

	if(win == NULL)
		win = stdscr;
	getyx(win, y, x);
	if(startx != 0)
		x = startx;
	if(starty != 0)
		y = starty;
	if(width == 0)
		width = 80;

	length = strlen(string);
	temp = (width - length)/ 2;
	x = startx + (int)temp;
	mvwprintw(win, y, x, "%s", string);
	refresh();
}
void func(char *name)
{	move(20, 0);
	clrtoeol();
	//mvprintw(20, 0, "Item selected is : %s", name);
	refresh();
	if(strcmp(name, "difficulty") == 0){
		werase(my_menu_win);
		wrefresh(my_menu_win);
		refresh();
		submenu();
	}
	if(strcmp(name, "words") == 0){
		werase(my_menu_win);
		wrefresh(my_menu_win);
		refresh();
		wordmenu();
	}
	if(strcmp(name, "exit") == 0) {
		endwin();
		refresh();
	}	
	if(strcmp(name, "new game") == 0){
		werase(my_menu_win);
		wrefresh(my_menu_win);
		werase(choice_win);
		wrefresh(choice_win);
		delwin(my_menu_win);
		delwin(choice_win);
		refresh();
		movetext(word_choice, diff_choice);
	}	
	
		
}
void func1(char *name)
{	move(20, 0);
	clrtoeol();
	if(strcmp(name, "Back") == 0){
		werase(my_menu_win1);
		wrefresh(my_menu_win1);
		refresh();
		mainmenu();
	}
	else {
		//mvprintw(20, 0, "Item selected is : %s", name);
		//refresh();
		strcpy(diff_choice, name);
		mvwprintw(choice_win, cstarty2, cstartx2, "%s", name);
		wrefresh(choice_win);
	
	}
}		
void func2(char *name)
{	move(20, 0);
	clrtoeol();
	if(strcmp(name, "Back") == 0){
		werase(my_menu_win2);
		wrefresh(my_menu_win2);
		refresh();
		mainmenu();
	}
	else {
		if(strcmp(name, "c c++ keywords") == 0)
			strcpy(word_choice, "ckey.txt");
		if(strcmp(name, "csharp keywords") == 0)
			strcpy(word_choice, "csharp.txt");
		if(strcmp(name, "dos commands") == 0) 
			strcpy(word_choice, "dos.txt");
		if(strcmp(name, "unix commands") == 0)
			strcpy(word_choice, "unix.txt");			
		//mvprintw(20, 0, "Item selected is : %s", name);
		strcpy(word_choice2, name);
		mvwprintw(choice_win, cstarty1, cstartx1, "%s", name);
		wrefresh(choice_win);
		refresh();
	}	
}		
