#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PQ priority_queue
#define OO 2147483647
#define ll long long

using namespace std;

ll n, m, i, l, r, mid, a[100005], b[100005];
int Check(ll mid);

int main()
{
	cin >> n >> m;
	for (i = 1; i <= n; i++)
		cin >> a[i];
	for (i = 1; i<= m; i++)
		cin >> b[i];
	l = 0, r = (1LL << 60);
	while (l < r)
	{
		mid = ((l + r) >> 1);
		if (Check(mid) == 1)
			r = mid;
		else
			l = mid + 1;
	}
	
	cout << l << endl;
	return 0;
}

int Check(ll mid)
{
	int i, j, k;
	j = 1;
	for (i = 1; i <= n; i++)
	{
		if (abs(a[i] - b[j]) > mid)
			continue;
		for (k = j + 1; k <= m; k++)
			if (b[k] - b[j] + min(abs(a[i] - b[j]), abs(a[i] - b[k])) > mid)
				break;
		j = k;
		if (j > m)
			break;
	}
	
	if (j > m)
		return 1;
	return 0;
}