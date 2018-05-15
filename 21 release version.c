#include <ncurses.h>
#include <stdio.h>

int size_x = 70;
int size_y = 20;

struct Snake
{
	int x[100];
	int y[100];
};

struct Snake snake;
bool Game_Over = false, fruit = false, fr_on_sn = false;
int score = 0;
int size_snake = 3, fruit_x, fruit_y;
enum eD {STOP = 0, LEFT, RIGHT, UP, DOWN};
enum eD dir; 
char ctrl[5];
const char items[4][10] = {
	"Play",
	"Settings",
	"Shop",
	"Exit"
};
const char color[9][10] = {
	"Standart",	
	"Red",
	"Yellow",
	"Blue",
	"Magenta",
	"Cyan",
	"Green",
	"White",
	"Back"
};
const char list_set[4][10] = {
	"Size",
	"Control",
	"Speed",
	"Back"
};

const char set_size[4][10] = {
	"70x20",
	"20x40",
	"40x40",
	"Back"
};

const char contrl[3][25] = {
	"up, left, down, right",
	"w, a, s, d",
	"Back"
};

const char set_speed[4][10] = {
	"Slow",
	"Normal",
	"Fast",
	"Back"
};

unsigned choice = 0, set = 0, Set_Size = 0, set_contrl = 0, lang = 0, choice_control = 1;
unsigned lang_choice = 1, color_choice = 0, color_set_ = 0, speed_choice = 0, setup_control = 0;
bool f = true;

struct color_choice_1
{
	bool buy;
	int cost;
};
 
struct color_choice_1 mas[8];
void Menu();
void Settings();
void Size();
void Control();
void Shop();
void Speed();
void Setup();
void Pole();
void Print_Snake();
void Pereresovka();
bool Prov_Fruit();
void Eat_Fruit();
int kbhit();
void Logic();
void Input_1();
void Input_2();
void Snake();

int main()
{	
	initscr();
	srand(time(0));
	curs_set(0);
	noecho();		
	keypad(stdscr, true);
	for (int i = 0; i < 8; i++) { mas[i].buy = false; mas[i].cost = i*2 + 1; }

	Menu();				

	endwin();	
	
return 0;
}

void Setup()
{
	switch (setup_control)
	{
		case 0:
			fruit_x = rand()%(size_x - 3) + 2; 
			fruit_y = rand()%(size_y - 2) + 2;
			snake.x[0] = 35;
			snake.y[0] = 10;
			snake.x[1] = 35;
			snake.y[1] = 11;
			snake.x[2] = 35;
			snake.y[2] = 12;
		break;
		case 1:
			snake.x[0] = 10;
			snake.y[0] = 10;
			snake.x[1] = 10;
			snake.y[1] = 11;
			snake.x[2] = 10;
			snake.y[2] = 12; 
			fruit_x = rand()%(size_x - 3) + 2; 
			fruit_y = rand()%(size_y - 2) + 2;
		break;
		case 2:
			snake.x[0] = 20;
			snake.y[0] = 10;
			snake.x[1] = 20;
			snake.y[1] = 11;
			snake.x[2] = 20;
			snake.y[2] = 12;
			fruit_x = rand()%(size_x - 3) + 2; 
			fruit_y = rand()%(size_y - 2) + 2;
		break;
	}
}

void Pole() 
{
	printw("Score: %d$", score);	
	for (int i = 0; i <= size_y; i++) {
		for (int j = 0; j <= size_x; j++) {
		if ((i == 1 || i == size_y) || ((j == 0 && i != 0)) || ((j == size_x) && (i != 0))) { mvaddch(i, j, '='); }
		} printw("\n");
	}
}

