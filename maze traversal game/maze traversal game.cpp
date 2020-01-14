// maked by navid
// manafinavid@yahoo.com
// https://github.com/manafinavid
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
string maze_[12] = {"############",
				   "#...#......#",
				   "..#.#.####.#",
				   "###.#....#.#",
				   "#....###.#..",
				   "####.#.#.#.#",
				   "#..#.#.#.#.#",
				   "##.#.#.#.#.#",
				   "#........#.#",
				   "######.###.#",
				   "#......#...#",
				   "######.#####"};
string egg[5] = { "#####",
			  "#K  #",
			  "###  ",
			  "#   #",
			  "#####" };
string Finish[]=
{ "#####",
"#   #",
"    D",
"#   #",
"#####" };
void show(int x, int y, string* maze) {
	system("Cls");
	char temp;
	temp = maze[x][y];
	maze[x][y] = '0';
	int i;
	int j;
	for ( i= 0; i < maze[i].length(); i++) {

		for (j = 0; j < maze[i].length(); j++) {
			
			cout << maze[i][j] << " ";
		}
		cout << endl;
	}
	maze[x][y] = temp;
}
void End();
bool result = false;
int main()
{
s:	int x = 11, y =6;
	string* map = maze_;
	show(x, y,map);
	char i;
	bool e=false;
	bool f = false, k=false;
	while (!result)
	{
		i = _getch();
		switch (i)
		{
		case 'W':
		case 'w':
			if (map[x-1][y]=='#')
			{
				End();
				break;
			}
			x--;
			show(x, y,map);
			break;
		case 'A':
		case 'a':
			if (y <= 0) {
				map = egg;
				y = 4;
				e = true;
				goto bug;
			}
			if (map[x][y-1] == '#')
			{
				End();
				break;
			}
			y--;
			if (map == egg && y == 1 && x == 1) {
				k = true;
				map[1][1] = ' ';
			}
			if (f == true && y == 0 && x == 2) {
				e = false;
				map = maze_;
				y = 11;
				x = 2;
			}
bug:			show(x, y,map);
			break;
		case 'S':
		case 's':
			x++;
			if (x == 12) {
				x --;
			}
			if (map[x][y] == '#')
			{
				End();
				break;
			}

			show(x, y,map);
			break;
		case 'D':
		case 'd':
			if (map[x][y+1] == '#')
			{
				End();
				break;
			}
			y++;
			if (map == Finish && x == 2 && y == 4) {
				if (k == false) {
					cout << "you dont have key" << endl;
					_getch();
					y--;
				}
			}
			if (e == true && y == 5 && x == 2) {
				e = false;
				map = maze_;
				y = 0;
				x = 2;
			}
			if (f==false&& x == 4 && y == 11) {
				f = true;
				map = Finish;
				x = 2;
				y = 0;
			}
			show(x, y,map);
			break;
		default:
			show(x, y,map);
		}
		if (map == Finish && k==true&&x==2&&y==4) {
a:			cout << "you are win :)" << endl<<"Try again? (Y/N):";
			char f =_getch();
			switch (f)
			{
			case 'Y':
			case 'y':
				goto s;
			case 'N':
			case 'n':
				break;
			default:
				goto a;
			}
			break;
		}
	}
}
void End() {
	system("cls");
a:	cout << "Game Over :/" << endl << "Try again? (Y/N):";
	char f = _getch();
	switch (f)
	{
	case 'Y':
	case 'y':
		main();
		break;
	case 'N':
	case 'n':
		result = true;
		break;
	default:
		goto a;
	}
}
