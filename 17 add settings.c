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
bool Game_Over = true, fruit = false, fr_on_sn = false, flag = false;
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
const char list_set[4][10] = {
	"Size",
	"Control",
	"Language",
	"Back"
};

const char set_size[4][10] = {
	"70x20",
	"20x40",
	"40x40",
	"Back"
};

const char contrl[4][25] = {
	"up, left, down, right",
	"w, a, s, d",
	"Your set",
	"Back"
};

const char set_lang[4][10] = {
	"Russian",
	"English",
	"Spain",
	"Back"
};

unsigned choice = 0, set = 0, Set_Size = 0, set_contrl = 0, lang = 0, choice_control = 1;

void Menu();
void Settings();
void Size();
void Control();
void Shop();
void Language();
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
void Input_3();
void Snake();

int main()
{	
	initscr();
	srand(time(0));
	curs_set(0);
	noecho();		
	keypad(stdscr, true);

	Menu();				

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
	printw("Score: %d$", score);	
	for (int i = 0; i <= size_y; i++) {
		for (int j = 0; j <= size_x; j++) {
		if ((i == 1 || i == size_y) || ((j == 0 && i != 0)) || ((j == size_x) && (i != 0))) 				{ mvaddch(i, j, '='); }
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
		switch (getch())
		{
			case KEY_UP:
				halfdelay(3);
				dir = UP;
			break;

			case KEY_DOWN:
				halfdelay(3);
				dir = DOWN;
			break;

			case KEY_LEFT:
				halfdelay(3);
				dir = LEFT;
			break;
				
			case KEY_RIGHT:
				halfdelay(3);
				dir = RIGHT;	
			break;
			case 'q':
				Game_Over = false;
				clear();refresh(); 
				Menu();	
			break;			
		}
}

void Input_2()
{
		switch (getch())
		{
			case 'w':
				halfdelay(3);
				dir = UP;
			break;

			case 's':
				halfdelay(3);
				dir = DOWN;
			break;

			case 'a':
				halfdelay(3);
				dir = LEFT;
			break;
				
			case 'd':
				halfdelay(3);
				dir = RIGHT;	
			break;
			case 'q':
				Game_Over = false;
				clear();refresh(); 
				Menu();	
			break;			
		}
}

void Input_3()
{
		/*switch (ctrl)
		{
			case ctrl[0]:
				halfdelay(3);
				dir = UP;
			break;

			case ctrl[1]:
				halfdelay(3);
				dir = DOWN;
			break;

			case ctrl[2]:
				halfdelay(3);
				dir = LEFT;
			break;
				
			case ctrl[3]:
				halfdelay(3);
				dir = RIGHT;	
			break;
			case ctrl[4]:
				Game_Over = false;
				clear();refresh(); 
				Menu();	
			break;			
		}*/
}

void Logic()
{
	switch (dir)
		{
			case UP:
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
				mvaddch(fruit_y, fruit_x, '$');		
				Print_Snake();
				refresh();
			break;

			case DOWN:
				clear();
				if (snake.y[0] + 1 != snake.y[1]) {				
					if (snake.y[0] == size_y-1) { Game_Over = false; break;}
					for (int i = 1; i < size_snake; i++) {
						if (snake.x[0]==snake.x[i]&&snake.y[0]+1==snake.y[i]) {
							Game_Over = false; break;
						}
					}
					Pereresovka();
					snake.y[0]++; }
				Pole();
				Eat_Fruit();
				mvaddch(fruit_y, fruit_x, '$');
				Print_Snake();
				refresh();
				
			break;

			case RIGHT:
				clear();
				if (snake.x[0] + 1 != snake.x[1]) {
					if (snake.x[0] == size_x-1) { Game_Over = false; break;}
					for (int i = 1; i < size_snake; i++) {
						if (snake.x[0]+1==snake.x[i]&&snake.y[0]==snake.y[i]) {
							Game_Over = false; break;
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
				mvaddch(fruit_y, fruit_x, '$');	
				Print_Snake();
				refresh();
				
			break;			
		}
}

void Snake()
{
	if (!flag) { Setup(); }
	Pole();
	Print_Snake();
	mvaddch(fruit_y, fruit_x, '$');
	while (Game_Over)
	{		
		if (choice_control == 1) { Input_1(); }
		if (choice_control == 2) { Input_2(); }
		if (choice_control == 3) { Input_3(); }
		Logic();
	}
	clear();
	halfdelay(100);
	printw("Game Over! Your score is %d$", score);
	
	refresh();
}

void Settings()
{
	bool f = true;
	while (f) {
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
				return;
			break;
			case 10:
				if (set == 0) { Size() ;f = false;}
				if (set == 1) { Control(); f = false;}
				if (set == 2) { Language(); f = false;}
				if (set == 3) { Menu(); f= false;}
			break;
		}
	}	
}

void Menu()
{
	bool f = true;
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
				if (choice == 0) { clear(); Snake(); f = false;}
				if (choice == 1) { Settings(); f = false;}
				if (choice == 2) { Shop(); f = false; }				
				if (choice == 3) {f = false;}
			break;
		}
	}
}

void Size()
{
	bool f = true;
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
				Settings();
			break;
			case 10:
				if (Set_Size == 0) {size_x = 70; size_y = 20; 
					Setup(); Settings(); flag = true; f = false;}
				if (Set_Size == 1) {size_x = 20; flag = true;size_y = 40; 
					snake.x[0] = 10;
					snake.y[0] = 10;
					snake.x[1] = 10;
					snake.y[1] = 11;
					snake.x[2] = 10;
					snake.y[2] = 12; 
					fruit_x = rand()%(size_x - 3) + 2; 
					fruit_y = rand()%(size_y - 2) + 2;
					Settings(); f = false;}
				if (Set_Size == 2) {size_x = 40; size_y = 40; flag = true; 
					snake.x[0] = 20;
					snake.y[0] = 10;
					snake.x[1] = 20;
					snake.y[1] = 11;
					snake.x[2] = 20;
					snake.y[2] = 12;
					fruit_x = rand()%(size_x - 3) + 2; 
					fruit_y = rand()%(size_y - 2) + 2;
					Settings(); f = false;}
				if (Set_Size == 3) {Settings(); f = false;}
			break;
		}
	}	
}

