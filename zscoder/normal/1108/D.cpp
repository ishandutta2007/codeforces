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
typedef pair<ll,ll> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

char C[3]={'R','G','B'};
int dp[222222][3];
int par[222222][3];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	string s; cin>>s;
	map<char,int> ma;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<3;j++) dp[i][j]=int(1e9);
	}
	for(int i=0;i<3;i++) ma[C[i]]=i;
	for(int i=0;i<3;i++)
	{
		par[0][i]=-1;
		dp[0][i]=(s[0]!=C[i]);
	}
	for(int i=0;i+1<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				if(j!=k)
				{
					int nw = dp[i][j]+(s[i+1]!=C[k]);
					if(dp[i+1][k]>nw)
					{
						dp[i+1][k]=nw;par[i+1][k]=j;
					}
				}
			}
		}
	}
	int cur=-1; int mn=int(1e9);
	for(int i=0;i<3;i++)
	{
		if(dp[n-1][i]<mn)
		{
			mn=dp[n-1][i]; cur=i;
		}
	}
	cout<<mn<<'\n';
	string S; int i=n-1;
	while(cur!=-1)
	{
		S+=C[cur]; 
		cur=par[i][cur];
		i--;
	}
	reverse(S.begin(),S.end());
	cout<<S<<'\n';
}