#include <menu.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define CTRLD 	4
ITEM **my_items, **my_items1, **my_items2;
int c;				
MENU *my_menu, *my_menu1, *my_menu2;
WINDOW *my_menu_win, *my_menu_win1, *my_menu_win2;
int n_choices, i, n_choices1, n_choices2;
char diff[50] = "Easy";
char word_choice[50] = "";


char *choices[] = {
                        "new game",
                        "difficulty",
                        "words",
                        "Choice 4",
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
			"words1",
			"words2",
			"words3",
			"words4",
			"words5",
			"Back",
			(char *)NULL,
		};
					
void mainmenu();			                  
void submenu();
void wordmenu();

void print_in_middle(WINDOW *win, int starty, int startx, int width, char *string);
void func(char *name);
void func1(char *name);
void func2(char *name);
int main()
{		
	/* Initialize curses */
	initscr();
        cbreak();
        noecho();
	keypad(stdscr, TRUE);
	/* Create items */
        mainmenu(); 
	endwin();
}

void mainmenu() {
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
	print_in_middle(my_menu_win, 1, 0, 40, "My Menu");
	mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
	mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
	mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
	mvprintw(LINES - 2, 0, "F1 to exit");
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
	mvprintw(LINES - 2, 0, "F1 to exit");
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
	mvprintw(LINES - 2, 0, "F1 to exit");
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
	mvprintw(20, 0, "Item selected is : %s", name);
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

		
}
void func1(char *name)
{	move(20, 0);
	clrtoeol();
	mvprintw(20, 0, "Item selected is : %s", name);
	strcpy(diff, name);
	refresh();
	if(strcmp(name, "Back") == 0){
		werase(my_menu_win1);
		wrefresh(my_menu_win1);
		refresh();
		mainmenu();
	}
}		
void func2(char *name)
{	move(20, 0);
	clrtoeol();
	mvprintw(20, 0, "Item selected is : %s", name);
	strcpy(word_choice, name);
	refresh();
	if(strcmp(name, "Back") == 0){
		werase(my_menu_win2);
		wrefresh(my_menu_win2);
		refresh();
		mainmenu();
	}
}		
