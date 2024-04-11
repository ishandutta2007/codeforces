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

int dp[222222];
int a[11][111111];
int pos[11][111111];
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m; 
	cin>>n>>m;
	//n=100000;m=10;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a[i][j]; 
			//a[i][j]=j+1;
			a[i][j]--; pos[i][a[i][j]]=j;
		}
	}
	ll ans=0;
	for(int i=0;i<n;i++)
	{
		vi P(m,0);
		for(int j=0;j<m;j++) P[j]=pos[j][i];
		vector<int> V; int ext=0;
		while(1)
		{
			bool pos=1;
			int eq=-1;
			for(int j=0;j<m;j++)
			{
				if(P[j]>=n){pos=0; break;}
				if(eq!=-1&&a[j][P[j]]!=eq){pos=0; break;}
				eq=a[j][P[j]]; P[j]++;
			}
			if(!pos) break;
			if(dp[eq]>0){ext=dp[eq]; break;}
			V.pb(eq);
		}
		ext+=V.size();
		for(int i=0;i<V.size();i++)
		{
			dp[V[i]]=ext;
			ext--;
		}
		ans+=dp[i];
	}
	cout<<ans<<'\n';
}