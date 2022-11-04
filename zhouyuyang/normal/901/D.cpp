#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
struct edge{int to,next,id;}e[N*2];
int n,m,tot,idx,idy,ide;
int head[N],c[N],vis[N];
ll a[N],b[N];
void add(int x,int y,int id){
	e[++tot]=(edge){y,head[x],id};
	head[x]=tot;
}
bool pdfs(int x){
	for (int i=head[x];i;i=e[i].next)
		if (!c[e[i].to]){
			c[e[i].to]=3-c[x];
			if (!pdfs(e[i].to)) return 0;
		}
		else if (c[e[i].to]==c[x]){
			idx=x; idy=e[i].to;
			ide=i; return 0;
		}
	return 1;
}
ll dfs(int x){
	vis[x]=1;
	ll s=a[x];
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]){
			ll tmp=dfs(e[i].to);
			b[e[i].id]+=tmp;
			s-=tmp;
		}
	return s;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y,i); add(y,x,i);
	}
	c[1]=1;
	bool f=pdfs(1);
	if (f){
		long long s=0;
		for (int i=1;i<=n;i++)
			if (c[i]==1) s+=a[i];
			else s-=a[i];
		if (s) return puts("NO"),0;
		s=dfs(1);
		if (s) return puts("NO"),0;
		puts("YES");
		for (int i=1;i<=m;i++)
			printf("%I64d\n",b[i]);
		return 0;
	}
	long long s=dfs(1);
	if (s&1) return puts("NO"),0;
	s/=2;
	if (c[idx]==2) s=-s;
	memset(b,0,sizeof(b));
	b[e[ide].id]=s;
	a[idx]-=s; a[idy]-=s;
	memset(vis,0,sizeof(vis));
	s=dfs(1);
	if (s) return puts("NO"),0;
	puts("YES");
	for (int i=1;i<=m;i++)
		printf("%I64d\n",b[i]);
}