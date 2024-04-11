#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=3e5+3;
int n,m,q,sum;
bool val[maxn];
struct query{int x,y;}p[maxn];
vector<int>ans1,ans2;
struct graph
{
	vector<int>e1[maxn],e2[maxn];
	int fa[maxn];bool vis[maxn];
	void link(int x,int y){e1[x].push_back(y);e1[y].push_back(x);}
	void dfs(int x,int f)
	{
		fa[x]=f;vis[x]=1;
		for(int y:e1[x])if(!vis[y])dfs(y,x),e2[x].push_back(y);
	}
	void work(int x,int y)
	{
		int ox=x,oy=y;
		for(int j=0;j<=n;++j)vis[j]=0;
		while(y){vis[y]=1;y=fa[y];}
		ans1.clear();ans2.clear();
		while(x&&!vis[x]){ans1.push_back(x);x=fa[x];}
		y=oy;while(y!=x){ans2.push_back(y);y=fa[y];}
		printf("%lu\n",ans1.size()+ans2.size()+1);
		reverse(ans2.begin(),ans2.end());
		for(int j:ans1)printf("%d ",j);printf("%d ",x);for(int j:ans2)printf("%d ",j);printf("\n");
	}
}o;
int main()
{
	n=read();m=read();
	for(int i=1;i<=m;i++)o.link(read(),read());
	q=read();
	for(int i=1;i<=q;i++)p[i].x=read(),p[i].y=read(),val[p[i].x]^=1,val[p[i].y]^=1;
	for(int i=1;i<=n;i++)sum+=val[i];
	if(!sum)
	{
		o.dfs(1,0);
		printf("YES\n");
		for(int i=1;i<=q;i++)o.work(p[i].x,p[i].y);
	}
	else printf("NO\n%d\n",sum>>1);
	return 0;
}