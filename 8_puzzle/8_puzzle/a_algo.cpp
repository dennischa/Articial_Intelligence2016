#include "Puzzle.cpp"
#include <queue>

using namespace std;

int goal[5][5] = { 0, 0, 0, 0, 0,
0, 1, 2, 3, 0,
0, 8, 0, 4, 0,
0, 7, 6, 5, 0,
0, 0, 0, 0, 0 };
int gy = 2, gx = 2;
Puzzle g(goal, gy, gx, 0);
queue<Puzzle> queSort(queue<Puzzle> a);

int main() {
	int start[5][5] = { 0, 0, 0, 0, 0,
					  0, 2, 8, 3, 0,
					  0, 1, 6, 4, 0,
					  0, 7, 0, 5, 0,
					  0, 0, 0, 0, 0 };

	int sy = 3, sx = 2;
	
	
	//Puzzle(int arr[5][5],int by, int bx, int gn)
	Puzzle s(start, sy, sx, 0);
	

	queue<Puzzle> openQ;
	queue<Puzzle> closQ;
	queue<Puzzle> copy;
	Puzzle c = s;

	int f = s.g + s.getMD(g);
	int h = s.getMD(g);
	openQ.push(s);
	int Qnumber = 1;
	int path[10] = { 0, };

	while (h)
	{
		c = openQ.front();
		path[c.g] = c.pastdir;
		h = c.getMD(g);
		
		closQ.push(c);
		openQ.pop();

		// 0 :left , 1: right, 2: up, 3: down
		if (c.x != 1) {
			Puzzle left = c.setChildPuzzle(0);
			openQ.push(left);
		}

		if (c.y != 1){
			Puzzle up = c.setChildPuzzle(2);
			openQ.push(up);
		}

		if (c.x != 3) {
			Puzzle right = c.setChildPuzzle(1);
			openQ.push(right);
		}

		if (c.y != 3){
			Puzzle down = c.setChildPuzzle(3);
			openQ.push(down);
		}
		openQ = queSort(openQ);

		copy = openQ;
		
		cout << Qnumber++ << "¹øÂ° Q"<< endl;
		cout << "------------" << endl;
		for (int i = 0; i < copy.size();i++)
		{
			copy.front().printPuzzle();
			copy.pop();
			cout << "------------" << endl;
		}
	}
	cout << endl;
	cout << "Solution Path" << endl;
	for (int i = 1; i <= c.g; i++) {
		switch (path[i]) {
		case 0:
			cout << "left";
			break;
		case 1:
			cout << "right";
			break;
		case 2:
			cout << "up";
			break;
		case 3:
			cout << "down";
			break;
		}
		cout << endl;
	}
		
}

queue<Puzzle> queSort(queue<Puzzle> a) {
	queue<Puzzle> b;
	b.push(a.front());
	a.pop();
	
	while (!a.empty()) {
		Puzzle next = a.front();
		a.pop();
		for (int i = 0; i < b.size(); i++)
		{
			if (b.front().g + b.front().getMD(g) < next.g + next.getMD(g))
			{
				b.push(b.front());
				b.pop();
			}
			else
			{
				b.push(next);
				next = b.front();
				b.pop();
			}
		}
		b.push(next);
	}

	return b;
}