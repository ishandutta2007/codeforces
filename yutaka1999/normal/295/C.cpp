#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#define MOD 1000000007
#define INF 1000000010

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
typedef pair <int,P> PP;
template <class T> void chmin(T&a,T b){a=min(a,b);}

ll dp[55][55][2];
ll time[55][55][2];
bool use[55][55][2];
ll C[55][55];
int sn=0,tn=0;
int n,k;

void make()
{
	memset(dp,0,sizeof(dp));
	memset(time,-1,sizeof(time));
	memset(use,false,sizeof(use));
	dp[sn][tn][1]=1;
	time[sn][tn][1]=0;
	use[sn][tn][1]=true;
	for(int i=0;i<55;i++)
	{
		C[i][0]=1;
		C[i][i]=1;
		for(int j=1;j<i;j++)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		}
	}
}
void solve()
{
	queue <PP> que;
	que.push(PP(1,P(sn,tn)));
	while(!que.empty())
	{
		PP q=que.front();que.pop();
		int s=q.second.first,t=q.second.second,p=q.first;
		int nt=time[s][t][p]+1;
		for(int i=0;i<=s;i++)
		{
			for(int j=0;j<=t;j++)
			{
				if(i*50+j*100>k) break;
				if(i==0&&j==0) continue;
				int as=sn-s+i,at=tn-t+j;
				ll pa=dp[s][t][p];
				pa=(pa*C[as][i])%MOD;
				pa=(pa*C[at][j])%MOD;
				if(time[as][at][p^1]==-1||time[as][at][p^1]>nt)
				{
					time[as][at][p^1]=nt;
					dp[as][at][p^1]=0;
					use[as][at][p^1]=false;
				}
				else if(time[as][at][p^1]<nt) continue;
				dp[as][at][p^1]+=pa;
				dp[as][at][p^1]%=MOD;
				if(!use[as][at][p^1])
				{
					que.push(PP(p^1,P(as,at)));
					use[as][at][p^1]=true;
				}
			}
		}
	}
}
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		if(a==50) sn++;
		else tn++;
	}
	make();
	solve();
	//see();
	printf("%I64d\n",time[sn][tn][0]);
	printf("%I64d\n",dp[sn][tn][0]);
	return 0;
}