#include <iostream>
using namespace std;
int n;
	
int pos(int x, int y)
{
	int p;
	if (x == 0)
	{
		p = y;
	}
	else if (x == n)
	{
		p = 3 * n - y;
	}
	if (y == n)
	{
		p = x + y;
	}
	else if (y == 0)
	{
		p = 4 * n - x;
	}
	return p;
}

int abs(int x)
{
	return (x < 0) ? -x : x;
}

int main(int argc, char **argv)
{
	cin >> n;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int p1 = pos(x1, y1), p2 = pos(x2, y2);
	cout << min(abs(p2 - p1), 4 * n - abs(p2 - p1));
	return 0;
}