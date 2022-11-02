#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=300005,M=N*2;
LL read(){
	LL x=0;
	char ch=getchar();
	while (!('0'<=ch&&ch<='9'))
		ch=getchar();
	while ('0'<=ch&&ch<='9')
		x=x*10+ch-48,ch=getchar();
	return x;
}
struct Gragh{
	int cnt,y[M],nxt[M],fst[N];
	LL z[M];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b,LL c){
		y[++cnt]=b,z[cnt]=c,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g;
int n,q,fa[N][20],depth[N],xx,yy;
LL a[N],dp1[N],f1[N],dp2[N],sum[N],fadis[N],len[N],s[N];
void dfs1(int x,int pre,int d,LL L){
	fa[x][0]=pre;
	depth[x]=d;
	len[x]=L;
	s[x]=s[pre]+a[x];
	for (int i=1;i<20;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	dp1[x]=0;
	for (int i=g.fst[x];i;i=g.nxt[i]){
		int y=g.y[i];
		LL z=g.z[i];
		if (y!=pre){
			dfs1(y,x,d+1,L+z);
			fadis[y]=z;
			f1[y]=max(dp1[y]+a[y]-z*2,0LL);
			dp1[x]+=f1[y];
		}
	}
}
void dfs2(int x,int pre,LL v,LL v2){
	dp2[x]=v;
	sum[x]=v2;
	for (int i=g.fst[x];i;i=g.nxt[i]){
		int y=g.y[i];
		LL z=g.z[i];
		if (y!=pre){
			LL _v=max(v+a[x]+dp1[x]-f1[y]-2*z,0LL);
			LL _v2=max(v2+dp1[x]-f1[y],0LL);
			dfs2(y,x,_v,_v2);
		}
	}
}
int LCA(int x,int y){
	if (depth[x]<depth[y])
		swap(x,y);
	for (int i=19;i>=0;i--)
		if (depth[x]-(1<<i)>=depth[y])
			x=fa[x][i];
	if (x==y)
		return x;
	for (int i=19;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	xx=x,yy=y;
	return fa[x][0];
}
int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
		a[i]=read();
	g.clear();
	for (int i=1;i<n;i++){
		int a=read(),b=read();
		LL c=read();
		g.add(a,b,c);
		g.add(b,a,c);
	}
	dfs1(1,0,0,0);
	dfs2(1,0,0,0);
	while (q--){
		int x,y,lca;
		scanf("%d%d",&x,&y);
		if (depth[x]>depth[y])
			swap(x,y);
		lca=LCA(x,y);
		if (x==lca){
			if (y==lca){
				printf("%I64d\n",dp1[x]+dp2[x]+a[x]);
				continue;
			}
			LL ans=s[y]-s[x]+a[x];
			ans-=len[y]-len[x];
			ans+=sum[y]-sum[x];
			ans+=dp2[x]+dp1[y];
			printf("%I64d\n",ans);
			continue;
		}
		LL ans=s[x]+s[y]-s[lca]*2+a[lca];
		ans-=len[x]+len[y]-len[lca]*2;
		ans+=sum[x]+sum[y]-sum[xx]-sum[yy];
		ans+=dp1[lca]-f1[xx]-f1[yy];
		ans+=dp2[lca]+dp1[x]+dp1[y];
		printf("%I64d\n",ans);
	}
	return 0;
}