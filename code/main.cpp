#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <fstream>
using namespace std;


void drawBond(HANDLE h, COORD t, COORD b, int numbersR[15][5], int numbersD[15][5]){
	system("cls"); SetConsoleTextAttribute(h, (WORD)((30 << 4) | 0));
	int lenx = b.X-t.X-2, leny = b.Y-t.Y-1;
	COORD f = t;
	unsigned char c;
	SetConsoleCursorPosition(h, f);
	c = 457; cout << c;
	c = 461;
	for(int i=0; i < lenx; i++){//top
		cout << c;
	}
	c=442; f=t; f.Y++;
	for(int i=0; i< leny-1;i++){//left
		SetConsoleCursorPosition(h, f);f.Y++;
		cout<<c;
	}
	SetConsoleCursorPosition(h, f);f.Y++;
	c= 456; cout << c;
	f.X = t.X+1; f.Y = b.Y; c= 461;
	for(int i=0; i < lenx;i++){//bottom
		cout<<c;
	}
	c=444; cout<<c;
	c=442;
	f.X = b.X -1; f.Y = b.Y-2;
	for(int i=leny; i >1;i--){//right
		SetConsoleCursorPosition(h, f);
		f.Y--;
		cout<<c;
	}
	f.X = b.X-1; f.Y = t.Y;
	SetConsoleCursorPosition(h, f);
	c=443; cout<<c;
	c=95;
	SetConsoleCursorPosition(h, {1,2});
	for(int i=1; i < 44; i+=3){//linesG
		SetConsoleCursorPosition(h, {1,i+2});
		for(int j=0; j < lenx; j++){
			cout << c;
		}
	}
	c=124;
	for(int i=7; i < 112; i+=7){//linesV
		SetConsoleCursorPosition(h, {i+2,1});
		for(int j=0; j < leny-1; j++){
			SetConsoleCursorPosition(h, {i,1+j});
			cout << c;
		}
	}
	SetConsoleTextAttribute(h, (WORD)((30 << 4) | 0));
	for(int i=0; i < 15; i++){
		for(int j=0; j < 5; j++){
			if(numbersR[i][j] >= 10)
				SetConsoleCursorPosition(h, {b.X - 10 + j*2 - 1, 2 + i*3});
			else{
				SetConsoleCursorPosition(h, {b.X - 10 + j*2, 2 + i*3});
			}
			if(numbersR[i][j] != 0){
				cout << numbersR[i][j];
				cout << "|";
			}
		}
	}
	
	for(int i=0; i < 15; i++){
		for(int j=0; j < 5; j++){
			SetConsoleCursorPosition(h, {t.X + 4 + i*7, b.Y - 6 + j});
			if(numbersD[i][j] != 0){
				cout << numbersD[i][j];
			}
		}
	}
	SetConsoleTextAttribute(h, (WORD)((30 << 4) | 0));
	c=442;
	f.X = b.X -1; f.Y = b.Y-2;
	for(int i=leny; i >1;i--){//right
		SetConsoleCursorPosition(h, f);
		f.Y--;
		cout<<c;
	}
	
	
	SetConsoleCursorPosition(h, {2, 2});
}

void fill(HANDLE h, int x, int y){
    SetConsoleTextAttribute(h, (WORD)((9 << 4) | 0));
    for(int i=0; i < 6; i++){
	    for(int j=0; j < 3; j++){
    		SetConsoleCursorPosition(h, {x+i-1, y+j-1});
    		cout << " ";
		}	
	}
}
void cross(HANDLE h, int x, int y, int color){//20 24
    SetConsoleTextAttribute(h, (WORD)((color << 4) | 0));
    for(int i=0; i < 3; i++){
   		SetConsoleCursorPosition(h, {x+i*2-1, y+i-1});
  		cout << " ";
  		SetConsoleCursorPosition(h, {x+i*2, y+i-1});
  		cout << " ";
	}
	for(int i = 3; i > 0; i--){
   		SetConsoleCursorPosition(h, {x+i*2-3, y-i+2});
  		cout << " ";
  		SetConsoleCursorPosition(h, {x+i*2-2, y-i+2});
  		cout << " ";
	}
}
char* menu[] = {"Start", "Rules", "Exit"};
char* lvls[] = {"Level1 (House)", "Level2 (Fish)", "Exit"};

