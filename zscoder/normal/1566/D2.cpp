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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int seated[111111];
int taken[555][555];
void solve()
{
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++) taken[i][j]=0;
	}
	for(int i=0;i<n*m;i++)
	{
		seated[i]=0;
	}
	map<int,vi> ma;
	for(int i=0;i<n*m;i++)
	{
		int x; cin>>x;
		ma[x].pb(i);
	}
	int l=0;
	const int C = int(1e7);
	for(auto x:ma)
	{
		vi pos = x.se;
		int r = l+pos.size()-1;
		vector<ii> seats;
		for(int j=l;j<=r;j++)
		{
			int rk = -1;
			if(l/m!=r/m)
			{
				if(j/m==l/m)
				{
					rk=C+j;
				}
				else if(j/m==r/m)
				{
					rk=-C*10+j;
				}
				else
				{
					rk=-C+j;
				}
			}
			else
			{
				rk=j;
			}
			seats.pb({rk,j});
			//seats.pb({j%m,j});
		}
		sort(seats.rbegin(),seats.rend());
		for(int i=0;i<pos.size();i++)
		{
			seated[pos[i]]=seats[i].se;
		}
		l+=pos.size();
	}
	ll ans=0;
	for(int i=0;i<n*m;i++)
	{
		int r = seated[i]/m; int c = seated[i]%m;
		for(int j=0;j<c;j++)
		{
			if(taken[r][j])
			{
				ans++;
			}
		}
		taken[r][c]=1;
	}
	cout<<ans<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}