#include <iostream>
#include <cstdio>
using namespace std;

//#define TASK ""

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	int x, y, z;
	cin >> x >> y >> z;
	int k;
	cin >> k;
	int a, b, c;
	if (x > y)
		swap(x, y);
	if (y > z)
		swap(y, z);
	if (x > y)
		swap(x, y);
	a = min(x - 1, (k + 2) / 3);
	k -= a;
	b = min(y - 1, (k + 1) / 2);
	k -= b;
	c = min(z - 1, (k + 0) / 1);
	k -= c;
	cout << (long long)(a + 1) * (long long)(b + 1) * (c + 1);
	return 0;
}