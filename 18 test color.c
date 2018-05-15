#include <ncurses.h>
#include <stdio.h>

#define size_x 70
#define size_y 20

int main()
{
	initscr();
	
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_CYAN);
	init_pair(2, COLOR_MAGENTA, COLOR_MAGENTA);
		
	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
			if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && i != 0)) 					{color_set(1, NULL); mvaddch(i, j, '='); }
			else if (i > 1) { color_set(2, NULL); printw(" ");}	
		} printw("\n");
	}

	mvaddch(19, 20, '9');

	getch();
	endwin();
	return 0;
}
