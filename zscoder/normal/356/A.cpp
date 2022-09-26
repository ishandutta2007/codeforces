#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fbo find_by_order
#define ook order_of_key

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int nxt[300010];
int ans[300001];

int rt(int u)
{
	if(nxt[u] == u) return u;
	else return (nxt[u] = rt(nxt[u]));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	for(int i = 0; i <= n + 1; i++)
	{
		nxt[i] = i;
	}
	for(int i = 0; i < m; i++)
	{
		int l, r, w; cin >> l >> r >> w;
		int p = rt(l);
		//cerr << i << ' ' << p << '\n';
		for(;p <= r;)
		{
			int tmp = rt(p+1);
			if(p < w)
			{
				nxt[p] = nxt[w];
				ans[p] = w;
			}
			else if(p > w)
			{
				nxt[p] = nxt[r+1];
				ans[p] = w;
			}
			p = tmp;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << ans[i] << ' ';
	}
}