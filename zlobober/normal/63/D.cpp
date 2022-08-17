#include <iostream>
#include <memory.h>
#include <stack>
using namespace std;

const int N = 200;

char F[N][N];

int par[256];
int main()
{
	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	memset(F, '.', sizeof(F));
	
	for (char c = 'a'; c < 'a' + n; c++)
		cin >> par[c];
	
	for (int i = 1; i <= b; i++)
		for (int j = 1; j <= a; j++)
			F[i][j] = '#';
	
	for (int i = 1; i <= d; i++)
		for (int j = a + 1; j <= c + a; j++)
			F[i][j] = '#';
	
	int dir, x, y;
	
	if (b > d)
	{
		if ((b - d) % 2)
			y = b, x = a, dir = -1;
		else
			y = b, x = 1, dir = 1;
	}
	else
	{
		if ((d - b) % 2)
			y = d, x = a + 1, dir = 1;
		else
			y = d, x = a + c, dir = -1;
	}
	
	int cur = 'a';
	for (int t = 0; t < a * b + c * d; t++)
	{
		if (par[cur] == 0)
			cur++;
		par[cur]--;
		F[y][x] = cur;
		x += dir;
		if (F[y][x] == '.')
			y--, x -= dir, dir *= -1;
	}
	cout << "YES" << endl;
	for (int y = 1; y <= max(b, d); y++)
	{
		for (int x = 1; x <= a + c; x++)
			cout << F[y][x];
		cout << endl;
	}
	return 0;
}