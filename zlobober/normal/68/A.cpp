#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cstdio>
using namespace std;

//#define TASK ""

bool good(int x, pair<int, int>* q)
{
	int y = x;
	for (int i = 0; i < 4; i++)
		y %= q[i].first;
	return x == y;
}

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	int n;
	pair<int, int> p[4];
	int a, b;
	
	for (int i = 0; i < 4; i++)
		cin >> p[i].first, p[i].second = i;
	cin >> a >> b;
	int ans = 0;
	pair<int, int> q[4];
	int col;
	sort(p, p + 4);
	for (int i = a; i <= b; i++)
	{
		for (int j = 0; j < 4; j++)
			q[j] = p[j];
		col = 0;
		do
		{
			col += good(i, q);
		} while (next_permutation(q, q + 4));
		ans += col >= 7;
	}
	cout << ans;
	return 0;
}