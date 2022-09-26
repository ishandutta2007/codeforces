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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

ii a[11111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].fi>>a[i].se;
	}
	while(1)
	{
		vi F[2];
		for(int i=0;i<n;i++)
		{
			int s=a[i].fi+a[i].se;
			F[abs(s)%2].pb(i);
		}
		if(F[0].empty()||F[1].empty())
		{
			for(int i=0;i<n;i++)
			{
				ii tmp = mp(a[i].fi+a[i].se,a[i].fi-a[i].se);
				if(abs(tmp.fi)%2==1)
				{
					tmp.fi++; tmp.se++;
				}
				tmp.fi/=2; tmp.se/=2;
				a[i]=tmp;
			}
		}
		else
		{
			cout<<F[0].size()<<'\n';
			for(int x:F[0])
			{
				cout<<x+1<<' ';
			}
			cout<<'\n';
			return 0;
		}
	}
}