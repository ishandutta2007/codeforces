#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int T;
int x[N] , y[N];
int fa[N];

int find(int x)
{
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

int main()
{
	ios::sync_with_stdio(false); 
	cin >> T;
	while(T--)
	{
		int n , m;
		cin >> n >> m;
		for(int i = 1; i <= m; i++)
			cin >> x[i] >> y[i];
		for(int i = 1; i <= n; i++)
			fa[i] = i;
		int ans = 0;
		for(int i = 1; i<= m; i++)
			if(x[i] != y[i])
			{
				if(find(x[i]) != find(y[i]))
				{
					ans++;
					fa[fa[x[i]]] = fa[y[i]];
				}
				else
					ans += 2;
			}
		cout << ans << endl;
	}
	return 0;
}