void printMenu(HANDLE h, COORD c, int k, int n, int len){
	SetConsoleTextAttribute(h, (WORD)((30 << 4) | 5));
	system("cls");
	SetConsoleTextAttribute(h, (WORD)((30 << 4) | 0));
	COORD cc = c;	
	for(int i=0; i<n; i++){
		cc.X = c.X + i*len;
		SetConsoleCursorPosition(h, cc);
		cout<< menu[i];
	}
	cc.X = c.X + k*len;
	SetConsoleTextAttribute(h, (WORD)((30 << 4) | 5));
	SetConsoleCursorPosition(h, cc);
	cout << menu[k];
}

void printLvls(HANDLE h, COORD c, int k, int n, int len){
	SetConsoleTextAttribute(h, (WORD)((30 << 4) | 5));
	system("cls");
	SetConsoleTextAttribute(h, (WORD)((30 << 4) | 0));
	COORD cc = c;	
	for(int i=0; i<n; i++){
		cc.X = c.X + i*len;
		SetConsoleCursorPosition(h, cc);
		cout << lvls[i];
	}
	cc.X = c.X + k*len;
	SetConsoleTextAttribute(h, (WORD)((30 << 4) | 5));
	SetConsoleCursorPosition(h, cc);
	cout << lvls[k];
}

void printRules(HANDLE h){
	SetConsoleTextAttribute(h, (WORD)((30 << 4) | 5));
	system("cls");
	SetConsoleTextAttribute(h, (WORD)((30 << 4) | 0));
	cout << "When solving Japanese crossword puzzles, a person considers each row / column separately, constantly moving on to the next columns and rows. In this case, the solution process in each row/column is reduced to:";
	cout << endl << endl << "1) Determining the cells that will definitely be painted over (for any possible arrangement of groups) - we paint over them." << endl;
	cout << "2) Determination of cells in which the presence of filled cells is impossible - such cells are crossed out with a cross (sometimes a bold dot is used instead of a cross)." << endl;
	cout << "3) Identification of digits whose position has already been calculated - usually these digits are crossed out." << endl;
}

void cursorMove(HANDLE h, int x, int y, int step, int dirx, int diry){
	SetConsoleCursorPosition(h, {x, y}); 
}
	
void read(int pic[15][15], int numbersR[15][5], int numbersD[15][5], int number){
	char c;
	int counter = 0;
    setlocale(LC_ALL, "eu");
	ifstream file ("file.txt");

	if (file.is_open()) {
		while(file){
			file >> c;
			if(c == '.'){
				if(counter == number){
					for(int i = 0; i < 15; i++){
						for(int j = 0; j < 15; j++){
							file >> pic[i][j];
						}
					}
					file >> c;
					if(c == ','){
						for(int i = 0; i < 15; i++){
							for(int j = 0; j < 5; j++){
								file >> numbersR[i][j];
							}
						}
						for(int i = 0; i < 15; i++){
							for(int j = 0; j < 5; j++){
								file >> numbersD[i][j];
							}
							cout<<endl;
						}
						break;	
					}
				}
				counter++;
			}
		}
	}
}


