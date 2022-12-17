#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define rd (rand()<<16^rand())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=15,maxm=2005;
int T,n,m,a[maxm][maxn],dp[2][(1<<12)+1],tmp[(1<<12)+1];
vector<int>vec[(1<<12)+1];
bool vis[maxm];
inline void down(int *a)
{
	int temp=a[1];
	FOR(i,2,n)a[i-1]=a[i];
	a[n]=temp;
}
struct node
{
	int x,val;
	node(int xx=0,int vv=0){x=xx,val=vv;}
	inline bool operator<(const node &b)const
	{
		return val<b.val;
	}
};
priority_queue<node>pq;
inline void init()
{
	memset(dp,0,sizeof(dp));
	memset(tmp,0,sizeof(tmp));
	memset(vis,0,sizeof(vis));
	FOR(i,0,(1<<n)-1)vec[i].clear();
	while(!pq.empty())pq.pop();
}
inline void input()
{
	n=gi();m=gi();
	FOR(i,1,n)FOR(j,1,m)a[j][i]=gi(),pq.push(node(j,a[j][i]));///colume j 
	int cnt=0;
	while(cnt<n&&!pq.empty())
	{
		int x=pq.top().x;
		pq.pop();
		if(!vis[x])++cnt,vis[x]=1;
	}
	FOR(i,0,(1<<n)-1)
	{
		FOR(j,0,n-1)
		{
			if((i>>j)&1)continue;
			vec[i].push_back(j);
		}
	}
}
inline void solve()
{
	int now=0,last=0;
	FOR(i,1,m)///colume i
	{
		if(!vis[i])continue;
		now=now^1,last=now^1;
		FOR(j,1,n)
		{
			down(a[i]);
			memcpy(tmp,dp[last],sizeof(dp[last]));
			FOR(t,0,(1<<n)-1)
			{
				for(auto k:vec[t])
				{
					tmp[t|(1<<k)]=max(tmp[t|(1<<k)],tmp[t]+a[i][k+1]);
				}
				dp[now][t]=max(dp[now][t],tmp[t]);
			}
		}
	}
	printf("%d\n",dp[now][(1<<n)-1]);
}
int main()
{
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}
/*
1
12 12
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1
*/