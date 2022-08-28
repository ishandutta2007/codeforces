#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#define SIZE 10005
#define MX 105

using namespace std;
typedef pair <int,int> P;

int dp[MX][SIZE],use_cnt[MX][SIZE];
P back[MX][SIZE];
int in[MX];
P cur[MX];
int zan[SIZE];
vector <int> tg[MX];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);a--;
		in[a]+=2;
	}
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<m;i++)
	{
		if(i==0)
		{
			dp[i][in[i]]=0;
			use_cnt[i][in[i]]=0;
		}
		else
		{
			for(int j=0;j<SIZE;j++)
			{
				if(dp[i-1][j]==-1) continue;
				for(int k=0;k<=min(in[i],j);k++)
				{
					int nxt=j+in[i]-2*k;
					if(dp[i][nxt]<dp[i-1][j]+k)
					{
						dp[i][nxt]=dp[i-1][j]+k;
						use_cnt[i][nxt]=k;
						back[i][nxt]=P(i-1,j);
					}
				}
			}
		}
	}
	int mx=0;
	for(int i=0;i<SIZE;i++) mx=max(mx,dp[m-1][i]);
	printf("%d\n",mx);
	for(int i=0;i<SIZE;i++)
	{
		if(mx==dp[m-1][i])
		{
			int sz=0;
			P p=P(m-1,i);
			while(1)
			{
				cur[sz++]=p;
				if(p.first==0) break;
				P q=back[p.first][p.second];
				p=q;
			}
			int l=0,r=0,now=0;
			for(sz--;sz>=0;sz--)
			{
				P p=cur[sz];
				int a=p.first,b=p.second;
				for(int j=0;j<use_cnt[a][b];j++)
				{
					tg[zan[l]].push_back(a);
					l++;
				}
				for(int j=0;j<in[a]-use_cnt[a][b];j++) zan[r++]=a;
			}
			for(;l<r;l+=2)
			{
				tg[zan[l]].push_back(zan[l+1]);
			}
			for(int j=0;j<m;j++)
			{
				in[j]/=2;
				for(int k=0;k<tg[j].size();k++)
				{
					if(j==tg[j][k])
					{
						printf("%d %d\n",j+1,j+1);
						in[j]--;
					}
				}
			}
			for(int j=0;j<m;j++)
			{
				for(int k=0;k<tg[j].size();k++)
				{
					int to=tg[j][k];
					if(to==j) continue;
					if(in[to]>0&&tg[j].size()-k-1>=in[j])
					{
						printf("%d %d\n",to+1,j+1);
						in[to]--;
					}
					else
					{
						printf("%d %d\n",j+1,to+1);
						in[j]--;
					}
				}
			}
			break;
		}
	}
	return 0;
}