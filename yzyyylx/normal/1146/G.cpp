#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define N 3010
#define M 1001000
using namespace std;

int n,m,tot,S,T,h,ans,bb=1,first[N],cur[N],deep[N];
struct Bn
{
    int to,next,quan;
}bn[M];
queue<int>que;

inline void add(int u,int v,int w)
{
    bb++;
    bn[bb].to=v;
    bn[bb].quan=w;
    bn[bb].next=first[u];
    first[u]=bb;
}

inline void ad(int u,int v,int w)
{
//    cout<<u<<" "<<v<<" "<<w<<endl;
    add(u,v,w);
    add(v,u,0);
}

inline bool bfs()
{
    memset(deep,0,sizeof(deep));
    int p,q;
    deep[S]=1;
    que.push(S);
    for(;!que.empty();)
    {
	q=que.front();
	que.pop();
	for(p=first[q];p!=-1;p=bn[p].next)
	{
	    int t=bn[p].to;
	    if(deep[t] || !bn[p].quan) continue;
	    deep[t]=deep[q]+1;
	    que.push(t);
	}
    }
    return deep[T];
}

int dfs(int now,int mn)
{
    if(now==T) return mn;
    int res;
    for(int &p=cur[now];p!=-1;p=bn[p].next)
    {
	int t=bn[p].to;
	if(deep[t]!=deep[now]+1 || !bn[p].quan) continue;
	res=dfs(t,min(mn,bn[p].quan));
	if(res)
	{
	    bn[p].quan-=res;
	    bn[p^1].quan+=res;
	    return res;
	}
    }
    return 0;
}

int main()
{
    memset(first,-1,sizeof(first));
    int i,j,p,q,o,t;
    cin>>n>>h>>m;
    tot=(h+1)*n;
    T=tot+m+1;
    for(i=1;i<=n;i++)
    {
	for(j=(i-1)*(h+1)+1;j<i*(h+1);j++) ad(j,j+1,h*h-(j-(i-1)*(h+1)-1)*(j-(i-1)*(h+1)-1));
	ad(S,(i-1)*(h+1)+1,INF);
    }
    for(i=1;i<=m;i++)
    {
	scanf("%d%d%d%d",&p,&q,&o,&t);
	if(o>=h) continue;
	ad(i+tot,T,t);
	for(j=p;j<=q;j++) ad((j-1)*(h+1)+o+2,i+tot,INF);
    }
    for(;bfs();)
    {
	memcpy(cur,first,sizeof(first));
	for(t=dfs(S,INF);t;ans+=t,t=dfs(S,INF));
    }
    cout<<h*h*n-ans;
}