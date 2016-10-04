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

	int f = s.g + s.getMD(g);
	int h = s.getMD(g);
	openQ.push(s);

	while (!h)
	{
		Puzzle c = openQ.front();
		closQ.push(c);
		openQ.pop();

	}
	




	//openQ.push(new Puzzle())

	
}

queue<Puzzle> 
(queue<Puzzle> uq) {
	// instantiate required variables
	queue<Puzzle> sq;
	//Puzzle t ,last = null;
	// copy the items to a temp queue
	// so as not to destroy the original queue
	// loop until input is not empty
	while (!tq.isEmpty()) {
		t = tq.dequeue();
		if (last && last <= t) {
			// new element will be at the end of the queue, and we don't have to
			// process any further - short-circuit scenario
			// this is the best case scenario, constant time operation per new item
			sq.enqueue(t);
			// also keep track of the last item in the queue,
			// which in this case is the new item
			last = t;
		}
		else {
			// other scenario: linear time operation per new item
			// new element will be somewhere in the middle (or beginning) so,
			// take elements from the beginning which are less or equal to new item,
			// and put them at the back
			while (!sq.isEmpty() && sq.peek() <= t) {
				sq.enqueue(sq.dequeue());
			}
			// when that is done, now put the new element into the queue,
			// i.e the insertion into the proper place
			sq.enqueue(t);
			// following which, shift the rest elements to the back of the queue,
			// to reconstruct the sorted order,
			// thus always keeping the second queue sorted per insertion
			while (sq.peek() > t) {
				// meanwhile, also keep a track of the last (highest) item in the queue
				// so that we may perform a short-circuit if permitted
				last = sq.dequeue();
				sq.enqueue(last);
			}
		}

	}
	return sq;
}