#include <iostream>
#include <cstdio>
using namespace std;

//#define TASK ""

const int N = 1050;

int B[N];
int A[N];

int main(int argc, char **argv)
{
#ifdef TASK
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
#endif
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> B[i];
	int pt = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (B[j] == 0)
			{
				B[j] = -1;
				A[i] = j;
				for (int t = 1; t <= n; t++)
					if (t <= j - k)
						B[t]--;
				goto nexti;
			}
		}
		cout << 1 / (min(0, i));
		nexti:;
	}
	for (int i = 1; i <= n; i++)
		cout << A[i] << ' ';
	return 0;
}