#include<iostream>
#include<algorithm>
using namespace std;

int a[110];
int n;

int b[110];
int c[110];
int bp, cp;
int pre, nxt;

int pd(int x)
{
	pre = a[0], nxt = a[n - 1];
	bp = cp = 0;
	b[++bp] = a[0], c[++cp] = a[0];
	for (int i = 1; i < n - 1; i++)
	{
		if (b[bp] <= c[cp])
		{
			if (a[i] - b[bp] > x)return 0;
			else b[++bp] = a[i];
		}
		else
		{
			if (a[i] - c[cp] > x)return 0;
			else c[++cp] = a[i];
		}
	}
	if (nxt - b[bp] > x)return 0;
	if (nxt - c[cp] > x)return 0;
	return 1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	int l = 1, r = 1e9, mid;
	int ans = 0;
	while (l <= r)
	{
		mid = (l + r) / 2;
		if (pd(mid))
		{
			r = mid - 1;
			ans = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	pd(ans);
	for (int i = 1; i <= bp; i++)cout << b[i] << " ";
	cout << nxt << " ";
	for (int i = cp; i >= 2; i--)cout << c[i] << " ";
	cout << endl;
}