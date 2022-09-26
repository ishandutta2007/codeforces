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
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int ma[16111111];
const int MX = int(1e7)+int(5e6)+1;
bool vis[MX+1];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<int> vec;
	for(int i=0;i<n;i++)
	{
		int x; cin>>x; vec.pb(x); 
	}
	int gd=vec[0]; int mx=0;
	for(int i=1;i<n;i++) gd=__gcd(gd,vec[i]);
	for(int i=0;i<n;i++) {vec[i]/=gd; ma[vec[i]]++; mx=max(mx,vec[i]);}
	int ans=0;
	for(int i=2;i<=MX;i++)
	{
		if(vis[i]) continue;
		int res=0;
		for(int j=i;j<=MX;j+=i)
		{
			vis[j]=1;
			res+=ma[j];
		}
		ans=max(ans,res);
	}
	if(ans>=2) cout<<n-ans<<'\n';
	else if(ans==1&&mx>0) cout<<n-1<<'\n';
	else cout<<-1<<'\n';
}