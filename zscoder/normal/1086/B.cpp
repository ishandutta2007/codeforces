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
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int ct[111111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n; ll s; cin>>s;
	for(int i=0;i<n-1;i++)
	{
		int u,v; cin>>u>>v; u--; v--; ct[u]++; ct[v]++;
	}
	ll leaves=0;
	for(int i=0;i<n;i++)
	{
		if(ct[i]==1) leaves++;
	}
	cout<<fixed<<setprecision(15)<<ld(s)*ld(2)/ld(leaves)<<'\n';
}