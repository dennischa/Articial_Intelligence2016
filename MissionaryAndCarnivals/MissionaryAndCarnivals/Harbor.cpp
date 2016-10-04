#include <iostream>
#include <cmath>

using namespace std;

enum Direction {
	Left,
	Right
};

struct Move {
	int changeOfm, changeOfc;
};


class Harbor{

public:
	int left_m, right_m;
	int left_c, right_c;
	Direction dir;
	int g = 0;
	int h = 0;
	Move p[5] = { { 1,1 },{ 1,0 },{ 0,1 },{ 2,0 }, (0,2) };

	Harbor(int lm,int lc,int rm,int rc,Direction d) {
		left_m = lm;
		left_c = lc;
		right_m = rm;
		right_c = rc;
		dir = d;
	}

	Harbor(const Harbor& com) {
		left_m = com.left_m;
		left_c = com.left_c;
		right_m = com.right_m;
		right_c = com.right_c;
		dir = com.dir;
		g = com.g;
	}

	// d = left or right, n = 0~4;
	Harbor move_Harbor(Direction d, int n) {
		Harbor tmp(*this);
		tmp.g = tmp.g + 1;
	
		Move m = p[n];

		if (d == Right)
		{
			tmp.left_m -= m.changeOfm;
			tmp.left_c -= m.changeOfc;

			tmp.right_m += m.changeOfm;
			tmp.right_c += m.changeOfc;
			tmp.dir = Left;
		}
		else
		{
			tmp.left_m += m.changeOfm;
			tmp.left_c += m.changeOfc;

			tmp.right_m -= m.changeOfm;
			tmp.right_c -= m.changeOfc;
			tmp.dir = Right;
		}
		return tmp;
	}

	int heuristic(Harbor goal)
	{
		return abs(right_c - goal.right_c) + abs(right_m - goal.right_m);
	}



	bool checkDeadEnd() {
		if (left_m < left_c || right_m < right_c)
			return true;
		else
			return false;
	}


};