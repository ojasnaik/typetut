#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <ncurses.h>
#include <signal.h>
#include <sys/time.h>
#include <string.h>
#define FPS 2
int ymax, xmax, height, width, y11 = 0, x1 = 0 , y2 = 0, x2 = 0, y3 = 0, x3 = 0, x4 = 0, x5 = 0, y4 = 0, y5 = 0;
int i1 = 1, i2 = 1, i3 = 1, i4 = 1, i5 = 1;
int check1 = 0, check2 = 0, check3 = 0, check4 = 0, check5 = 0; 
int fd, istartx, istarty;
int l1, l2, l3, l4, l5;
int i, j, k, l, m;
FILE *fp;
char ch, ch1, ch2, str1[80];
int startx1 = 0, starty1 = 0, startx2 = 0, starty2 = 0, startx3 = 0, starty3 = 0;
int startx4 = 0, starty4 = 0, startx5 = 0, starty5 = 0;
char string1[50], string2[50], string3[50], string4[50], string5[50];
WINDOW *my_win1, *input_win, *my_win2, *my_win3, *my_win4, *my_win5 ;
int countright = 0, countwrong = 0;
int movetext();
void timer1();
void setuptimer1();

int main(int argc, char*argv[]) {
	
	fp = fopen(argv[1], "r");
	initscr();			
	//noecho();
	//cbreak();
	keypad(stdscr, TRUE);		
	getmaxyx(stdscr, ymax, xmax);
	height = 4, width = xmax;
	starty1 = (ymax - height)/2 ;
	starty2 = (ymax - height)/4 ;
	starty3 = ((ymax - height)*3)/4;
	starty4 = (ymax - height)/8;
	starty5 = (ymax - height)*0.85;
	istartx = 0;
	istarty = ymax - 5;
	refresh();
	input_win = newwin(height, width, istarty, istartx);
	box(input_win, 0, 0);
	wrefresh(input_win);
	fscanf(fp, "%s%s%s%s%s", string1, string2, string3, string4, string5);
	l1 = strlen(string1);
	l2 = strlen(string2);
	l3 = strlen(string3);
	l4 = strlen(string4);
	l5 = strlen(string5);
	
	//while(fscanf(fp, "%s%s%s", string1, string2, string3) != EOF){ 
		movetext();
	
	
	getch();
	endwin();
	return 0;
}
int movetext(){
	check1 = 0;
	check2 = 0;
	check3 = 0;
	my_win1 = newwin(height, width, starty1, startx1);
	my_win2 = newwin(height, width, starty2, startx2);
	my_win3 = newwin(height, width, starty3, startx3);
	my_win4 = newwin(height, width, starty4, startx4);
	my_win5 = newwin(height, width, starty5, startx5);
	/*box(my_win1, 0, 0);
	wrefresh(my_win1);
	box(my_win2, 0, 0);
	wrefresh(my_win2);
	box(my_win3, 0, 0);
	wrefresh(my_win3);
	*/
	starty1 = 0;
	starty2 = 0;
	starty3 = 0;
	starty4 = 0;
	starty5 = 0;
	setuptimer1();
	while(1){
		//if(i1 = 0 || i2 == 0 || i3 == 0)
		mvwscanw(input_win, 0, 0, "%s", str1);
		i1 = strcmp(string1, str1);
		i2 = strcmp(string2, str1);
		i3 = strcmp(string3, str1);
		if(countright >= 10){
			i4 = strcmp(string4, str1);
		}
		if(countright >= 15){
			i5 = strcmp(string5, str1);
		}
			 
		//printw("%d", startx1);
		refresh();
		if(i1 == 0 || startx1 >= (xmax-l1) ) {
			check1 = 1;
			if(i1 == 0){
				countright++;
				printw("%d", countright);
				refresh();
				 
			}	
			if(startx1 >= (xmax-l1)){
			 	countwrong++;
				printw("%d", countwrong);
				refresh();
				 
			 }	
			
			for(i = 0; i < l1; i++){
				mvwprintw(my_win1, starty1, startx1, " ");
				wrefresh(my_win1);
				startx1++;
			}	
			//delwin(my_win1);
			startx1 = 0;
			starty1 = 0;
			i1 = 1;
			check1 = 0;
			fscanf(fp, "%s", string1);
			l1 = strlen(string1);
			//break;
		}
		if(i2 == 0 || startx2 >= (xmax-l2)) {
			check2 = 1;
			if(i2 == 0){
				countright++;
				printw("%d", countright);
				refresh();
				 
			 }	

			if(startx2 >= (xmax-l2)){
			 	countwrong++;
				printw("%d", countwrong);
				refresh();
				 
			 }
			
			for(j = 0; j < l2; j++){
				mvwprintw(my_win2, starty2, startx2, " ");
				wrefresh(my_win2);
				startx2++;
			}
			//delwin(my_win2);
			startx2 = 0;
			starty2 = 0;
			check2 = 0;
			i2 = 1;
			fscanf(fp, "%s", string2);
			
			l2 = strlen(string2);//break;
		}
		if(i3 == 0 || startx3 >= (xmax-l3)) {
			check3 = 1;
			if(i3 == 0){
				countright++;
				printw("%d", countright);
				refresh();
				 
			 }	

			if(startx3 >= (xmax-l3)){
			 	countwrong++;
				printw("%d", countwrong);
				refresh();
				 
			 }
			
			for(k = 0; k < l3; k++){
				mvwprintw(my_win3, starty3, startx3, " ");
				wrefresh(my_win3);
				startx3++;
			}
			//delwin(my_win3);
			startx3 = 0;
			starty3 = 0;
			check3 = 0;
			i3 = 1;
			fscanf(fp, "%s", string3);
			l3 = strlen(string3);
			//break;
		}
		if((countright >= 10) && (i4 == 0 || startx4 >= (xmax-l4))) {
			check3 = 1;
			if(i4 == 0){
				countright++;
				//printw("%d", countright);
				refresh();
				 
			 }	

			if(startx4 >= (xmax-l4)){
			 	countwrong++;
				printw("%d", countwrong);
				refresh();
				 
			 }
			
			for(l = 0; l < l4; l++){
				mvwprintw(my_win4, starty4, startx4, " ");
				wrefresh(my_win4);
				startx4++;
			}
			//delwin(my_win3);
			startx4 = 0;
			starty4 = 0;
			check4 = 0;
			i4 = 1;
			fscanf(fp, "%s", string4);
			l4 = strlen(string4);
			//break;
		}

		if((countright >= 15) && (i5 == 0 || startx5 >= (xmax-l5))) {
			check5 = 1;
			if(i5 == 0){
				countright++;
				//printw("%d", countright);
				refresh();
				 
			 }	

			if(startx5 >= (xmax-l5)){
			 	countwrong++;
				printw("%d", countwrong);
				refresh();
				 
			 }
			
			for(m = 0; m < l5; m++){
				mvwprintw(my_win5, starty5, startx5, " ");
				wrefresh(my_win5);
				startx5++;
			}
			//delwin(my_win3);
			startx5 = 0;
			starty5 = 0;
			check5 = 0;
			i5 = 1;
			fscanf(fp, "%s", string5);
			l5 = strlen(string5);
			//break;
		}


	//mvwprintw(input_win, 0, 0, "    ");
	}
		
	return 0;
}
void setuptimer1() {
	struct itimerval mytimer;
	struct sigaction myaction;
	mytimer.it_value.tv_sec = 1/FPS;
	mytimer.it_value.tv_usec = 1000000 / FPS;
	mytimer.it_interval.tv_sec = 1/FPS;
	mytimer.it_interval.tv_usec = 1000000 / FPS;
	setitimer(ITIMER_REAL, &mytimer, NULL);
	myaction.sa_handler = &timer1;
	myaction.sa_flags = SA_RESTART;
	sigaction(SIGALRM, &myaction, NULL);
}	
	
