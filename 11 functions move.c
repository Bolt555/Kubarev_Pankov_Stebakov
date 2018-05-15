#include <ncurses.h>
#include <stdio.h>

#define size_x 70
#define size_y 20
#define SIZE 100

struct Snake
{
	int x;
	int y;
};
enum eD {STOP = 0, LEFT, RIGHT, UP, DOWN};
enum eD dir;

struct Snake snake[SIZE];
bool Game_Over = false;
int head_x, head_y, snake_size = 3, fruit_x, fruit_y, score = 0;

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

void Start()
{
	dir = STOP;
	head_x = 35;
	head_y = 10;
	snake[0].x = 35;
	snake[0].y = 10;
	snake[1].x = 35;
	snake[1].y = 11;
	snake[2].x = 35;
	snake[2].y = 12;
	fruit_x = rand()%(size_x - 3) + 2; 
	fruit_y = rand()%(size_y - 2) + 2;
}

void pereresovka()
{
	for(int i = snake_size; i != 0; i--){
		snake[i].y = snake[i-1].y;
		snake[i].x = snake[i-1].x;
	}
}

void Fruit()
{
	mvaddch(fruit_y, fruit_x, '$');	
}

void Print_Snake()
{
	mvaddch(head_y, head_x, '@');
	for (int i = 1; i < snake_size; i++) {
		mvaddch(snake[i].y, snake[i].x, '*');
	}	
}

void Pole()
{
for (int i = 0; i < size_y; i++) {
	for (int j = 0; j < size_x; j++) {
	if ((i == 1 || i == 19) || ((j == 0 && i != 0)) || ((j == 69) && i != 0)) { mvaddch(i, j, '='); }
		} printw("\n");
	}
	printw("Score: %d", score);
}

void Print()
{
	clear();

	Print_Snake();
	Fruit();
//----------------------------------------------------------------------------------------------------
	Pole();
//----------------------------------------------------------------------------------------------------	
	//usleep(5000);
	refresh();
}

void Input()
{
	if (kbhit()) {
		switch (getch())
		{
			case 'a':
				dir = LEFT;
			break;

			case 'd':
				dir = RIGHT;
			break;

			case 'w':
				dir = UP;
			break;
				
			case 's':
				dir = DOWN;	
			break;
			case 'q':
				Game_Over = true;
				clear();refresh(); 
				printw("Goodbye!\tYour score is %d!", score);	
			break;			
		}
	}
}

void Logic()
{
	switch (dir)
		{
			case LEFT:
				if (snake[0].x - 1 != snake[1].x) {
				pereresovka();			
				head_x--;
				snake[0].x = head_x; 
				Print(); }
			break;
				
			case RIGHT:
				if (snake[0].x + 1 != snake[1].x) {
				pereresovka();
				head_x++;
				snake[0].x = head_x;
				Print(); }
			break;

			case UP:
				if (snake[0].y - 1 != snake[1].y) {
				pereresovka();	
				head_y--;
				snake[0].y = head_y; 
				Print(); }
			break;
				
			case DOWN:
				if (snake[0].y + 1 != snake[1].y) {
				pereresovka();
				head_y++;
				snake[0].y = head_y;
				Print(); }	
			break;		
		}

	if ((snake[0].x == 69) || (snake[0].y == 19) || (snake[0].y == 1) || (snake[0].x == 0)) {
		Game_Over = true;
		clear(); refresh();
		printw("Oh, no! You are lose! Your score is %d", score);	
	}
	if (snake[0].x == fruit_x && snake[0].y == fruit_y) {
		score++;
		snake_size++;
		fruit_x = rand()%(size_x - 3) + 2; 
		fruit_y = rand()%(size_y - 2) + 2;
		Fruit();
	}			
}

int main()
{
	initscr();
	curs_set(0);
	srand(time(0));
	noecho();
	keypad(stdscr, true);
	
	clear();

	Start();

	while (!Game_Over) {
		Print();
		Logic();
		Input();
	}

	refresh();
	
	getch();
	endwin();

	return 0;
}
