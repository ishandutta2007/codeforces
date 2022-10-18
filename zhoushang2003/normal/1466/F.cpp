#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MOD = 1000000007;

int n , m;
int fa[500010];
int f[500010];

vector <int> v; 

int find(int x)
{
	if(fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

void connect(int x , int y)
{
	int tx = find(x) , ty = find(y);
	f[ty] |= f[tx];
	fa[fa[tx]] = fa[ty];
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i++)
		fa[i] = i;
	ll ans = 1;
	for(int i = 1; i <= n; i++)
	{
		int k , x , y;
		cin >> k;
		if(k == 1)
		{
			cin >> x;
			int t = find(x);
			if(f[t] == 0)
			{
				ans = ans * 2 % MOD;
				f[t] = 1;
				v.push_back(i);
			}
		}
		else
		{
			cin >> x >> y;
			int tx = find(x) , ty = find(y);
			if(tx != ty && f[tx] + f[ty] != 2)
			{
				ans = ans * 2 % MOD;
				connect(tx , ty);
				v.push_back(i);
			}
		}
	}
	cout << ans << " " << v.size() << endl;
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}