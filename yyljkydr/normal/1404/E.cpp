#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=1e6+1e3+7,INF=0x7ffffff;

struct node{
	int ne,to,w;
}edg[N+1];

queue<int>q;

int head[N],S,T,cnt=1,d[N],ans,h[N];

int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();};
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();};
	return x;
}

void build(int u,int v,int w)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].w=w;
	edg[cnt].ne=head[u];
	head[u]=cnt;
	++cnt;
	edg[cnt].to=u;
	edg[cnt].w=0;
	edg[cnt].ne=head[v];
	head[v]=cnt;
}

bool bfs()
{
	for(int i=S;i<=T;i++)
		head[i]=h[i];
	memset(d,-1,sizeof(d));
	q.push(S);
	d[S]=0;
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
		{
			int v=edg[tmp].to;
			if(d[v]!=-1||edg[tmp].w<=0)
				continue;
			d[v]=d[i]+1;
			q.push(v);
		}
	}
	return d[T]!=-1;
}

int dinic(int i,int mn)
{
	if(i==T||mn==0)
		return mn;
	int flow=0;
	for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		int tmpf;
		if(d[v]==d[i]+1&&(tmpf=dinic(v,min(mn,edg[tmp].w)))>0)
		{
			flow+=tmpf;
			mn-=tmpf;
			edg[tmp].w-=tmpf;
			edg[tmp^1].w+=tmpf;
			if(edg[tmp].w)
				head[i]=tmp;
		}
		if(mn==0)
			break;
	}
	if(flow==0)
		d[i]=0;
	return flow;
}

char s[202][202];

int n,m;

int main()
{
	int tot=0;
	scanf("%d%d",&n,&m);
	S=0,T=(n-1)*m+(m-1)*n+1;
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	int ss=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
		{
			if(s[i][j]=='#'&&s[i][j+1]=='#')
				build(S,(i-1)*(m-1)+j,1),ss++;
		}
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='#'&&s[i+1][j]=='#')
				build((j-1)*(n-1)+i+n*(m-1),T,1),ss++;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			tot+=s[i][j]=='#';
			int U=0,D=0,L=0,R=0;
			if(s[i][j]=='#'&&s[i][j+1]=='#')
				R=(i-1)*(m-1)+j;
			if(s[i][j]=='#'&&s[i][j-1]=='#')
				L=(i-1)*(m-1)+j-1;
			if(s[i][j]=='#'&&s[i+1][j]=='#')
				D=(j-1)*(n-1)+i+n*(m-1);
			if(s[i][j]=='#'&&s[i-1][j]=='#')
				U=(j-1)*(n-1)+i-1+n*(m-1);
			if(U&&L)
				build(L,U,1);
			if(U&&R)
				build(R,U,1);
			if(D&&L)
				build(L,D,1);
			if(D&&R)
				build(R,D,1);
		}
	ans=ss;
	for(int i=S;i<=T;i++)
		h[i]=head[i];
	while(bfs())
		ans-=dinic(S,INF);
	ans=tot-ans;
	printf("%d\n",ans);
}