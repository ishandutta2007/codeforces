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

int a[120];
int cnt[(1<<12)+1];
const int C = 102;
int dp[(1<<12)+1][C+11];
int V[(1<<12)+1];

int main()
{
	int n,m,q; scanf("%d %d %d",&n,&m,&q);
	for(int i=n-1;i>=0;i--)
	{
		scanf("%d",a+i);
	}
	for(int i=0;i<m;i++)
	{
		char s[15];
		scanf("%s",s);
		int cur=0;
		for(int j=0;j<n;j++)
		{
			cur<<=1; 
			if(s[j]=='1') cur++;
		}
		cnt[cur]++;
		//cerr<<cur<<'\n';
	}
	for(int i=0;i<(1<<n);i++)
	{
		int s=0;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)) s+=a[j];
		}
		V[i] = min(s,C);
	}
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<(1<<n);j++)
		{
			//cerr<<i<<' '<<j<<' '<<V[i^j]<<' '<<cnt[j]<<'\n';
			dp[i][V[i^j]]+=cnt[j];
		}
		for(int j=1;j<=C;j++)
		{
			dp[i][j]+=dp[i][j-1];
		}
	}
	for(int i=0;i<q;i++)
	{
		char s[15]; scanf("%s",s); int k; scanf("%d",&k);
		int cur=0;
		for(int j=0;j<n;j++)
		{
			cur<<=1; 
			if(s[j]=='1') cur++;
		}
		cur=((1<<n)-1)^cur;
		printf("%d\n", dp[cur][k]);
	}
}