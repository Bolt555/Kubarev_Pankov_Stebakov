#include <ncurses.h>

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
	"20x70",
	"50x50",
	"Back"
};

const char contrl[4][25] = {
	"w, a, s, d",
	"up, left, down, right",
	"Your set",
	"Back"
};

const char set_lang[4][10] = {
	"Russian",
	"English",
	"Spain",
	"Back"
};

unsigned choice = 0, set = 0, Set_Size = 0, set_contrl = 0, lang = 0;

void Play();
void Menu();
void Settings();
void Size();
void Control();
void Shop();
void Language();

int main()
{
	initscr();
	curs_set(0);
	keypad(stdscr, true);

	Menu();	

	endwin();
	return 0;
}

void Play()
{
	
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
				if (choice == 0) { Play(); f = false;}
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
				return;
			break;
			case 10:
				if (Set_Size == 0) {Settings(); f = false;}
				if (Set_Size == 1) {Settings(); f = false;}
				if (Set_Size == 2) {Settings(); f = false;}
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
				return;
			break;
			case 10:
				if (set_contrl == 0) {Settings(); f = false;}
				if (set_contrl == 1) {Settings(); f = false;}
				if (set_contrl == 2) {Settings(); f = false;}
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
				if (lang == 3) {Settings(); f= false; }
			break;
		}
	}
}

void Shop()
{
	clear();
	printw("H");
	getch();
}
