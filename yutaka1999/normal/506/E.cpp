#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#include <functional>
#define SIZE 205
#define MX 805
#define MOD 10007
#define BT 30

using namespace std;

int dp[SIZE][SIZE][SIZE];
int way[MX][MX][BT],wt[2][2*SIZE];
int id[2*SIZE];
char str[SIZE];

void memo(int t,int m)
{
	if(t==0)
	{
		for(int i=0;i<4*m;i++)
		{
			for(int j=0;j<4*m;j++)
			{
				if(i>j||(i>=2*m&&i!=j)||(i<2*m&&j>=2*m&&i>j-2*m)) way[i][j][t]=0;
				if(j>=2*m) way[i][j][t]=26;
				else if(j>=m) way[i][j][t]=25;
				else way[i][j][t]=24;
			}
		}
		return;
	}
	memo(t-1,m);
	for(int i=0;i<4*m;i++)
	{
		for(int j=i;j<4*m;j++)
		{
			if(i>=2*m)
			{
				if(i!=j) continue;
				way[i][j][t]=way[i][j][t-1]*way[i][j][t-1]%MOD;
			}
			else
			{
				int to=j;
				if(j>=2*m)
				{
					way[i][j][t]=way[i][j][t-1]*way[j][j][t-1]%MOD;
					to-=2*m;
				}
				if(to-i+1>m||i>m+m/2) continue;
				for(int k=i;k<=to;k++)
				{
					way[i][j][t]+=way[i][k][t-1]*way[k][j][t-1]%MOD;
					if(way[i][j][t]>=MOD) way[i][j][t]-=MOD;
				}
			}
		}
	}
	return;
}
int main()
{
	scanf("%s",&str);
	int n;
	scanf("%d",&n);
	int m=strlen(str);
	dp[0][m-1][0]=1;
	for(int i=0;i<m;i++)
	{
		for(int j=m;j>i;j--)
		{
			for(int k=0;k<=m;k++)
			{
				if(dp[i][j][k]==0) continue;
				if(str[i]==str[j])
				{
					dp[i+1][j-1][k+1]+=dp[i][j][k];
					if(dp[i+1][j-1][k+1]>=MOD) dp[i+1][j-1][k+1]%=MOD;
				}
				else
				{
					dp[i+1][j][k]+=dp[i][j][k];
					if(dp[i+1][j][k]>=MOD) dp[i+1][j][k]-=MOD;
					dp[i][j-1][k]+=dp[i][j][k];
					if(dp[i][j-1][k]>=MOD) dp[i][j-1][k]-=MOD;
				}
			}
		}
	}
	memo(BT-1,m);
	int ret=0;
	if((n+m)%2==0)
	{
		for(int i=0;i<m;i++)
		{
			int sum=0;
			for(int j=1;j<m;j++)
			{
				sum+=dp[j][j-1][i];
				if(sum>=MOD) sum-=MOD;
			}
			if(sum==0) continue;
			int a=m-2*i,b=i,Z=(n-a)/2;
			if(n-a<0) continue;
			int sz=0;
			for(int j=m-a;j<m+b;j++) id[sz++]=j;
			id[sz++]=3*m+b-1;
			int pos=0;
			memset(wt[pos],0,sizeof(wt[pos]));
			wt[pos][0]=1;
			for(int j=BT-1;j>=0;j--)
			{
				if(Z>>j&1)
				{
					pos^=1;
					memset(wt[pos],0,sizeof(wt[pos]));
					for(int k=0;k<sz;k++)
					{
						if(wt[pos^1][k]==0) continue;
						for(int p=k;p<sz;p++)
						{
							wt[pos][p]+=wt[pos^1][k]*way[id[k]][id[p]][j]%MOD;
							if(wt[pos][p]>=MOD) wt[pos][p]-=MOD;
						}
					}
				}
			}
			for(int j=0;j<sz;j++)
			{
				ret+=wt[pos][j]*sum%MOD;
				if(ret>=MOD) ret-=MOD;
			}
		}
	}
	else
	{
		for(int i=0;i<m;i++)
		{
			int sum=0;
			for(int j=1;j<m;j++)
			{
				sum+=dp[j][j-1][i];
				if(sum>=MOD) sum-=MOD;
			}
			if(sum==0) continue;
			int a=m-2*i,b=i,Z=(n-a-1)/2;
			if(n-a-1<0) continue;
			int sz=0;
			for(int j=m-a;j<m+b;j++) id[sz++]=j;
			id[sz++]=3*m+b-1;
			int pos=0;
			memset(wt[pos],0,sizeof(wt[pos]));
			wt[pos][0]=1;
			for(int j=BT-1;j>=0;j--)
			{
				if(Z>>j&1)
				{
					pos^=1;
					memset(wt[pos],0,sizeof(wt[pos]));
					for(int k=0;k<sz;k++)
					{
						if(wt[pos^1][k]==0) continue;
						for(int p=k;p<sz;p++)
						{
							wt[pos][p]+=wt[pos^1][k]*way[id[k]][id[p]][j]%MOD;
							if(wt[pos][p]>=MOD) wt[pos][p]-=MOD;
						}
					}
				}
			}
			for(int j=0;j<sz;j++)
			{
				ret+=wt[pos][j]*sum%MOD*26%MOD;
				if(ret>=MOD) ret-=MOD;
			}
		}
	}
	if((n+m)%2==0)
	{
		for(int i=0;i<m;i++)
		{
			int sum=0;
			for(int j=0;j<m;j++)
			{
				sum+=dp[j][j][i];
				if(sum>=MOD) sum-=MOD;
			}
			if(sum==0) continue;
			int a=m-2*i-1,b=i+1,Z=(n-a-1)/2;
			if(n-a-1<0) continue;
			int sz=0;
			for(int j=m-a;j<m+b;j++) id[sz++]=j;
			id[sz++]=3*m+b-1;
			int pos=0;
			memset(wt[pos],0,sizeof(wt[pos]));
			wt[pos][0]=1;
			for(int j=BT-1;j>=0;j--)
			{
				if(Z>>j&1)
				{
					pos^=1;
					memset(wt[pos],0,sizeof(wt[pos]));
					for(int k=0;k<sz;k++)
					{
						if(wt[pos^1][k]==0) continue;
						for(int p=k;p<sz;p++)
						{
							wt[pos][p]+=wt[pos^1][k]*way[id[k]][id[p]][j]%MOD;
							if(wt[pos][p]>=MOD) wt[pos][p]-=MOD;
						}
					}
				}
			}
			for(int j=0;j<sz;j++)
			{
				ret+=wt[pos][j]*sum%MOD;
				if(ret>=MOD) ret-=MOD;
			}
		}
	}
	else
	{
		for(int i=0;i<m;i++)
		{
			int sum=0;
			for(int j=0;j<m;j++)
			{
				sum+=dp[j][j][i];
				if(sum>=MOD) sum-=MOD;
			}
			if(sum==0) continue;
			int a=m-2*i-1,b=i+1,Z=(n-a-2)/2;
			if(n-a-2<0) continue;
			int sz=0;
			for(int j=m-a;j<m+b;j++) id[sz++]=j;
			id[sz++]=3*m+b-1;
			int pos=0;
			memset(wt[pos],0,sizeof(wt[pos]));
			wt[pos][0]=1;
			for(int j=BT-1;j>=0;j--)
			{
				if(Z>>j&1)
				{
					pos^=1;
					memset(wt[pos],0,sizeof(wt[pos]));
					for(int k=0;k<sz;k++)
					{
						if(wt[pos^1][k]==0) continue;
						for(int p=k;p<sz;p++)
						{
							wt[pos][p]+=wt[pos^1][k]*way[id[k]][id[p]][j]%MOD;
							if(wt[pos][p]>=MOD) wt[pos][p]-=MOD;
						}
					}
				}
			}
			for(int j=0;j<sz;j++)
			{
				ret+=wt[pos][j]*sum%MOD*26%MOD;
				if(ret>=MOD) ret-=MOD;
			}
		}
		for(int i=0;i<m;i++)
		{
			int sum=0;
			for(int j=0;j<m;j++)
			{
				sum+=dp[j][j][i];
				if(sum>=MOD) sum-=MOD;
			}
			if(sum==0) continue;
			int a=m-2*i-1,b=i+1,Z=(n-a)/2;
			if(n-a<0) continue;
			int sz=0;
			for(int j=m-a;j<m+b;j++) id[sz++]=j;
			int pos=0;
			memset(wt[pos],0,sizeof(wt[pos]));
			wt[pos][0]=1;
			for(int j=BT-1;j>=0;j--)
			{
				if(Z>>j&1)
				{
					pos^=1;
					memset(wt[pos],0,sizeof(wt[pos]));
					for(int k=0;k<sz;k++)
					{
						if(wt[pos^1][k]==0) continue;
						for(int p=k;p<sz;p++)
						{
							wt[pos][p]+=wt[pos^1][k]*way[id[k]][id[p]][j]%MOD;
							if(wt[pos][p]>=MOD) wt[pos][p]-=MOD;
						}
					}
				}
			}
			for(int j=0;j<sz;j++)
			{
				ret+=wt[pos][j]*sum%MOD;
				if(ret>=MOD) ret-=MOD;
			}
		}
	}
	printf("%d\n",ret);
	return 0;
}