#include <ncurses.h>
#include <stdio.h>
#define size_x 70
#define size_y 20

struct Snake
{
	int x[100];
	int y[100];
};

int main()
{	
	initscr();
	srand(time(0));
	curs_set(0);
	noecho();
	int score = 0;
	printw("Score: %d", score);	
		
	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
		if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && i != 0)) { mvaddch(i, 				j, '='); }
		} printw("\n");
	}	
	
	int size_snake = 3, fruit_x = rand()%(size_x - 3) + 2, fruit_y = rand()%(size_y - 2) + 2;
	struct Snake snake;
	bool Game_Over = true, fruit = false;
	snake.x[0] = 35;
	snake.y[0] = 10;
	snake.x[1] = 35;
	snake.y[1] = 11;
	snake.x[2] = 35;
	snake.y[2] = 12;	
	keypad(stdscr, true);	

	for (int i = 0; i < size_snake; i++) {
		if (i == 0) {
		mvaddch(snake.y[0], snake.x[0], '%');
		}
		else { 
		mvaddch(snake.y[i], snake.x[i], '*');
		} 
	}

	mvaddch(fruit_y, fruit_x, '9');

	while (Game_Over)
	{		
		switch (getch())
		{
			case KEY_UP:
				clear();
				if (snake.y[0] - 1 != snake.y[1]) {				
					if (snake.y[0] == 2) { Game_Over = false; break;}
					for(int i = size_snake; i !=0; i--){
						snake.y[i]=snake.y[i-1];
						snake.x[i]=snake.x[i-1];
					}
					snake.y[0]--; }
				printw("Score: %d", score);
				for (int i = 0; i < size_y; i++) {
					for (int j = 0; j < size_x; j++) {
					if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && 						i != 0)) { mvaddch(i, j, '='); }
					} printw("\n");
				}
				if ((snake.y[0] == fruit_y) && (snake.x[0] == fruit_x)) {
					fruit_x = rand()%(size_x - 3) + 2;
					fruit_y = rand()%(size_y - 3) + 2;
					score++;
					size_snake++;
				}
				mvaddch(fruit_y, fruit_x, '9');	
				for(int i = 0;i < size_snake; i++) {
					if (i == 0) {
						mvaddch(snake.y[0], snake.x[0], '%');
					}
					else { 
						mvaddch(snake.y[i], snake.x[i], '*');
					}
				}
				refresh();
			break;

			case KEY_DOWN:
				clear();
				if (snake.y[0] + 1 != snake.y[1]) {				
					if (snake.y[0] == 18) { Game_Over = false; break;}
					for(int i = size_snake; i !=0; i--){
						snake.y[i]=snake.y[i-1];
						snake.x[i]=snake.x[i-1];
					}
					snake.y[0]++; }
				printw("Score: %d", score);
				for (int i = 0; i < size_y; i++) {
					for (int j = 0; j < size_x; j++) {
					if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && 						i != 0)) { mvaddch(i, j, '='); }
					} printw("\n");
				}
				if ((snake.y[0] == fruit_y) && (snake.x[0] == fruit_x)) {
					fruit_x = rand()%(size_x - 3) + 2;
					fruit_y = rand()%(size_y - 3) + 2;
					score++;
					size_snake;
				}
				mvaddch(fruit_y, fruit_x, '9');	
				for(int i = 0;i < size_snake; i++) {
					if (i == 0) {
						mvaddch(snake.y[0], snake.x[0], '%');
					}
					else { 
						mvaddch(snake.y[i], snake.x[i], '*');
					} 
				}
				refresh();
				
			break;

			case KEY_RIGHT:
				clear();
				if (snake.x[0] + 1 != snake.x[1]) {
					if (snake.x[0] == 68) { Game_Over = false; break;}
					for(int i = size_snake; i !=0; i--) {
						snake.y[i]=snake.y[i-1];
						snake.x[i]=snake.x[i-1];
					}
					snake.x[0]++; }
				printw("Score: %d", score);
				for (int i = 0; i < size_y; i++) {
					for (int j = 0; j < size_x; j++) {
					if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && 						i != 0)) { mvaddch(i, j, '='); }
					} printw("\n");
				}
				if ((snake.y[0] == fruit_y) && (snake.x[0] == fruit_x)) {
					fruit_x = rand()%(size_x - 3) + 2;
					fruit_y = rand()%(size_y - 3) + 2;
					score++;
					size_snake++;
				}
				mvaddch(fruit_y, fruit_x, '9');	
				for(int i = 0;i < size_snake; i++) {
					if (i == 0) {
						mvaddch(snake.y[0], snake.x[0], '%');
					}
					else { 
						mvaddch(snake.y[i], snake.x[i], '*');
					} 
				}
				refresh();
				
			break;
				
			case KEY_LEFT:
				clear();
				if (snake.x[0] - 1 != snake.x[1]) {
					if (snake.x[0] == 1) { Game_Over = false; break;}
					for(int i = size_snake; i !=0; i--){
						snake.y[i]=snake.y[i-1];
						snake.x[i]=snake.x[i-1];
					}
					snake.x[0]--; }
				printw("Score: %d", score);
				for (int i = 0; i < size_y; i++) {
					for (int j = 0; j < size_x; j++) {
					if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && 						i != 0)) { mvaddch(i, j, '='); }
					} printw("\n");
				}
				if ((snake.y[0] == fruit_y) && (snake.x[0] == fruit_x)) {
					fruit_x = rand()%(size_x - 3) + 2;
					fruit_y = rand()%(size_y - 3) + 2;
					score++;
					size_snake++;
				}
				mvaddch(fruit_y, fruit_x, '9');	
				for(int i = 0;i < size_snake; i++) {
					if (i == 0) {
						mvaddch(snake.y[0], snake.x[0], '%');
					}
					else { 
						mvaddch(snake.y[i], snake.x[i], '*');
					} 
				}
				refresh();
				
			break;			
		}
		
	}
	printw("Game Over!");
	
	usleep(5000);
	refresh();
				
	getch();
	endwin();	
	
return 0;
}
