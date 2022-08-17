#include <iostream>
using namespace std;

const int N = 10050;

typedef long long llong;

llong A[N];

int main()
{
	llong n, m, k;
	cin >> n >> m >> k;
	if (n % 2 == 0)
		cout << 0;
	else
	{
		llong mn = 1e9;
		for (int i = 0; i < n; i++)
		{
			cin >> A[i];
			if (i % 2 == 0)
				mn = min(mn, A[i]);
		}
		llong x = (1 + n / 2);
		llong u = (m / x);
		cout << min(u * k, mn);
	}
}