void Control()
{
	bool f = true;
	while (f) {
		clear();
		for (unsigned i = 0; i < 4; i++) {
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
				if (set_contrl != 3)
					set_contrl++;
			break;
			case KEY_BACKSPACE:
				Settings();
			break;
			case 10:
				if (set_contrl == 0) {choice_control = 1; Settings(); f = false;}
				if (set_contrl == 1) {choice_control = 2; Settings(); f = false;}
				if (set_contrl == 2) {choice_control = 3; clear(); 
					printw("UP: "); scanw("%c", ctrl[0]);		
					printw("DOWN: "); scanw("%c", ctrl[1]);
					printw("LEFT: "); scanw("%c", ctrl[2]);
					printw("RIGHT: "); scanw("%c", ctrl[3]); 
					printw("EXIT: "); scanw("%c", ctrl[4]);
					Settings(); f = false;}
				if (set_contrl == 3) {Settings(); f= false; }
			break;
		}
	}
}

void Language()
{
	bool f = true;
	while (f) {
		clear();
		for (unsigned i = 0; i < 4; i++) {
			if (i == lang)
				addch('>');
			else 
				addch(' ');
			printw("%s\n", set_lang[i]);
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
				return;
			break;
			case 10:
				if (lang == 0) {Settings(); f = false;}
				if (lang == 1) {Settings(); f = false;}
				if (lang == 2) {Settings(); f = false;}
				if (lang == 3) {Settings(); f = false;}
			break;
		}
	}
}

void Shop()
{

}
