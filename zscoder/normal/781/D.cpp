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

const ll INF = ll(1e18);
const int C = 501;
bitset<C> a[62][2][C];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	int m; cin>>m;
	for(int i=0;i<62;i++)
	{
		for(int k=0;k<2;k++)
		{
			for(int j=0;j<C;j++)
			{
				a[i][k][j].reset();
			}
		}
	}
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		u--;v--;
		a[0][w][u][v]=1;
	}
	for(int i=1;i<=60;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<n;l++)
				{
					if(a[i-1][j][k][l]==1)
					{
						a[i][j][k]|=a[i-1][j^1][l];
					}
				}
			}
		}
	}
	bitset<C> cur;
	cur.reset();
	cur[0]=1;
	ll ans = 0;
	int mode = 0;
	for(int i = 60; i >= 0; i--)
	{
		bitset<C> nxt;
		nxt.reset();
		for(int j=0;j<n;j++)
		{
			if(cur[j]==1)
			{
				nxt|=a[i][mode][j];
			}
		}
		if(nxt.count()==0)
		{
			continue;
		}
		ans+=(1LL<<i);
		mode^=1;
		cur=nxt;
	}
	if(ans>INF) cout<<-1;
	else cout<<ans;
}