#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

//#define TASK ""

const int N = 100500;

bool F[N];

int n;
	

bool check(int q)
{
	if (n / q <= 2)
		return false;
	
	for (int i = 0; i < q; i++)
	{
		int t;
		for (t = i; t < n; t += q)
			if (!F[t])
				break;
		if (t >= n)
			return true;
	}
	return false;
}

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> F[i];
	}

	for (int t = 1; t <= (int)sqrt((double)n); t++)
	{
		if (n % t)
			continue;
		if (check(t) || check(n / t))
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}