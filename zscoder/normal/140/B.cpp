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
typedef vector<ll> vi;
typedef long double ld; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int ans[333];
int rnk[333][333];
int a[333];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int cnt=0;
		vi vec;
		for(int j=0;j<n;j++)
		{
			int x; cin>>x; x--; vec.pb(x);
			if(x==i) continue;
			rnk[i][x]=cnt; cnt++;
		}
		rnk[i][i]=cnt;
	}
	vi vec;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; x--; a[x]=i;
		vec.pb(x);
	}
	int curbest=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<a[curbest])
		{
			curbest=i;
		}
		for(int j=0;j<n;j++)
		{
			if(j==curbest)
			{
				int curbest2=-1;
				for(int k=0;k<n;k++)
				{
					if(vec[k]!=j&&vec[k]<=i)
					{
						curbest2=vec[k]; break;
					}
				}
				//cerr<<"CURBEST2 = "<<curbest2<<' '<<ans[j]<<' '<<rnk[j][curbest2]<<' '<<rnk[j][ans[j]]<<'\n';
				if(curbest2!=-1&&rnk[j][curbest2]<rnk[j][ans[j]]) ans[j]=curbest2;
			}
			else
			{
				if(rnk[j][curbest]<rnk[j][ans[j]]) ans[j]=curbest;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]+1;
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
}