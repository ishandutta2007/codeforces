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

int a[2111];
struct node
{
	int ans,ans2,a,b;
};

node combine(node a, node b)
{
	node c;
	c.a=a.a+b.a; c.b=a.b+b.b;
	c.ans = max(a.a+b.ans, a.ans+b.b);
	c.ans2 = max(a.b+b.ans2, a.ans2+b.a);
	return c;
}

node rev(node a)
{
	swap(a.ans,a.ans2); return a;
}

node create(int a, int b)
{
	node c;
	c.ans=c.ans2=a+b;
	c.a=a; c.b=b;
	return c;
}

node dp[2011][2011];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int ans = 0;
	for(int i=0;i<n;i++)
	{
		node cur;
		cur.a = 0; cur.b = 0; cur.ans = 0; cur.ans2 = 0;
		for(int j=i;j<n;j++)
		{
			if(a[j]==1) cur = combine(cur, create(1,0));
			else cur = combine(cur,create(0,1));
			dp[i][j] = cur;
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			node L = create(0,0); node R = create(0,0);
			node mid = rev(dp[i][j]);
			if(i-1>=0) L = dp[0][i-1];
			if(j+1<n) R = dp[j+1][n-1];
			L = combine(L,mid);
			L = combine(L,R);
			ans = max(ans, L.ans);
		}
	}
	cout<<ans<<'\n';
}