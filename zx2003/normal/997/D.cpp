#include<bits/stdc++.h>
using namespace std;
const int N=4005,K=80,mo=998244353;
struct poly{int a[K];}ret;
int C[N][N],k;
inline poly operator+(const poly&a,const poly&b){
	int i,j;memset(ret.a,0,k+1<<2);
	for(i=0;i<=k;++i)ret.a[i]=(a.a[i]+b.a[i])%mo;
	return ret;
}
inline poly operator*(const poly&a,const poly&b){
	int i,j;memset(ret.a,0,k+1<<2);
	for(i=0;i<=k;++i)for(j=0;i+j<=k;++j)ret.a[i+j]=(ret.a[i+j]+1ll*a.a[i]*b.a[j])%mo;
	return ret;
}
inline poly mul2(const poly&a,const poly&b){
	int i,j;memset(ret.a,0,k+1<<2);
	for(i=0;i<=k;++i)for(j=0;i+j<=k;++j)ret.a[i+j]=(ret.a[i+j]+1ll*a.a[i]*b.a[j]%mo*C[i+j][i])%mo;
	return ret;
}
inline poly F(poly a){
	int i,j;memset(ret.a,0,k+1<<2);ret.a[0]=1;
	for(i=1;i<=k;++i)for(j=2;j<=i;++j)ret.a[i]=(ret.a[i]+1ll*a.a[j-2]*ret.a[i-j])%mo;
	return ret;
}
struct tree{
	int n;
	vector<int>e[N];
	poly of[N],f[N],g[N],tot;
	void dfs1(int x,int fa){
		if(fa)e[x].erase(find(e[x].begin(),e[x].end(),fa));
		for(int y:e[x])dfs1(y,x),f[x]=f[x]+f[y];
		of[x]=f[x];f[x]=F(f[x]);
	}
	void dfs2(int x){
		static poly pre[N],suf[N];int i,d=e[x].size();
		memset(suf[d+1].a,0,k+1<<2);
		for(i=1;i<=d;++i)pre[i]=pre[i-1]+f[e[x][i-1]];
		for(i=d;i;--i)suf[i]=suf[i+1]+f[e[x][i-1]];
		for(i=1;i<=d;++i)g[e[x][i-1]]=F(pre[i-1]+suf[i+1]+g[x]);
		for(int y:e[x])dfs2(y);
	}
	void solve(){
		int x,y,i;
		for(i=1;i<n;++i)scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
		dfs1(1,0);dfs2(1);
		for(i=1;i<=n;++i)tot=tot+F(of[i]+g[i]);
	}
}t1,t2;
int main(){
	for(int i=**C=1;i<K;++i)for(int j=*C[i]=1;j<=i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	scanf("%d%d%d",&t1.n,&t2.n,&k);
	t1.solve();t2.solve();
	printf("%d\n",mul2(t1.tot,t2.tot).a[k]);
	return 0;
}