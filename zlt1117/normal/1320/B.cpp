//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5;
int dis[maxn],n,m,p[maxn],t[maxn],len;
vector<int>vec[maxn];
int cnt[maxn];
inline void bfs()
{
	queue<int>q;
	q.push(t[len]);
	memset(dis,0x3f,sizeof(dis));
	dis[t[len]]=0;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto x:vec[u])
		{
			if(dis[x]>dis[u]+1)
			{
				dis[x]=dis[u]+1;
				q.push(x);
			}
		}
	}
}
inline void init()
{
	memset(p,-1,sizeof(p));
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,m)
	{
		int u=gi(),v=gi();
		vec[v].pb(u);
	}
	len=gi();
	FOR(i,1,len)t[i]=gi();
}	
inline void solve()
{
	bfs();
	FOR(i,1,n)
	{
		for(auto x:vec[i])
		{
			if(dis[x]==dis[i]+1)cnt[x]++;
		}
	}
	int ans1=0,ans2=0;
	FOR(i,1,len-1)
	{
		if(dis[t[i+1]]==dis[t[i]]-1)
		{
			if(cnt[t[i]]>=2)ans2++;
		}
		else
		{
			ans1++,ans2++;
		}
	}
	printf("%d %d\n",ans1,ans2);
}
int main()
{
	init();
	input();
	solve();
	return 0;
}///