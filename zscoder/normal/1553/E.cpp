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
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef set<ll>::iterator sit;
typedef map<ll,ll>::iterator mit;

int singletons[333333];
bool vis[333333];
void solve()
{
	int n,m; cin>>n>>m;
	vi a(n);
	for(int i=0;i<=n+10;i++) singletons[i]=0;
	//if shift i, what is the number of singletons?
	for(int i=0;i<n;i++) 
	{
		cin>>a[i]; a[i]--;
		//compute the time where a[i] appears in position i
		//(a[i]+t = i) mod n
		int t = (i-a[i]);
		while(t>=n) t-=n;
		while(t<0) t+=n;
		singletons[t]++;
	}
	vi ans;
	for(int i=0;i<n;i++)
	{
		if(singletons[i]<n/9) continue;
		for(int j=0;j<n;j++)
		{
			vis[j]=0;
		}
		int cc=0;
		for(int j=0;j<n;j++)
		{
			if(!vis[j])
			{
				cc++;
				int cur=j;
				while(!vis[cur])
				{
					vis[cur]=1;
					cur=a[(cur+i)%n];
				}
			}
		}
		if(cc>=n-m)
		{
			ans.pb(i);
		}
	}
	cout<<ans.size()<<' ';
	for(int v:ans) cout<<v<<' ';
	cout<<'\n';
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}