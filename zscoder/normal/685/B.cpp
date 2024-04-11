#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long double ld;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

int par[300001];
vi adj[300001];
int ans[300001];
int anstmp[300001];
int rootdp[300001];
int subdp[300001];
int subsize[300001];

void precalc(int u) //precompute subtree size
{
	subsize[u] = 1;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		precalc(v);
		subsize[u] += subsize[v];
	}
}

void dfs(int u)
{
	int bestsub = 0;
	for(int i = 0; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		dfs(v);
		bestsub = max(bestsub, subsize[v]);
	}
	rootdp[u] = bestsub;
	if(2*bestsub <= subsize[u])
	{
		subdp[u] = bestsub;
		ans[u] = u;
		anstmp[u] = u;
	}
	else
	{
		int bestcentroid = 1e9; int bestidx = -1;
		for(int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i];
			int pos = anstmp[v];
			int tmpval = rootdp[pos];
			int val = max(tmpval, subsize[u] - subsize[pos]);
			while(pos != v)
			{
				int p = par[pos];
				tmpval = rootdp[p];
				//cout << u << ' ' << v << ' ' << pos << ' ' << p << ' ' << tmpval << '\n';
				if(max(tmpval, subsize[u] - subsize[p]) <= val)
				{
					val = max(tmpval, subsize[u] - subsize[p]);
				}
				else
				{
					break;
				}
				pos = par[pos];
			}
			anstmp[v] = pos;
			//cout << u << ' ' << v << ' ' << pos << '\n';
			if(val < bestcentroid)
			{
				bestcentroid = val;
				bestidx = pos;
			}
		}
		subdp[u] = bestcentroid;
		ans[u] = bestidx;
		anstmp[u] = bestidx;
	}
}

int main()
{
	//ios_base::sync_with_stdio(0); cin.tie(0);
	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 0; i < n - 1; i++)
	{
		scanf("%d", &par[i+1]);
		par[i+1]--;
		adj[par[i+1]].pb(i + 1);
	}
	precalc(0);
	dfs(0);
	/*
	for(int i = 0; i < n; i++)
	{
		cout << i << ' ' << subsize[i] << '\n';
	}
	*/
	for(int i = 0; i < q; i++)
	{
		int x; scanf("%d", &x);
		x--;
		printf("%d\n", ans[x]+1);
	}
	return 0;
}