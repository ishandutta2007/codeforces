#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#define SIZE 505
#define MX 1005

using namespace std;
typedef pair <int,int> PP;

struct P
{
	int in,out,w,s,v;
	P(int in=0,int out=0,int w=0,int s=0,int v=0):in(in),out(out),w(w),s(s),v(v){}
	bool operator<(const P&l) const
	{
		if(out-in!=l.out-l.in) return out-in<l.out-l.in;
		return in<l.in;
	}
};
int dp[SIZE][MX];
int cur[SIZE*2][MX];
P pos[SIZE];
PP now[SIZE];

int main()
{
	int n,S;
	scanf("%d %d",&n,&S);
	int sz=0;
	pos[sz++]=P(0,2*n,0,S,0);
	for(int j=0;j<n;j++)
	{
		int i,o,w,s,v;
		scanf("%d %d %d %d %d",&i,&o,&w,&s,&v);
		pos[sz++]=P(i,o,w,s,v);
	}
	sort(pos,pos+sz);
	for(int i=0;i<sz;i++)
	{
		int m=0;
		for(int j=0;j<i;j++)
		{
			if(pos[i].in<=pos[j].in&&pos[j].out<=pos[i].out)
			{
				now[m++]=PP(pos[j].in,j);
			}
		}
		sort(now,now+m);
		for(int j=0;j<=pos[i].out;j++)
		{
			for(int k=0;k<=S;k++)
			{
				cur[j][k]=0;
			}
		}
		int bef=0;
		for(int j=0;j<m;j++)
		{
			int id=now[j].second;
			//printf("%d ",id);
			while(bef<pos[id].in)
			{
				int mx=0;
				for(int k=0;k<=S;k++)
				{
					mx=max(mx,cur[bef][k]);
					cur[bef+1][k]=max(cur[bef+1][k],mx);
				}
				bef++;
			}
			for(int k=0;k<=S;k++)
			{
				cur[pos[id].out][k]=max(cur[pos[id].out][k],cur[pos[id].in][k]+dp[id][k]);
			}
		}
		//puts("");
		while(bef<pos[i].out)
		{
			int mx=0;
			for(int k=0;k<=S;k++)
			{
				mx=max(mx,cur[bef][k]);
				cur[bef+1][k]=max(cur[bef+1][k],mx);
			}
			bef++;
		}
		int mx=0;
		for(int j=0;j<=S;j++)
		{
			mx=max(mx,cur[pos[i].out][j]);
			dp[i][j]=mx;
		}
		for(int j=pos[i].s+1;j<=S;j++) dp[i][j]=0;
		for(int j=S;j>=pos[i].w;j--) dp[i][j]=max(dp[i][j],dp[i][j-pos[i].w]+pos[i].v);
		mx=0;
		for(int j=0;j<=S;j++)
		{
			mx=max(mx,dp[i][j]);
			dp[i][j]=mx;
		}
		//for(int j=0;j<=S;j++) printf("%d ",dp[i][j]);puts("");
	}
	printf("%d\n",dp[sz-1][S]);
	return 0;
}