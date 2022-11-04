#include<bits/stdc++.h>
#define mo 1000000007
#define N 1005
using namespace std;
int f[N][(1<<12)+5];
struct edge{int to,next;}e[N*2];
struct Tree{
	int c[N][N],head[N];
	int sz[N],son[N],hsh[N];
	int n,tot;
	edge e[N*2];
	void add(int x,int y){
		e[++tot]=(edge){y,head[x]};
		head[x]=tot;
	}
	void init(){
		scanf("%d",&n);
		for (int i=2;i<=n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y); add(y,x);
		}
	}
	void dfs(int x,int fa){
		son[x]=hsh[x]=0;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa){
				c[x][son[x]++]=e[i].to;
				dfs(e[i].to,x);
				hsh[x]|=1<<(e[i].to-1); 
			}
	}
}a,b;
int dfs(int x,int y,int v){
	if (!y) return !v;
	int &ans=f[a.c[x][y-1]][v];
	if (ans) return ans-1;
	ans=dfs(x,y-1,v);
	for (int to=a.c[x][y-1],k=0;k<b.n;k++)
		if ((v>>k)&1)
			ans=(ans+1ll*dfs(x,y-1,v^(1<<k))*
						dfs(to,a.son[to],b.hsh[k+1]))%mo;
	return ans++;
}
int Inv(int x){
	return x<=1?x:1ll*(mo-mo/x)*Inv(mo%x)%mo;
}
int main(){
	a.init(); b.init();
	a.dfs(1,0);
	int ans=0,Ans=0;
	for (int i=1;i<=b.n;i++){
		b.dfs(i,0);
		for (int j=1;j<=a.n;j++)
			ans=(ans+dfs(j,a.son[j],b.hsh[i]))%mo;
		memset(f,0,sizeof(f));
	}
	a=b;
	a.dfs(1,0);
	for (int i=1;i<=b.n;i++){
		b.dfs(i,0);
		for (int j=1;j<=a.n;j++)
			Ans=(Ans+dfs(j,a.son[j],b.hsh[i]))%mo;
		memset(f,0,sizeof(f));
	}
	printf("%d",ans*1ll*Inv(Ans)%mo);
}