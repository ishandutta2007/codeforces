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
typedef double ld; 
typedef pair<ld,ld> state;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[111111][2];
int best[111111][2];
const int INF = int(1e8);

void amax(int &x, int y)
{
	x=max(x,y);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	vector<int> a(n);
	vector<int> b;
	for(int i=0;i<n;i++) 
	{
		cin>>a[i];
		if(i==0||(i>0&&a[i]!=a[i-1]))
		{
			b.pb(a[i]);
		}
	}
	a=b;
	a.pb(n+2);
	n=b.size();
	for(int i=0;i<=n+5;i++)
	{
		for(int j=0;j<2;j++) dp[i][j]=best[i][j]=-INF;
	}
	for(int i=0;i<n;i++)
	{
		dp[i][0]=0;
	}
	int C[2] = {-INF,-INF};
	for(int i=0;i<n;i++)
	{
		//compute dp[i][0,1]
		//loop through all 1<=j<=i to form segment [j,i]
		amax(dp[i][0],max(C[1]+1,C[0]));
		//do dp[i][1]'s case now
		amax(dp[i][1],max(best[a[i+1]][1]+1,best[a[i+1]][0]));
		amax(C[0],dp[i][0]);
		amax(C[1],dp[i][1]);
		amax(best[a[i]][0],dp[i][0]);
		amax(best[a[i]][1],dp[i][1]);
	}
	int ans = max(dp[n-1][0],dp[n-1][1]);
	cout<<n-ans<<'\n';
}