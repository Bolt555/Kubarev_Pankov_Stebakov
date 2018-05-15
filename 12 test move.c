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
bool Game_Over = true, fruit = false, fr_on_sn = false;
int score = 0;
int size_snake = 3, fruit_x, fruit_y;

int kbhit();
void Setup();
void Pole();
void Print_Snake();
void Pereresovka();
bool Prov_Fruit();
void Eat_Fruit();

int main()
{	
	initscr();
	srand(time(0));
	curs_set(0);
	noecho();		
	keypad(stdscr, true);	
	Setup();
	Pole();
	Print_Snake();
	mvaddch(fruit_y, fruit_x, '9');

	while (Game_Over)
	{		
		switch (getch())
		{
			case KEY_UP:
				clear();
				if (snake.y[0] - 1 != snake.y[1]) {				
					if (snake.y[0] == 2) { Game_Over = false; break;}
					for (int i = 1; i < size_snake; i++) {
						if (snake.x[0]==snake.x[i]&&snake.y[0]-1==snake.y[i]) {
							Game_Over = false; break;
						}
					}
					Pereresovka();
					snake.y[0]--; }
				Pole();
				Eat_Fruit();
				mvaddch(fruit_y, fruit_x, '9');		
				Print_Snake();
				refresh();
			break;

			case KEY_DOWN:
				clear();
				if (snake.y[0] + 1 != snake.y[1]) {				
					if (snake.y[0] == 18) { Game_Over = false; break;}
					for (int i = 1; i < size_snake; i++) {
						if (snake.x[0]==snake.x[i]&&snake.y[0]+1==snake.y[i]) {
							Game_Over = false; break;
						}
					}
					Pereresovka();
					snake.y[0]++; }
				Pole();
				Eat_Fruit();
				mvaddch(fruit_y, fruit_x, '9');
				Print_Snake();
				refresh();
				
			break;

			case KEY_RIGHT:
				clear();
				if (snake.x[0] + 1 != snake.x[1]) {
					if (snake.x[0] == 68) { Game_Over = false; break;}
					for (int i = 1; i < size_snake; i++) {
						if (snake.x[0]+1==snake.x[i]&&snake.y[0]==snake.y[i]) {
							Game_Over = false; break;
						}
					}
					Pereresovka();
					snake.x[0]++; }
				Pole();
				Eat_Fruit();
				mvaddch(fruit_y, fruit_x, '9');
				Print_Snake();
				refresh();
				
			break;
				
			case KEY_LEFT:
				clear();
				if (snake.x[0] - 1 != snake.x[1]) {
					if (snake.x[0] == 1) { Game_Over = false; break;}
					for (int i = 1; i < size_snake; i++) {
						if (snake.x[0]-1==snake.x[i]&&snake.y[0]==snake.y[i]) {
							Game_Over = false; break;
						}
					}
					Pereresovka();
					snake.x[0]--; }
				Pole();
				Eat_Fruit();
				mvaddch(fruit_y, fruit_x, '9');	
				Print_Snake();
				refresh();
				
			break;			
		}
		
	}
	clear();
	printw("Game Over!");
	
	usleep(5000);
	refresh();
				
	getch();
	endwin();	
	
return 0;
}

void Setup()
{
	fruit_x = rand()%(size_x - 3) + 2; fruit_y = rand()%(size_y - 2) + 2;
	snake.x[0] = 35;
	snake.y[0] = 10;
	snake.x[1] = 35;
	snake.y[1] = 11;
	snake.x[2] = 35;
	snake.y[2] = 12;
}

void Pole() 
{
	printw("Score: %d", score);	
	for (int i = 0; i < size_y; i++) {
		for (int j = 0; j < size_x; j++) {
		if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && i != 0)) { mvaddch(i, 				j, '='); }
		} printw("\n");
	}
}

void Print_Snake()
{
	for (int i = 0; i < size_snake; i++) {
		if (i == 0) {
		mvaddch(snake.y[0], snake.x[0], '%');
		}
		else { 
		mvaddch(snake.y[i], snake.x[i], '*');
		} 
	}
}

void Pereresovka()
{
	for(int i = size_snake; i !=0; i--) {
		snake.y[i]=snake.y[i-1];
		snake.x[i]=snake.x[i-1];
	}	
}

bool Prov_Fruit()
{
	fruit_x = rand()%(size_x - 3) + 2;
	fruit_y = rand()%(size_y - 3) + 2; 			
	for (int i = 0; i < size_snake; i++) {
		if ((snake.x[i] == fruit_x) &&(snake.y[i] == fruit_y)) {
			return  false;
			break;
		}
	}
	return true;
}
void Eat_Fruit()
{
	if ((snake.y[0] == fruit_y) && (snake.x[0] == fruit_x)) {
		while (!fr_on_sn) {
			fr_on_sn = Prov_Fruit();
		}
		fr_on_sn = false; 	
		score++;
		size_snake++;
	}
}

int kbhit()
{
	int ch = getch();

	if (ch != ERR) {
		ungetch(ch);
		return 1;
	}
	else {
		return 0;
	} 
}
