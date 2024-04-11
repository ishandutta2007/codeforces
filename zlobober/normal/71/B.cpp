#include <iostream>
#include <cstdio>
using namespace std;

//#define TASK ""

const int N = 1000;

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	int n, k, t;
	cin >> n >> k >> t;
	int A[N];
	int g;
	for (g = 0; g <= n * k; g++)
	{
		if (g * 100 <= t * n * k && t * n * k < (g + 1) * 100)
			break;
	}
	for (int i = 0; i < n; i++)
		A[i] = min(g, k), g -= A[i];
	for (int i = 0; i < n; i++)
		cout << A[i] << ' ';
	return 0;
}