void Print_Snake()
{
	switch (color_choice)
	{
		case 1:
			start_color();
			init_pair(1, COLOR_RED, COLOR_BLACK);
			for (int i = 0; i < size_snake; i++) {
				if (i == 0) {
					mvaddch(snake.y[0], snake.x[0], '%' | COLOR_PAIR(1));
				}
				else { 
					mvaddch(snake.y[i], snake.x[i], '*' | COLOR_PAIR(1));
				} 
			}
		break;
		case 2:
			start_color();
			init_pair(1, COLOR_YELLOW, COLOR_BLACK);
			for (int i = 0; i < size_snake; i++) {
				if (i == 0) {
					mvaddch(snake.y[0], snake.x[0], '%' | COLOR_PAIR(1));
				}
				else { 
					mvaddch(snake.y[i], snake.x[i], '*' | COLOR_PAIR(1));
				}
			}
		break;
		case 3:
			start_color();
			init_pair(1, COLOR_BLUE, COLOR_BLACK);
			for (int i = 0; i < size_snake; i++) {
				if (i == 0) {
					mvaddch(snake.y[0], snake.x[0], '%' | COLOR_PAIR(1));
				}
				else { 
					mvaddch(snake.y[i], snake.x[i], '*' | COLOR_PAIR(1));
				}
			}
		break;
		case 4:
			start_color();
			init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
			for (int i = 0; i < size_snake; i++) {
				if (i == 0) {
					mvaddch(snake.y[0], snake.x[0], '%' | COLOR_PAIR(1));
				}
				else { 
					mvaddch(snake.y[i], snake.x[i], '*' | COLOR_PAIR(1));
				}
			}
		break;
		case 5:
			start_color();
			init_pair(1, COLOR_CYAN, COLOR_BLACK);
			for (int i = 0; i < size_snake; i++) {
				if (i == 0) {
					mvaddch(snake.y[0], snake.x[0], '%' | COLOR_PAIR(1));
				}
				else { 
					mvaddch(snake.y[i], snake.x[i], '*' | COLOR_PAIR(1));
				}
			}
		break;
		case 6:
			start_color();
			init_pair(1, COLOR_GREEN, COLOR_BLACK);
			for (int i = 0; i < size_snake; i++) {
				if (i == 0) {
					mvaddch(snake.y[0], snake.x[0], '%' | COLOR_PAIR(1));
				}
				else { 
					mvaddch(snake.y[i], snake.x[i], '*' | COLOR_PAIR(1));
				}
			}
		break;
		case 7:
			start_color();
			init_pair(1, COLOR_CYAN, COLOR_RED);
			for (int i = 0; i < size_snake; i++) {
				if (i == 0) {
					mvaddch(snake.y[0], snake.x[0], '%' | COLOR_PAIR(1));
				}
				else { 
					mvaddch(snake.y[i], snake.x[i], '*' | COLOR_PAIR(1));
				}
			}
		break;
		default: 
			for (int i = 0; i < size_snake; i++) {
				if (i == 0) {
					mvaddch(snake.y[0], snake.x[0], '%');
				}
				else { 
					mvaddch(snake.y[i], snake.x[i], '*');
				}
			}
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

void Input_1()
{
		if (speed_choice == 1) { halfdelay(5); }
		if (speed_choice == 0) { halfdelay(3); }
		if (speed_choice == 2) { halfdelay(1); }
		switch (getch())
		{
			case KEY_UP:
				dir = UP;
			break;

			case KEY_DOWN:
				dir = DOWN;
			break;

			case KEY_LEFT:
				dir = LEFT;
			break;
				
			case KEY_RIGHT:
				dir = RIGHT;	
			break;
			case 'q':
				Game_Over = true;
				f=true;
			break;			
		}
}

void Input_2()
{
		if (speed_choice == 1) { halfdelay(5); }
		if (speed_choice == 0) { halfdelay(3); }
		if (speed_choice == 2) { halfdelay(1); }
		switch (getch())
		{
			case 'w':
				dir = UP;
			break;

			case 's':
				dir = DOWN;
			break;

			case 'a':
				dir = LEFT;
			break;
				
			case 'd':
				dir = RIGHT;	
			break;
			case 'q':
				Game_Over = true;
				f=true; //Menu();//
			return;
			break;			
		}
}

void Logic()
{
	switch (dir)
		{
			case UP:
				clear();
				if (snake.y[0] - 1 != snake.y[1]) {				
					if (snake.y[0] == 2) { Game_Over = true; break;}
					for (int i = 1; i < size_snake; i++) {
						if (snake.x[0]==snake.x[i]&&snake.y[0]-1==snake.y[i]) {
							Game_Over = true; break;
						}
					}
					Pereresovka();
					snake.y[0]--; }
				Pole();
				Eat_Fruit();
				mvaddch(fruit_y, fruit_x, '$');		
				Print_Snake();
				refresh();
			break;

			case DOWN:
				clear();
				if (snake.y[0] + 1 != snake.y[1]) {				
					if (snake.y[0] == size_y-1) { Game_Over = true; break;}
					for (int i = 1; i < size_snake; i++) {
						if (snake.x[0]==snake.x[i]&&snake.y[0]+1==snake.y[i]) {
							Game_Over = true; break;
						}
					}
					Pereresovka();
					snake.y[0]++; } else {Pereresovka(); snake.y[0]++;}
				Pole();
				Eat_Fruit();
				mvaddch(fruit_y, fruit_x, '$');
				Print_Snake();
				refresh();
				
			break;

			case RIGHT:
				clear();
				if (snake.x[0] + 1 != snake.x[1]) {
					if (snake.x[0] == size_x-1) { Game_Over = true; break;}
					for (int i = 1; i < size_snake; i++) {
						if (snake.x[0]+1==snake.x[i]&&snake.y[0]==snake.y[i]) {
							Game_Over = true; break;
						}
					}
					Pereresovka();
					snake.x[0]++; }
				Pole();
				Eat_Fruit();
				mvaddch(fruit_y, fruit_x, '$');
				Print_Snake();
				refresh();
				
			break;
				
			case LEFT:
				clear();
				if (snake.x[0] - 1 != snake.x[1]) {
					if (snake.x[0] == 1) { Game_Over = true; break;}
					for (int i = 1; i < size_snake; i++) {
						if (snake.x[0]-1==snake.x[i]&&snake.y[0]==snake.y[i]) {
							Game_Over = true; break;
						}
					}
					Pereresovka();
					snake.x[0]--; }
				Pole();
				Eat_Fruit();
				mvaddch(fruit_y, fruit_x, '$');	
				Print_Snake();
				refresh();
				
			break;			
		}
}

void Snake()
{
	size_snake = 3;
	Setup();
	Pole();
	Print_Snake();
	mvaddch(fruit_y, fruit_x, '$');
	while (!Game_Over)
	{		
		if (choice_control == 1) { Input_1(); }
		if (choice_control == 2) { Input_2(); }
		Logic();
	}
	Game_Over = false;
	clear();
	halfdelay(100);
	printw("Game Over! Your score is %d$\nPress to Enter...", score);
	getch();
	f = true;
	return;
	refresh();
}

void Menu()
{
	while (f) {
		clear();
		for (unsigned i = 0; i < 4; i++) {
			if (i == choice)
				addch('>');
			else 
				addch(' ');
			printw("%s\n", items[i]);
		}
		
		switch (getch())
		{
			case KEY_UP:
				if (choice)
					choice--;
			break;
			case KEY_DOWN:
				if (choice != 3)
					choice++;
			break;
			case 10:
				if (choice == 0) {f = false; clear(); Snake(); }
				if (choice == 1) {f = false; Settings(); }
				if (choice == 2) {f = false; Shop();  }				
				if (choice == 3) {f = false; return; /*break;*/ /*return;*/}
			break;
		}
	}
}

void Settings()
{
	//bool f = true;
	while (!f) {
		clear();
		for (unsigned i = 0; i < 4; i++) {
			if (i == set)
				addch('>');
			else 
				addch(' ');
			printw("%s\n", list_set[i]);
		}
		
		switch (getch())
		{
			case KEY_UP:
				if (set)
					set--;
			break;
			case KEY_DOWN:
				if (set != 3)
					set++;
			break;
			case KEY_BACKSPACE:
				//Menu();
				f=true;
				return;
			break;
			case 10:
				if (set == 0) {f = true; Size() ;}
				if (set == 1) {f = true; Control(); }
				if (set == 2) {f = true; Speed(); }
				if (set == 3) {f= true;return; Menu(); }
			break;
		}
	}	
}

void Size()
{
	//bool f = true;
	while (f) {
		clear();
		for (unsigned i = 0; i < 4; i++) {
			if (i == Set_Size)
				addch('>');
			else 
				addch(' ');
			printw("%s\n", set_size[i]);
		}
		
		switch (getch())
		{
			case KEY_UP:
				if (Set_Size)
					Set_Size--;
			break;
			case KEY_DOWN:
				if (Set_Size != 3)
					Set_Size++;
			break;
			case KEY_BACKSPACE:
				//Settings();
				f=false;
				return;
			break;
			case 10:
				if (Set_Size == 0) {size_x = 70; size_y = 20; 
					Setup();f = false;return; Settings(); }
				if (Set_Size == 1) {size_x = 20; size_y = 40; 
					setup_control = 1;
					f = false;return; Settings(); }
				if (Set_Size == 2) {size_x = 40; size_y = 40; 
					setup_control = 2;
					f = false;return; Settings(); }
				if (Set_Size == 3) {f = false;return;Settings(); }
			break;
		}
	}	
}

void Control()
{
	//bool f = true;
	while (f) {
		clear();
		for (unsigned i = 0; i < 3; i++) {
			if (i == set_contrl)
				addch('>');
			else 
				addch(' ');
			printw("%s\n", contrl[i]);
		}
		
		switch (getch())
		{
			case KEY_UP:
				if (set_contrl)
					set_contrl--;
			break;
			case KEY_DOWN:
				if (set_contrl != 2)
					set_contrl++;
			break;
			case KEY_BACKSPACE:
				//Settings();
				f=false;
				return;
			break;
			case 10:
				if (set_contrl == 0) {choice_control = 1;f = false;return; Settings(); }
				if (set_contrl == 1) {choice_control = 2;f = false;return; Settings(); }
				if (set_contrl == 2) {f= false; return; Settings();  }
			break;
		}
	}
}

void Speed()
{
	//bool f = true;
	while (f) {
		clear();
		for (unsigned i = 0; i < 4; i++) {
			if (i == lang)
				addch('>');
			else 
				addch(' ');
			printw("%s\n", set_speed[i]);
		}
		
		switch (getch())
		{
			case KEY_UP:
				if (lang)
					lang--;
			break;
			case KEY_DOWN:
				if (lang != 3)
					lang++;
			break;
			case KEY_BACKSPACE:
				//Settings();
				f=false;
				return;
			break;
			case 10:
				if (lang == 0) {speed_choice = 1;f = false;return; Settings(); }
				if (lang == 1) {speed_choice = 0;f = false;return; Settings(); }
				if (lang == 2) {speed_choice = 2;f = false;return; Settings(); }
				if (lang == 3) { f = false;return;Settings();}
			break;
		}
	}
}

const char MMM[2][7] = {
	"Price",
	"Buying"
};

void Shop()
{
	//bool f = true; 
	int cost = 10; 
	while (!f) {
		clear();
		printw("You can buy a color of snake. Just do it!\nYour balance is %d$\n", score);
		for (unsigned i = 0; i < 10; i++) {
			if (i == color_set_)
				addch('>');
			else 
				addch(' ');
			if((i < 8) && (i > 0)){
			if(mas[i].buy){ printw("%s %s\n", color[i], MMM[1]);
				} else {printw("%s %s %d \n", color[i], MMM[0], mas[i].cost);}
					} else { printw("%s\n", color[i]);}
		}
		
		switch (getch())
		{
			case KEY_UP:
				if (color_set_)
					color_set_--;
			break;
			case KEY_DOWN:
				if (color_set_ != 8)
					color_set_++;
			break;
			case KEY_BACKSPACE:
				f = true; return;
			break;
			case 10:
				if (color_set_ == 0) { color_choice = 0; f = true;return; }
				if (color_set_ == 1) {
					if(mas[color_set_].buy){
						color_choice=1;
						f=true;
						return;
					}	else if (score >= mas[color_set_].cost) { 	 
						mas[color_set_].buy = true; score -=mas[color_set_].cost;
						color_choice = 1; f = true;return;
						} else { 
							printw("\nYou can't buy it!! You need more MONEY"); f=true; return;
							} 
				}



				if (color_set_ == 2) { if(mas[color_set_].buy){
						color_choice=2;
						f=true;
						return;
					}	else if (score >= mas[color_set_].cost) { 	 
						mas[color_set_].buy = true; score -=mas[color_set_].cost;
						color_choice = 2; f = true;return;
						} else { 
							printw("\nYou can't buy it!! You need more MONEY"); f=true; return;
							} 

				 }
				if (color_set_ == 3) {if(mas[color_set_].buy){
						color_choice=3;
						f=true;
						return;
					}	else if (score >= mas[color_set_].cost) { 	 
						mas[color_set_].buy = true; score -=mas[color_set_].cost;
						color_choice = 3; f = true;return;
						} else { 
							printw("\nYou can't buy it!! You need more MONEY"); f=true; return;
							} 
				}
				if (color_set_ == 4) { if(mas[color_set_].buy){
						color_choice=4;
						f=true;
						return;
					}	else if (score >= mas[color_set_].cost) { 	 
						mas[color_set_].buy = true; score -=mas[color_set_].cost;
						color_choice = 4; f = true;return;
						} else { 
							printw("\nYou can't buy it!! You need more MONEY"); f=true; return;
							} 
				}
				if (color_set_ == 5) { if(mas[color_set_].buy){
						color_choice=5;
						f=true;
						return;
					}	else if (score >= mas[color_set_].cost) { 	 
						mas[color_set_].buy = true; score -=mas[color_set_].cost;
						color_choice = 5; f = true;return;
						} else { 
							printw("\nYou can't buy it!! You need more MONEY"); f=true; return;
							} 
				}
				if (color_set_ == 6) {if(mas[color_set_].buy){
						color_choice=6;
						f=true;
						return;
					}	else if (score >= mas[color_set_].cost) { 	 
						mas[color_set_].buy = true; score -=mas[color_set_].cost;
						color_choice = 6; f = true;return;
						} else { 
							printw("\nYou can't buy it!! You need more MONEY"); f=true; return;
							} 
				}
				if (color_set_ == 7) { if(mas[color_set_].buy){
						color_choice=7;
						f=true;
						return;
					}	else if (score >= mas[color_set_].cost) { 	 
						mas[color_set_].buy = true; score -=mas[color_set_].cost;
						color_choice = 7; f = true;return;
						} else { 
							printw("\nYou can't buy it!! You need more MONEY"); f=true; return;
							} 
				}
				if (color_set_ == 8) {f = true;return; }
			break;
		}
	}	
	getch();
}
