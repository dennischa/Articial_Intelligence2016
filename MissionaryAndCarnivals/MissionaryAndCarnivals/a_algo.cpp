#include "Harbor.cpp"
#include <queue>


queue<Harbor> queSort(queue<Harbor> a);
Harbor s(3, 3, 0, 0, Right);
Harbor g(0, 0, 3, 3, Left);
int main() {
	//Harbor(int lm,int lc,int rm,int rc,Direction d) 
	

	queue<Harbor> openQ;
	queue<Harbor> closQ;
	queue<Harbor> copy;
	Harbor c = s;

	int f = s.g + s.heuristic(g);
	int check_h = s.heuristic(g);

	openQ.push(s);

	while (c.right_c + c.right_m != 6) {

		c = openQ.front();
		closQ.push(c);
		openQ.pop();

		check_h = c.heuristic(g);

		if (!c.checkDeadEnd())
		{
			if (c.dir == Right)
			{
				// 0 : 1,1  >>  1: 1,0  >> 2 : 0,1 >> 3 : 2,0  >> 4 : 0,2
				if (c.left_m >= 1 && c.left_c >= 1)
					openQ.push(c.move_Harbor(Right, 0));

				if (c.left_m >= 1)
					openQ.push(c.move_Harbor(Right, 1));

				if (c.left_c >= 1)
					openQ.push(c.move_Harbor(Right, 2));

				if (c.left_m >= 2)
					openQ.push(c.move_Harbor(Right, 3));

				if (c.left_c >= 2)
					openQ.push(c.move_Harbor(Right, 4));
			}
			else
			{
				// 0 : 1,1  >>  1: 1,0  >> 2 : 0,1 >> 3 : 2,0  >> 4 : 0,2
				if (c.right_m >= 1 && c.right_c >= 1)
					openQ.push(c.move_Harbor(Left, 0));

				if (c.right_m >= 1)
					openQ.push(c.move_Harbor(Left, 1));

				if (c.right_c >= 1)
					openQ.push(c.move_Harbor(Left, 2));

				if (c.right_m >= 2)
					openQ.push(c.move_Harbor(Left, 3));

				if (c.right_c >= 2)
					openQ.push(c.move_Harbor(Left, 4));
			}
		}
		openQ = queSort(openQ);
	
 	}
	cout << 000 << endl;
	cout << c.right_c << c.right_m << endl;
	
}

queue<Harbor> queSort(queue<Harbor> a) {
	queue<Harbor> b;
	b.push(a.front());
	a.pop();

	while (!a.empty()) {
		Harbor next = a.front();
		a.pop();
		for (int i = 0; i < b.size(); i++)
		{
			if (b.front().g + b.front().heuristic(g) < next.g + next.heuristic(g))
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