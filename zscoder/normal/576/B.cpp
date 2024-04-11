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

bool visited[100001];
int p[100001];
int color[100001];
vector<int> pts[2];

bool dfs(int u, int col)
{
	color[u] = col; pts[col].pb(u); visited[u] = true;
	if(!visited[p[u]])
	{
		return dfs(p[u], (col^1));
	}
	else if(color[p[u]] == color[u])
	{
		return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i =	0; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
	}
	int idx = -1; int idx2 = -1;
	for(int i = 0; i < n; i++)
	{
		if(p[i] == i)
		{
			idx = i; break;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(p[p[i]] == i)
		{
			idx2 = i; break;
		}
	}
	if(idx == -1 && idx2 == -1)
	{
		cout<<"NO"; return 0;
	}
	if(idx != -1)
	{
		cout << "YES\n";
		for(int i = 0; i < n; i++)
		{
			if(i != idx)
			{
				cout << i + 1 << ' ' << idx + 1 << '\n';
			}
		}
		return 0;
	}
	int u = idx2; int v = p[idx2];
	for(int i = 0; i < n; i++)
	{
		if(i == u || i == v) continue;
		if(!visited[i])
		{
			bool cur = dfs(i, 0);
			if(!cur){cout<<"NO"; return 0;}
		}
	}
	cout << "YES\n";
	cout << u+1 << ' ' << v+1 << '\n';
	for(int i = 0; i < pts[0].size(); i++)
	{
		cout << u+1 << ' ' << pts[0][i]+1 << '\n';
	}
	for(int i = 0; i < pts[1].size(); i++)
	{
		cout << v+1 << ' ' << pts[1][i]+1 << '\n';
	}
}