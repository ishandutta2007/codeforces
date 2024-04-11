#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5;
int n,x,A,mx,ct[N];
pair<int,int>p[N];
signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> x, p[x].second = i;
		if(!p[x].first)
			p[x].first = i;
	}
	sort (p + 1, p + N);
	for (int i = 1; i <= N; i++) {
		if (!p[i].first) continue;
		if (p[i].first == p[i].second) {
			A++;
			continue;
		}
		A += 2, mx = p[i].second;
		while (i + 1 < N) {
			if (p[i + 1].first > mx) break;
			int tmp = mx;
			while (i + 1 < N && p[i + 1].first <= tmp)
				++i, mx = max(mx, p[i].second);
			if (mx > tmp) A++;
		}
	}
	cout << n - A << endl;
	return 0;
}