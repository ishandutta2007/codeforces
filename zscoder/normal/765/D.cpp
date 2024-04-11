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

int f[100001];
int g[1000001];
int h[1000001];
vi inv[100001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>f[i];
		inv[f[i]].pb(i);
	}
	int m=0;
	for(int i = 1; i <= n; i++)
	{
		if(!inv[i].empty()) m++;
	}
	int z = 1;
	for(int i = 1; i <= n; i++)
	{
		if(!inv[i].empty())
		{
			bool pos=0;
			vi vec;
			for(int j = 0; j < inv[i].size(); j++)
			{
				vec.pb(inv[i][j]);
				if(inv[i][j]==i)
				{
					pos=1;
				}
			}
			if(!pos)
			{
				cout<<-1;
				return 0;
			}
			for(int j = 0; j < vec.size(); j++)
			{
				g[vec[j]] = z; 
			}
			h[z] = i;
			z++;
		}
	}
	cout<<m<<'\n';
	for(int i = 1; i <= n; i++)
	{
		cout<<g[i]<<' ';
	}
	cout<<'\n';
	for(int i = 1; i <= m; i++)
	{
		cout<<h[i]<<' ';
	}
	for(int i = 1; i <= n; i++)
	{
		assert(h[g[i]]==f[i]);
	}
	for(int i = 1; i <= m; i++)
	{
		assert(g[h[i]]==i);
	}
}