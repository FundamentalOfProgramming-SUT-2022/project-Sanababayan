#include<stdlib.h>
#include<stdio.h>
#include<string.h>
//#include <ncurses.h> E:\Sana\reference\FOP\Project
#include <curses.h>
#include<windows.h>
#include<time.h>

WINDOW *create_newwin(int height, int width, int starty, int startx);
void destroy_win(WINDOW *local_win);

int main(int argc, char *argv[])
{	WINDOW *my_win;
    /*char * file_path;
    getstr(file_path);

    FILE *src;
    src = fopen (file_path, "r");

    if(src==NULL)
    {
        printw("Cant open the file\n");
    }else
    {
        printw("I opened it\n");
    }
    char s[500];
    fgets(s, sizeof(s), src);
    mvwprintw(my_win, 3, 5, s);
    wrefresh(my_win);
    fclose(src);
    Sleep(5);*/
    MEVENT event;
	int startx, starty, width, height;
	int ch;

	initscr();			/* Start curses mode 		*/
	cbreak();			/* Line buffering disabled, Pass on
					 * everty thing to me 		*/
	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/

	height = 35;
	width = 65;
	starty = (LINES - height) / 2;	/* Calculating for a center placement */
	startx = (COLS - width) / 2;	/* of the window		*/
	//printw("Press F1 to exit");
    refresh();

	start_color();			/* Start color 			*/
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	my_win = create_newwin(height, width, starty, startx);
	scrollok(my_win, TRUE);
    wbkgd(my_win, COLOR_PAIR(1));
	attroff(COLOR_PAIR(1));

	char mesg1[]="NORMAL";
	char mesg2[]=":command args";
	int row,col;
	initscr();				/* start the curses mode */
    getmaxyx(my_win,row,col);		/* get the number of rows and columns */
    mvprintw(row,(col-36),"%s",mesg1);
    mvprintw((row+1),(col-36),"%s",mesg2);
    for(int i=1;i<row-4;i++)
    {
        mvprintw(i+4,(col-36),"%d",i);
    }

    char kar=' ';
	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{	case KEY_LEFT:
		         mvwaddch(my_win, starty, --startx, kar);
		         //wrefresh(my_win);
				//destroy_win(my_win);
				//my_win = create_newwin(height, width, starty,--startx);
				break;
			case KEY_RIGHT:
			    mvwaddch(my_win, starty, ++startx, kar);
		         //wrefresh(my_win);
				//destroy_win(my_win);
				//my_win = create_newwin(height, width, starty,++startx);
				break;
			case KEY_UP:
			    mvwaddch(my_win, --starty, startx, kar);
		        // wrefresh(my_win);
				//destroy_win(my_win);
				//my_win = create_newwin(height, width, --starty,startx);
				break;
			case KEY_DOWN:
			    mvwaddch(my_win, ++starty, startx, kar);
		         //wrefresh(my_win);
				//destroy_win(my_win);
				//my_win = create_newwin(height, width, ++starty,startx);
				break;
		}
	}
	endwin();			/* End curses mode		  */
	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx)
{	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);		/* 0, 0 gives default characters
					 * for the vertical and horizontal
					 * lines			*/
	wrefresh(local_win);		/* Show that box 		*/

	return local_win;
}

void destroy_win(WINDOW *local_win)
{
	/* box(local_win, ' ', ' '); : This won't produce the desired
	 * result of erasing the window. It will leave it's four corners
	 * and so an ugly remnant of window.
	 */
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	/* The parameters taken are
	 * 1. win: the window on which to operate
	 * 2. ls: character to be used for the left side of the window
	 * 3. rs: character to be used for the right side of the window
	 * 4. ts: character to be used for the top side of the window
	 * 5. bs: character to be used for the bottom side of the window
	 * 6. tl: character to be used for the top left corner of the window
	 * 7. tr: character to be used for the top right corner of the window
	 * 8. bl: character to be used for the bottom left corner of the window
	 * 9. br: character to be used for the bottom right corner of the window
	 */
	wrefresh(local_win);
	delwin(local_win);
}
