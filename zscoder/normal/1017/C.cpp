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

void solve(int n, int C)
{
	vi vec;
	for(int i=1;i<=n;i+=C)
	{
		int l=i; int r=min(n,i+C-1);
		for(int j=r;j>=l;j--)
		{
			vec.pb(j);
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<vec[i];
		if(i+1<n) cout<<' ';
	}
	cout<<'\n';
	return ;
}

int calc(int n, int C)
{
	return C+(n+C-1)/C;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	int best=int(1e9); int idx=0;
	for(int i=1;i<=n;i++)
	{
		if(calc(n,i)<best)
		{
			best=calc(n,i); idx=i;
		}
	}
	solve(n,idx);
}