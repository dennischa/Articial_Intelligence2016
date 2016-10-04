#include <iostream>
#include <cmath>

using namespace std;

struct Point {
	int x, y;
};

class Puzzle {
public:
	int p[5][5] = { 0, };
	int x, y;
	int g = 0;
	int pastdir = -1;
	int path[10] = {0, };


	Puzzle(int arr[5][5], int by, int bx, int gn)
	{
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				p[i][j] = arr[i][j];
			}
		}
		x = bx;
		y = by;
		p[y][x] = 0;
		g = gn;
	}

	Point getPosofValue(int n) {
		Point point;
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				if (p[i][j] == n)
				{
					point.y = i;
					point.x = j;
					break;
				}
			}
		}

		return point;
	}

	int getDistance(Point start, Point end)
	{
		return abs(start.x - end.x) + abs(start.y - end.y);
	}

	//get Mahattan Distance
	int getMD(Puzzle goal) {

		int dis = 0;
		for (int i = 1; i < 9; i++){
			Point s;
			Point g;
			s = getPosofValue(i);
			g = goal.getPosofValue(i);			
			dis += getDistance(s, g);
		}
		return dis;		
	}

	// 0 :left , 1: right, 2: up, 3: down
	Puzzle setChildPuzzle(int n) {
		Puzzle cp(p, y, x,g + 1);
		for (int i = 0; i <= cp.g;i++)
			cp.path[i] = path[i];
		cp.path[g + 1] = n;

		cp.pastdir = n;
		
		int x = cp.x;
		int y = cp.y;

		

		switch (n) {
		case 0:
			cp.p[y][x] = cp.p[y][x - 1];
			cp.p[y][x - 1] = 0;
			cp.x = x - 1;
			break;
		case 1:
			cp.p[y][x] = cp.p[y][x + 1];
			cp.p[y][x + 1] = 0;
			cp.x = x + 1;
			break;
		case 2:
			cp.p[y][x] = cp.p[y-1][x];
			cp.p[y-1][x] = 0;
			cp.y= y - 1;
			break;
		case 3:
			cp.p[y][x] = cp.p[y + 1][x];
			cp.p[y + 1][x] = 0;
			cp.y = y + 1;
			break;
		}

		return cp;
	}

	void printPuzzle() {
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				cout << p[i][j]<< " ";
			}
			cout << endl;
		}
	}
};