int main(){
	bool playing = false, escape = true, selectLvl = false, readingRules = false;;
	int x = 2, y = 2;
    int step = 5;
    char c;
    int k = 0, n = 3;
    int pic[15][15], filled[15][15];
    int numbersR[15][5]; int numbersD[15][5];
    
	short status;
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD t = {0, 0}, b = {116, 52};
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(h, &csbiInfo);
	SetConsoleTextAttribute(h, (WORD)((30 << 4) | 5));
	system("cls");
	
    SetConsoleCursorPosition(h, {x, y});
	
	printMenu(h, {6, 3}, 0, 3, 20);
	do{
		c = getch();
		switch(c){
            case 75: //left
            	if(x >2 && playing){
					x -= step + 2;
					cursorMove(h, x, y, step, -1, 0);
				}
				else if(!playing){
					if(k == 0){
						k = n-1;
					}
					else 
						k--;
					if(!selectLvl)
						printMenu(h, {6, 3}, k, n, 20);
					else
						printLvls(h, {6, 3}, k, n, 20);
				}
				break;
			case 77: //right
				if(x < 100 && playing){
					x += step + 2;
					cursorMove(h, x, y, step, 1, 0);
				}
				else if(!playing){
					if(k == n-1){
						k = 0;
					}
					else 
						k++;
					if(!selectLvl)
						printMenu(h, {6, 3}, k, n, 20);
					else
						printLvls(h, {6, 3}, k, n, 20);
				}
				break;
			case 72: //down
				if(y > 3 && playing){
					y -= step - 2;
					cursorMove(h, x, y, step, 0, 1);
				}
				break;
			case 80: //up
				if(y < 42 && playing){
					y += step - 2;
					cursorMove(h, x, y, step, 0, -1);
				}
				break;
			case 32: //space
				if(playing){
					playing = false;
					for(int i = 0; i < 15; i++){
						for(int j = 0; j < 15; j++){
							if(pic[i][j] == 1 && (filled[i][j] == 0 || filled[i][j] == 2)){
								playing = true;
								break;
							}
						}
					}
					if(!playing){
						SetConsoleTextAttribute(h, (WORD)((0 << 4) | 0));
						system("cls");
						k = 0;
						printMenu(h, {6, 3}, k, n, 20);
						break;	
					}
					if(filled[(y-2)/3][(x-2)/7] == 0){
						if(pic[(y-2)/3][(x-2)/7] && playing){
							fill(h, x, y);
							filled[(y-2)/3][(x-2)/7] = 1;
						}
						else if(playing){
							cross(h, x, y, 20);
							filled[(y-2)/3][(x-2)/7] = 2;
						}
					}	
				}
				break;
			case 13: //enter
				if(!playing){
				    for(int i = 0; i < 15; i++){
						for(int j = 0; j < 15; j++){
							filled[i][j] = 0;
						}
					}
					switch(k){
						case 0:
							printLvls(h, {6, 3}, k, n, 20);
							if(selectLvl){
								read(pic, numbersR, numbersD, 0);
								playing = true;
								drawBond(h, t, b, numbersR, numbersD);
						 		x = 2; y = 2;
							}
							selectLvl = true;
							break;
						case 1:
							printRules(h);
							if(selectLvl){
								read(pic, numbersR, numbersD, 1);
								playing = true;
								drawBond(h, t, b, numbersR, numbersD);
								x = 2; y = 2;
							}
							readingRules = true;
							break;
						case 2:
							escape = false;
							break;
					}
				}
				else{
					if(!filled[(y-2)/3][(x-2)/7]){
						if(pic[(y-2)/3][(x-2)/7]){
							cross(h, x, y, 20); // true
							filled[(y-2)/3][(x-2)/7] = 1;
						}
						else{
							cross(h, x, y, 24); // mimo
							filled[(y-2)/3][(x-2)/7] = 2;
						}
						
					}
				}
				break;	
			case 27: //escape
				playing = false; selectLvl = false; readingRules = false;
				SetConsoleTextAttribute(h, (WORD)((0 << 4) | 0));
				system("cls");
				k = 0;
				printMenu(h, {6, 3}, k, n, 20);
				break;		
        }
	}while(escape);
	system("cls");
}
