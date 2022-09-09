#include<bits/stdc++.h>
const int N=205,M=N*N*4;
namespace tst{
const int V=N*2,E=M*2;
struct edge{int to,next;}e[E];
int h[V],ecnt,dfn[V],low[V],xb,st[V],w,bel[V],scccnt,vcnt;bool b[V];
inline void addedge(int x,int y){e[++ecnt]=(edge){y,h[x]};h[x]=ecnt;}
void dfs(int x){
	st[++w]=x;low[x]=dfn[x]=++xb;
	for(int i=h[x];i;i=e[i].next){
		if(!dfn[e[i].to])dfs(e[i].to);
		if(low[e[i].to]<low[x] && !bel[e[i].to])low[x]=low[e[i].to];
	}
	if(low[x]==dfn[x])for(++scccnt;bel[st[w]]=scccnt,b[st[w]^1]?0:b[st[w]]=1,st[w--]!=x;);
}
inline void ini(int n){vcnt=n;memset(h+1,0,n<<2);ecnt=0;}
inline bool wk(int z){
	int i;
	scccnt=0;memset(dfn+1,0,vcnt<<2);memset(low+1,0,vcnt<<2);memset(bel+1,0,vcnt<<2);memset(b+1,0,vcnt);
	for(i=2;i<=vcnt;++i)if(!dfn[i])dfs(i);
	for(i=1;i<=z;++i)if(bel[i<<1]==bel[i<<1|1])
		return 0;
	return 1;
}
}
int l,n,m,p1[M],t1[M],p2[M],t2[M],mx[2],aa[29],i,j,z,x,a[N],ans[N];
char c[N],cc[9];
int main(){
	scanf("%s%d%d",c+1,&n,&m);l=strlen(c+1);for(i=1;i<=l;++i)mx[aa[i]=c[i]=='C']=i;
	for(i=1;i<=m;++i){
		scanf("%d%s%d%s",p1+i,c,p2+i,cc),t1[i]=*c=='C',t2[i]=*cc=='C';
		if((!mx[0] && t2[i]==0 && t1[i]==1) || (!mx[1] && t2[i]==1 && t1[i]==0)){puts("-1");return 0;}
	}
	scanf("%s",c+1);for(i=1;i<=n;++i)a[i]=c[i]-'a'+1;
	for(i=n;i>=0;--i){
		if(i<n && a[i+1]==l)continue;
		tst::ini(n*2+1);
		for(j=1;j<=m;++j)
			tst::addedge(p1[j]<<1|t1[j],p2[j]<<1|t2[j]),
			tst::addedge(p2[j]<<1|!t2[j],p1[j]<<1|!t1[j]);
		for(j=1;j<=i;++j)tst::addedge(j<<1|!aa[a[j]],j<<1|aa[a[j]]);
		if(i<n && (mx[0]<=a[i+1] || mx[1]<=a[i+1])){
			if(mx[0]<=a[i+1])tst::addedge(i+1<<1,i+1<<1|1);
				else tst::addedge(i+1<<1|1,i+1<<1);
		}
		if(tst::wk(n))break;
	}
	if(i<0){puts("-1");return 0;}
	memcpy(ans+1,a+1,i<<2);z=i+1;
	for(;++i<=n;){
		tst::ini(n*2+1);
		for(j=1;j<=m;++j)
			tst::addedge(p1[j]<<1|t1[j],p2[j]<<1|t2[j]),
			tst::addedge(p2[j]<<1|!t2[j],p1[j]<<1|!t1[j]);
		for(j=1;j<i;++j)tst::addedge(j<<1|!aa[ans[j]],j<<1|aa[ans[j]]);
		if(i==z)x=a[i]+1;else x=1;ans[i]=x;
		tst::addedge(i<<1|!aa[x],i<<1|aa[x]);
		if(!tst::wk(n))for(;aa[ans[i]]==aa[x];++ans[i]);
	}
	for(i=1;i<=n;++i)putchar('a'+ans[i]-1);puts("");
	return 0;
}