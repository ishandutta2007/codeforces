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
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int ans[211111];

void solve()
{
	int n,m; cin>>n>>m;
	vector<vi> a(m);
	map<int,int> ma;
	for(int i=0;i<m;i++)
	{
		int k; cin>>k;
		a[i].resize(k);
		for(int j=0;j<k;j++)
		{
			cin>>a[i][j];
		}
		if(k==1) 
		{
			ans[i]=a[i][0]; ma[a[i][0]]++;
		}
	}
	int thres = (m+1)/2;
	for(int i=0;i<m;i++)
	{
		if(a[i].size()==1) continue;
		for(int v:a[i])
		{
			if(ma[v]+1>thres) continue;
			ans[i]=v; ma[v]++; break;
		}
	}
	for(int i=0;i<=n;i++)
	{
		if(ma[i]>thres){cout<<"NO\n"; return ;}
	}
	cout<<"YES\n";
	for(int i=0;i<m;i++)
	{
		cout<<ans[i];
		if(i+1<m) cout<<' ';
	}
	cout<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--) solve();
}