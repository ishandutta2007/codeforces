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

ll a[2222];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> ans;
	for(int k=1;k<=n;k++)
	{
		vector<int> x;
		for(int i=1;i<=k;i++)
		{
			x.pb(a[i]-a[i-1]);
		}
		vector<ll> A;
		A.pb(0);
		for(int i=1;i<=n;i++)
		{
			A.pb(A.back()+x[(i-1)%k]);
		}
		bool pos=1;
		for(int i=0;i<=n;i++)
		{
			if(a[i]!=A[i]){pos=0; break;}
		}
		if(pos) ans.pb(k);
	}
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(i+1<ans.size()) cout<<' ';
	}
	cout<<'\n';
}