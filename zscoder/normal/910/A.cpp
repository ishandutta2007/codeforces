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
typedef set<int>::iterator sit;
typedef map<int,int>::iterator mit;
typedef vector<int>::iterator vit;

int dp[2001];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,d; cin>>n>>d;
	string s; cin>>s;
	dp[0] = 0;
	for(int i=1;i<=n;i++) dp[i]=int(1e9);
	for(int i=1;i<n;i++)
	{
		if(s[i]=='0') continue;
		for(int j=1;j<=d;j++)
		{
			if(i-j>=0)
			{
				dp[i] = min(dp[i], dp[i-j]+1);
			}
		}
	}
	if(dp[n-1]>=int(1e9)) dp[n-1]=-1;
	cout<<dp[n-1]<<'\n';
}