#include <iostream>
using namespace std;

int abs(int x)
{
	return (x < 0) ? -x : x;
}

bool bk(int x, int y, int x2, int y2)
{
	return (abs(x2 - x) + abs(y2 - y) == 3) && (x != x2) && (y != y2);
}

bool bl(int x, int y, int x2, int y2)
{
	return (x2 - x == 0) || (y2 - y == 0);
}


int main()
{
	char x1, y1, x2, y2, t;
	cin >> x1 >> y1 >> x2 >> y2;
	x1 -= 'a', y1 -= '1', x2 -= 'a', y2 -= '1';
	int ans = 0;
	for (int x = 0; x < 8; x++)
		for (int y = 0; y < 8; y++)
		{
			if ((x == x1 && y == y1) || (x == x2 && y == y2))
				continue;
			ans += !(bk(x, y, x1, y1) || bk(x2, y2, x1, y1) || bl(x1, y1, x, y) || bk(x2, y2, x1, y1) || bk(x, y, x2, y2) || bk(x2, y2, x, y));
		}
	cout << ans;
}