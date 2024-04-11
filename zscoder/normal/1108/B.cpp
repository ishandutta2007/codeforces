#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

map<int,int> cnt;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; cnt[x]++;
	}
	for(int i=1;i<=10000;i++)
	{
		if(cnt[i]>0)
		{
			map<int,int> C = cnt;
			vi D;
			for(int j=1;j*j<=i;j++)
			{
				if(i%j==0)
				{
					D.pb(j);
					if(j*j!=i) D.pb(i/j);
				}
			}
			bool pos=1;
			for(int v:D)
			{
				if(C[v]==0){pos=0; break;}
				C[v]--;
			}
			if(!pos) continue;
			int mx=-1;
			for(auto x:C)
			{
				if(x.se>0)
				{
					mx=max(mx,x.fi);
				}
			}
			if(mx<=0) continue;
			D.clear();
			for(int j=1;j*j<=mx;j++)
			{
				if(mx%j==0)
				{
					D.pb(j);
					if(j*j!=mx) D.pb(mx/j);
				}
			}
			for(int v:D)
			{
				if(C[v]==0){pos=0; break;}
				C[v]--;
			}
			for(auto x:C)
			{
				if(x.se>0)
				{
					pos=0; break;
				}
			}
			if(pos)
			{
				cout<<i<<' '<<mx<<'\n'; return 0;
			}
		}
	}
}