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
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[222222];
int b[222222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	ll sum = 0;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; sum+=a[i];
	}
	ll m = 0;
	int q; cin>>q;
	ll ext=0;
	map<ii,int> S;
	for(int i=0;i<q;i++)
	{
		int s,t,u; cin>>s>>t>>u;
		s--; u--;
		if(S.find({s,t})==S.end())
		{
			b[u]++;
			if(b[u]>a[u])
			{
				ext++;
			}
			S[{s,t}]=u;
			m++;
		}
		else
		{
			int v=S[{s,t}];
			b[v]--;
			if(b[v]>=a[v])
			{
				ext--;
			}
			S.erase({s,t});
			m--;
			if(u>=0)
			{
				S[{s,t}]=u;
				b[u]++;
				if(b[u]>a[u]) ext++;
				m++;
			}
		}
		//cerr<<m<<' '<<ext<<'\n';
		cout<<sum-m+ext<<'\n';
	}
}