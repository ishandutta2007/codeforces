#include <cstdio>
#include <iostream>
using namespace std;

typedef long long llong;
                 
const int N = 100500;
llong A[N], B[N];

llong D[N];

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int pt = 0;
int S[N];

bool check(double d1, double d2, double d3, double b1, double b2, double b3)
{
	d2 -= d1;
	b2 -= b1;
	d3 -= d1;
	b3 -= b1;
	return d3 * b2 - b3 * d2 > 0;
}

int main()
{
	//freopen("02", "r", stdin);
	int n;
	scanf("%d", &n);
	int t;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		A[i] = t;
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &t);
		B[i] = t;
	}
	if (n == 1)
	{
		printf("%d\n", 0);
		return 0;
	}	

	S[pt++] = 0;

	for (int i = 1; i < n; i++)	
	{
		//D[i] = A[i] * B[0];
		//for (int j = i - 1; j >= 0; j--)
		//	D[i] = min(D[i], D[j] + B[j] * A[i]);
		//continue;
		int l = 0;
		int r = pt - 1;
		//eprintf("i = %d: ", i);
		//for (int j = 0; j < pt; j++)
		//	eprintf("%d ", S[j]);
	    //eprintf("\n");
		while (r - l >= 3)
		{
			int a = (l * 2 + r) / 3;
			int b = (l + 2 * r) / 3;
			if (D[S[a]] + B[S[a]] * A[i] < D[S[b]] + B[S[b]] * A[i])
				r = b;
			else
				l = a;	
		}
		llong ans = 1e18;
		for (int j = l; j <= r; j++)
			ans = min(ans, D[S[j]] + B[S[j]] * A[i]);
		D[i] = ans;
		while (pt != 0 && check(D[S[pt - 2]], D[S[pt - 1]], D[i], B[S[pt - 2]], B[S[pt - 1]], B[i]))
			pt--;
		S[pt++] = i;
		//eprintf("%I64d %I64d\n", D[i], B[i]);
		//eprintf("%d\n", D[i]);
		
	}
	cout << D[n - 1];
}