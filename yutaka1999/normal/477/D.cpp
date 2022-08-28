#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 5005
#define MOD 1000000007
#define INF 1000000000

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
typedef pair <P,int> PP;

int way[SIZE][SIZE];
int dp[SIZE][SIZE];
int sa[SIZE],rnk[SIZE];
int lcp[SIZE],mn[SIZE];
PP pos[SIZE];
char str[SIZE];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	for(int i=n;i>=1;i--) str[i]=str[i-1];
	str[0]='0';
	n++;
	for(int i=0;i<n;i++) rnk[i]=str[i]-'0';
	for(int k=1;k<=n;k<<=1)
	{
		for(int i=0;i<n;i++)
		{
			pos[i]=PP(P(rnk[i],(i+k<n?rnk[i+k]:-1)),i);
		}
		sort(pos,pos+n);
		for(int i=0;i<n;)
		{
			int s=i;
			for(;i<n&&pos[i].first==pos[s].first;i++)
			{
				rnk[pos[i].second]=s;
			}
		}
	}
	for(int i=0;i<n;i++) sa[rnk[i]]=i;
	int H=0;
	for(int i=0;i<n;i++)
	{
		if(H>0) H--;
		if(rnk[i]==n-1) continue;
		int tg=sa[rnk[i]+1];
		while(tg+H<n&&i+H<n&&str[tg+H]==str[i+H]) H++;
		lcp[rnk[i]]=H;
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=2*n;
			way[i][j]=0;
		}
	}
	dp[0][1]=0;
	way[0][1]=1;
	for(int i=0;i<n-1;i++)
	{
		//printf("%d\n",i);
		//for(int j=1;j<=i+1;j++) printf("[%d %d] ",dp[i][j],way[i][j]);puts("");
		if(str[i+1]=='0') continue;
		int M=SIZE;
		for(int j=rnk[i+1]+1;j<n;j++)
		{
			M=min(M,lcp[j-1]);
			mn[sa[j]]=M;
		}
		M=SIZE;
		for(int j=rnk[i+1]-1;j>=0;j--)
		{
			M=min(M,lcp[j]);
			mn[sa[j]]=M;
		}
		M=SIZE;
		int cnt=0;
		for(int j=i+1;j<n;j++)
		{
			int len=j-i;
			if(i-len+1>=0&&(mn[i-len+1]>=len||(rnk[i-len+1]<rnk[i+1])))
			{
				if(M>dp[i][len]+1)
				{
					M=dp[i][len]+1;
				}
				cnt+=way[i][len];
				if(cnt>=MOD) cnt-=MOD;
			}
			if(dp[j][len]>M)
			{
				dp[j][len]=M;
			}
			way[j][len]+=cnt;
			if(way[j][len]>=MOD) way[j][len]-=MOD;
			if(i-len+1>=0&&mn[i-len+1]<len&&rnk[i-len+1]>rnk[i+1])
			{
				if(M>dp[i][len]+1)
				{
					M=dp[i][len]+1;
				}
				cnt+=way[i][len];
				if(cnt>=MOD) cnt-=MOD;
			}
			//if(i==0) printf("%d\n",cnt);
		}
	}
	int m=INF;
	int cnt=0;
	//printf("%d\n",way[n-1][n-1]);
	//printf("%d %d\n",rnk[0],rnk[1]);
	for(int i=0;i<n;i++)
	{
		cnt+=way[n-1][i];
		if(cnt>=MOD) cnt-=MOD;
		if(dp[n-1][i]<n)
		{
			if(i<=20)
			{
				int t=1,now=dp[n-1][i];
				for(int j=0;j<i;j++)
				{
					int p=n-j-1;
					if(str[p]=='1') now+=t;
					t<<=1;
				}
				if(m>now)
				{
					m=now;
				}
			}
			else
			{
				if(m==INF)
				{
					int t=1,now=dp[n-1][i];
					for(int j=0;j<i;j++)
					{
						int p=n-j-1;
						if(str[p]=='1')
						{
							now+=t;
							if(now>=MOD) now-=MOD;
						}
						t<<=1;
						if(t>=MOD) t-=MOD;
					}
					m=now;
				}
			}
		}
	}
	printf("%d\n%d\n",cnt,m);
	return 0;
}