void timer1() {
	if(check1 != 1) { 
		for(i = 0; i < l1; i++){
			mvwprintw(my_win1, starty1, startx1, " ");
			wrefresh(my_win1);
			startx1++;
		}	
		mvwprintw(my_win1, starty1, startx1, string1);
		wrefresh(my_win1);
		getparyx(my_win1, y11, x1);
		refresh();
	}
	if(check2 != 1) { 
		for(j = 0; j < l2; j++){
			mvwprintw(my_win2, starty2, startx2, " ");
			wrefresh(my_win2);
			startx2++;
		}
		mvwprintw(my_win2, starty2, startx2, string2);
		wrefresh(my_win2);
		getparyx(my_win2, y2, x2);
		refresh();
	}
	if(check3 != 1) { 
		for(k = 0; k < l3; k++){
			mvwprintw(my_win3, starty3, startx3, " ");
			wrefresh(my_win3);
			startx3++;
		}
		mvwprintw(my_win3, starty3, startx3, string3);
		wrefresh(my_win3);
		getyx(my_win3, y3, x3);
		refresh();
	}
	if(check4 != 1 && countright >= 10) { 
		for(l = 0; l < l4; l++){
			mvwprintw(my_win4, starty4, startx4, " ");
			wrefresh(my_win4);
			startx4++;
		}
		mvwprintw(my_win4, starty4, startx4, string4);
		wrefresh(my_win4);
		getyx(my_win4, y4, x4);
		refresh();
	}
	if(check5 != 1 && countright >= 15) { 
		for(m = 0; m < l5; m++){
			mvwprintw(my_win5, starty5, startx5, " ");
			wrefresh(my_win5);
			startx5++;
		}
		mvwprintw(my_win5, starty5, startx5, string5);
		wrefresh(my_win5);
		getyx(my_win5, y5, x5);
		refresh();
	}
			
}

		
	
	 	
