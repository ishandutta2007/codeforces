#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=25;
const int maxm=450;
const int maxe=1000;
int T;
int n,m;
char s[maxn];
bool fr[maxn][maxn];
int id(int x,int y){return (x-1)*m+y;}
struct edge{int from,to;}e[maxe];int cnt;
int d[maxm];
struct dsu
{
	int fa[maxm];
	void prework(){for(int i=1;i<=n*m;i++)fa[i]=i;}
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	void merge(int x,int y){fa[get(x)]=get(y);}
	bool check(int x,int y){return get(x)==get(y);}
}S;
bool vis[maxe],in[maxe],x[maxe],y[maxe];
queue<int>q;int pre[maxe];
bool solve()
{
	S.prework();memset(d,0,sizeof d);memset(pre,0,sizeof pre);memset(vis,0,sizeof vis);
	for(int i=1;i<=cnt;i++)if(in[i]){S.merge(e[i].from,e[i].to);d[e[i].to]++;}
	while(!q.empty())q.pop();
	for(int i=1;i<=cnt;i++)
	{
		if(in[i]){x[i]=y[i]=0;continue;}
		x[i]=!S.check(e[i].from,e[i].to);y[i]=d[e[i].to]<2;
		if(x[i]&&y[i])return in[i]=1;
		if(x[i])q.push(i),vis[i]=1;
	}
	while(!q.empty())
	{
		int now=q.front();q.pop();
		if(y[now])
		{
			while(now){in[now]^=1;now=pre[now];}
			return true;
		}
		if(in[now])
		{
			S.prework();
			for(int i=1;i<=cnt;i++)if(in[i]&&i!=now)S.merge(e[i].from,e[i].to);
			for(int i=1;i<=cnt;i++)if(!in[i]&&!vis[i]&&!S.check(e[i].from,e[i].to)){q.push(i);vis[i]=1;pre[i]=now;}
		}
		else for(int i=1;i<=cnt;i++)if(in[i]&&!vis[i]&&d[e[now].to]-(e[i].to==e[now].to)<2){q.push(i);vis[i]=1;pre[i]=now;}
	}
	return false;
}
bool to[maxm][maxm];
char ans[maxn<<1][maxn<<1];
void link(int x1,int y1,int x2,int y2)
{
	if(!fr[x1][y1]||!fr[x2][y2])return;
	if(S.check(id(x1,y1),id(x2,y2)))return;
	S.merge(id(x1,y1),id(x2,y2));to[id(x1,y1)][id(x2,y2)]=to[id(x2,y2)][id(x1,y1)]=1;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();m=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)fr[i][j]=s[j]=='O';
		}
		cnt=0;int need=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if((!fr[i][j])||(i==1&&j==1)||((i+j)&1))continue;
				if(j<m&&fr[i][j+1])e[++cnt]=edge{id(i,j+1),id(i,j)};if(j>1&&fr[i][j-1])e[++cnt]=edge{id(i,j-1),id(i,j)};
				if(i>1&&fr[i-1][j])e[++cnt]=edge{id(i-1,j),id(i,j)};if(i<n&&fr[i+1][j])e[++cnt]=edge{id(i+1,j),id(i,j)};
				need+=2;
			}
		}
		memset(in,0,sizeof in);
		while(solve())need--;
		if(need){printf("NO\n");continue;}
		else printf("YES\n");
		memset(to,0,sizeof to);
		S.prework();
		for(int i=1;i<=cnt;i++)if(in[i]){to[e[i].from][e[i].to]=to[e[i].to][e[i].from]=1;S.merge(e[i].from,e[i].to);}
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)link(i,j,i-1,j),link(i,j,i,j-1);
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)ans[i*2-1][j*2-1]=fr[i][j]?'O':'X';
		for(int i=1;i<=n;i++)for(int j=1;j<=m-1;j++)ans[2*i-1][2*j]=to[id(i,j)][id(i,j+1)]?'O':' ';
		for(int i=1;i<=n-1;i++)for(int j=1;j<=m;j++)ans[2*i][2*j-1]=to[id(i,j)][id(i+1,j)]?'O':' ';
		for(int i=1;i<=n-1;i++)for(int j=1;j<=m-1;j++)ans[i*2][j*2]=' ';
		for(int i=1;i<=2*n-1;i++){for(int j=1;j<=2*m-1;j++)printf("%c",ans[i][j]);printf("\n");}
	}
	return 0;
}