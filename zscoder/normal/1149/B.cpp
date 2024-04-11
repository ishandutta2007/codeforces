#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int dp[252][252][252];
string s;
int len[3] = {0,0,0};
int n,q; 
int nxt[111111][27];
const int INF = int(1e9);

int N(int x, char c)
{
	if(x>=n-1) return INF;
	return nxt[x+1][c-'a'];
}

void amin(int &x, int y)
{
	if(y<x) x=y;
}

string ss[3];

void add_char(int p, char c)
{
	len[p]++; ss[p]+=c;
	if(p==0)
	{
		for(int i=0;i<=len[1];i++)
		{
			for(int j=0;j<=len[2];j++)
			{
				dp[len[0]][i][j]=INF;
			}
		}
		for(int i=0;i<=len[1];i++)
		{
			for(int j=0;j<=len[2];j++)
			{
				amin(dp[len[0]][i][j],N(dp[len[0]-1][i][j],ss[0][len[0]-1]));
				if(i) amin(dp[len[0]][i][j],N(dp[len[0]][i-1][j],ss[1][i-1]));
				if(j) amin(dp[len[0]][i][j],N(dp[len[0]][i][j-1],ss[2][j-1]));
				//cerr<<i<<' '<<j<<' '<<dp[len[0]][i][j]<<'\n';
			}
		}
	}
	else if(p==1)
	{
		for(int i=0;i<=len[0];i++)
		{
			for(int j=0;j<=len[2];j++)
			{
				dp[i][len[1]][j]=INF;
			}
		}
		for(int i=0;i<=len[0];i++)
		{
			for(int j=0;j<=len[2];j++)
			{
				amin(dp[i][len[1]][j],N(dp[i][len[1]-1][j],ss[1][len[1]-1]));
				if(i) amin(dp[i][len[1]][j],N(dp[i-1][len[1]][j],ss[0][i-1]));
				if(j) amin(dp[i][len[1]][j],N(dp[i][len[1]][j-1],ss[2][j-1]));
				//cerr<<i<<' '<<j<<' '<<dp[i][len[1]][j]<<'\n';
			}
		}
	}
	else
	{
		for(int i=0;i<=len[0];i++)
		{
			for(int j=0;j<=len[1];j++)
			{
				dp[i][j][len[2]]=INF;
			}
		}
		for(int i=0;i<=len[0];i++)
		{
			for(int j=0;j<=len[1];j++)
			{
				amin(dp[i][j][len[2]],N(dp[i][j][len[2]-1],ss[2][len[2]-1]));
				if(i) amin(dp[i][j][len[2]],N(dp[i-1][j][len[2]],ss[0][i-1]));
				if(j) amin(dp[i][j][len[2]],N(dp[i][j-1][len[2]],ss[1][j-1]));
				//cerr<<i<<' '<<j<<' '<<dp[i][j][len[2]]<<'\n';
			}
		}
	}	
}

void del_char(int p)
{
	len[p]--; ss[p]=ss[p].substr(0,len[p]);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>n>>q;
	cin>>s;
	for(int i=0;i<251;i++)
	{
		for(int j=0;j<251;j++)
		{
			for(int k=0;k<251;k++)
			{
				dp[i][j][k]=INF;
			}
		}
	}
	dp[0][0][0]=-1;
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<26;j++) nxt[i][j]=n;
		if(i<n-1) for(int j=0;j<26;j++) nxt[i][j]=nxt[i+1][j];
		nxt[i][s[i]-'a']=i;
	}
	for(int i=0;i<q;i++)
	{
		char c; cin>>c;
		int p; cin>>p;p--;
		if(c=='-')
		{
			del_char(p);
		}
		else
		{
			char x; cin>>x;
			add_char(p,x);
		}
		if(dp[len[0]][len[1]][len[2]]<n) cout<<"YES\n";
		else cout<<"NO\n";
	}
}