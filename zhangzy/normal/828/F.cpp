#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define xxx 520233
using namespace std;
int n,m;
struct E{
	int from,to,val,pos;
}e[xxx];
struct R{
	int to,val,pos,nex;
}r[xxx];
int hea[xxx],cnt=1;
int fa[xxx];
int dep[xxx],f[xxx][21],trx[xxx][21],eln[xxx][21],fe[xxx],ans[xxx];

bool cmp(E e1,E e2){
	return e1.val<e2.val;
}

int GF(int x){
	return fa[x]==x? x : fa[x]=GF(fa[x]);
}

void A(int u,int v,int w,int pos){
	r[++cnt]=(R){v,w,pos,hea[u]};
	hea[u]=cnt;
}

void dfs(int x,int fa,int rid){
	f[x][0]=fa;
	trx[x][0]=r[rid].val;
	dep[x]=dep[fa]+1;
	fe[x]=r[rid].pos;
	//printf(" %d %d %d\n",x,fa,fe[x]);
	for (int i=1;i<=20;i++){
		if (dep[x]<=(1<<i)) break;
		f[x][i]=f[f[x][i-1]][i-1];
		trx[x][i]=max(trx[x][i-1],trx[f[x][i-1]][i-1]);
	}
	for (int i=hea[x];i>0;i=r[i].nex){
		if (r[i].to!=fa)
			dfs(r[i].to,x,i);
	}
}

int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	for (int i=20;i>=0;i--){
		if (dep[x]-(1<<i)>=dep[y])
			x=f[x][i];
	}
	if (x==y) return x;
	for (int i=20;i>=0;i--){
		if (f[x][i]!=f[y][i]){
			x=f[x][i];
			y=f[y][i];
		}
	}
	return f[x][0];
}

int doit(int x,int y,int v){
	int t=0;
	for (int i=20;i>=0;i--){
		if (dep[x]-(1<<i)>=dep[y]){
			eln[x][i]=min(eln[x][i],v);
			t=max(t,trx[x][i]);
			x=f[x][i];
		}
	}
	return t-1;
}

int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].from,&e[i].to,&e[i].val);
		e[i].pos=i;
	}
	sort(e+1,e+m+1,cmp);
	
	for (int i=1;i<=n;i++)
		fa[i]=i;
	int f1,f2;
	for (int i=1;i<=m;i++){
		if ( (f1=GF(e[i].from))==(f2=GF(e[i].to)) ) continue;
		fa[f1]=f2;
		A(e[i].from,e[i].to,e[i].val,e[i].pos);
		A(e[i].to,e[i].from,e[i].val,e[i].pos);
		e[i].pos=0;
	}
	
	dfs(1,0,0);
	
	memset(eln,127,sizeof(eln));
	int lca;
	for (int i=1;i<=m;i++){
		if (!e[i].pos) continue;
		lca=LCA(e[i].from,e[i].to);
		//printf("  %d: %d %d %d\n",e[i].pos,e[i].from,e[i].to,lca);
		ans[e[i].pos]=max(doit(e[i].from,lca,e[i].val),doit(e[i].to,lca,e[i].val));
	}
	
	for (int i=20;i>0;i--){
		for (int j=1;j<=n;j++){
			eln[j][i-1]=min(eln[j][i-1],eln[j][i]);
			eln[f[j][i-1]][i-1]=min(eln[f[j][i-1]][i-1],eln[j][i]);
		}
	}
	for (int j=1;j<=n;j++)
		ans[fe[j]]=eln[j][0]-1;
	
	for (int i=1;i<=m;i++)
		printf("%d ",ans[i]>1000000000?-1:ans[i]);
}