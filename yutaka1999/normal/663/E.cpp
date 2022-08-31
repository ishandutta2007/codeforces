#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 25
#define MX 100005
#define ALL (1<<21)
#define CT 13
#define BT (1<<9)

using namespace std;

int bit[MX],cnt[ALL];
int dp[BT][SIZE];
int rt[BT][SIZE];
char str[MX];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		for(int j=0;j<m;j++) if(str[j]=='1') bit[j]|=1<<i;
	}
	cnt[0]=0;
	for(int S=1;S<ALL;S++)
	{
		int T=S&(S-1);
		cnt[S]=cnt[T]+1;
	}
	int st=min(n,CT);
	int zan=n-st;
	int lim=n/2;
	int ret=n*m;
	for(int S=0;S<1<<st;S++)
	{
		memset(dp,0,sizeof(dp));
		for(int i=0;i<m;i++)
		{
			int s=bit[i]>>st;
			int t=bit[i]-(s<<st);
			t^=S;
			dp[s][cnt[t]]++;
		}
		for(int i=0;i<1<<zan;i++)
		{
			for(int j=1;j<=st;j++)
			{
				rt[i][j]=dp[i][j]*j;
				dp[i][j]+=dp[i][j-1];
				rt[i][j]+=rt[i][j-1];
			}
		}
		for(int T=0;T<1<<zan;T++)
		{
			int sum=0;
			for(int i=0;i<1<<zan;i++)
			{
				int ft=i^T;
				ft=cnt[ft];
				//ft+x<=lim <=> x<=lim-ft  
				//ft+x>lim <=> x>=lim-ft+1  n-hoge
				sum+=(n-ft)*dp[i][st]-rt[i][st];
				if(ft<=lim) sum+=(2*ft-n)*dp[i][lim-ft]+2*rt[i][lim-ft];
			}
			//printf("%d %d : %d\n",S,T,sum);
			ret=min(ret,sum);
		}
	}
	printf("%d\n",ret);
	return 0;
}