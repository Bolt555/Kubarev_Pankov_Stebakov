#include <ncurses.h>
#include <stdio.h>

#define size_x 70
#define size_y 20

struct Snake
{
	int x[100];
	int y[100];
};

struct Snake snake;
int size_snake = 3, fruit_x, fruit_y, score = 0;
bool Game_Over = false, fruits = true;

	
void terminal()
{
	printw("Score: %d", score);
	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
		if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && i != 0)) { mvaddch(i, 				j, '='); }
		} printw("\n");
	}	
}

void move_arr_snake()
{
	for(int i = size_snake; i !=0; i--) {
		snake.y[i]=snake.y[i-1];
		snake.x[i]=snake.x[i-1];
	}
}


void mvaddch_snake()
{
	for(int i = 0;i < size_snake; i++) {
		if (i == 0) {
			mvaddch(snake.y[0], snake.x[0], '%');
		}
		else { 
			mvaddch(snake.y[i], snake.x[i], '*');
		}
	}
}

void fruit()
{
	
	do {
		fruits = true;		
		fruit_x = rand()%(size_x - 3) + 2;
		fruit_y = rand()%(size_y - 3) + 2;
		
		for (int i = 0; i < size_snake; i++) {
			if ((fruit_x == snake.x[i]) && (fruit_y == snake.y[i])) {
				fruits = false;
			}
		}
		
	} while (!fruit);
}

void eat()
{
	if ((snake.y[0] == fruit_y) && (snake.x[0] == fruit_x)) {
		score++;
		size_snake++;
	}
	fruit();
	mvaddch(fruit_y, fruit_x, '9');	
}

void snake_mov()
{
	switch (getch())
		{
			case KEY_UP:
				clear();
				move_arr_snake();
				snake.y[0]--;
				terminal();
				mvaddch_snake();
				eat();
				refresh();
			break;

			case KEY_DOWN:
				clear();
				move_arr_snake();
				snake.y[0]++;
				terminal();
				mvaddch_snake();
				eat();
				refresh();
				
			break;

			case KEY_RIGHT:
				clear();
				move_arr_snake();
				snake.x[0]++;
				terminal();
				mvaddch_snake();
				eat();
				refresh();
				
			break;
				
			case KEY_LEFT:
				clear();
				move_arr_snake();
				snake.x[0]--;
				terminal();
				mvaddch_snake();
				eat();
				refresh();
				
			break;			
		}
}


int main ()
{
	initscr();
	srand(time(0));
	curs_set(0);
	noecho();

	snake.x[0] = 35;
	snake.y[0] = 10;
	snake.x[1] = 35;
	snake.y[1] = 11;
	snake.x[2] = 35;
	snake.y[2] = 12;

	while(!Game_Over) {
		snake_mov();
	}
	
	printw("Game Over!");
	
	usleep(5000);
	refresh();
				
	getch();
	endwin();

	return 0;
}
