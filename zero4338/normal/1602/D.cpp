#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=3e5+5;
int n;
int ans,ap;
int a[maxn],b[maxn];
struct dsu
{
	int fa[maxn];
	void prework(){for(int i=1;i<=n+1;i++)fa[i]=i;}
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	void merge(int x,int y){fa[get(x)]=get(y);}
}S;
queue<int>q;int f[maxn],pre[maxn];
void bfs()
{
	S.prework();q.push(1);S.merge(1,2);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x-b[x]+a[x-b[x]]>n){ans=f[x]+1;ap=x;pre[n+1]=x;return;}
		for(int i=S.get(x-b[x]);i<=x-b[x]+a[x-b[x]];i=S.get(i)){q.push(i);pre[i]=x;f[i]=f[x]+1;S.merge(i,i+1);}
	}
}
void print(int x)
{
	if(x==1)return;
	if(pre[x])print(pre[x]);
	printf("%d ",n-x+1);
}
int main()
{
	n=read();
	generate_n(a+1,n,read);generate_n(b+1,n,read);reverse(a+1,a+n+1);reverse(b+1,b+n+1);
	ans=-1;bfs();
	if(ans==-1)printf("-1\n");
	else
	{
		printf("%d\n",ans);
		print(n+1);printf("\n");
	}
	return 0;
}