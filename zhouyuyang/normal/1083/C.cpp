#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define db long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define EB emplace_back
#define fi first
#define se second
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?x-=mo:233)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
 
#define inf 1e18
#define sqr(x) ((x)*(x))
using namespace std;
const int N=200005;
int dep[N],fa[N][18];
int sz[N],dfn[N],ed[N],las[N];
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	For(i,0,17) if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,17,0) if (fa[x][i]!=fa[y][i])
		x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int p[5];
bool check(int x,int y){
	return dfn[x]<=dfn[y]&&ed[x]>=ed[y];
}
bool cmp(int x,int y){
	return dep[x]>dep[y];
}
pii operator +(const pii &a,const pii &b){
	if (a==pii(-1,-1)||b==pii(-1,-1))
		return pii(-1,-1);
	p[1]=a.fi; p[2]=a.se; p[3]=b.fi; p[4]=b.se;
	sort(p+1,p+5,cmp);
	int L=p[4];
	Rep(i,3,1)
		if (!check(L,p[i])){
			L=-1; break;
		}
	int tp=0;
	For(i,1,4) if (p[i]!=L){
		int cnt=0;
		For(j,1,tp) if (check(p[i],p[j])) cnt=1;
		if (!cnt) p[++tp]=p[i];
	}
	if (L!=-1){
		int L2=p[1];
		For(i,2,tp) L2=LCA(L2,p[i]);
		if (L2!=L&&L!=-1) p[++tp]=L;
	}
	return tp>2?pii(-1,-1):pii(p[1],p[2]);
}
pii t[N*3];
int a[N],pos[N],n,Q;
void build(int k,int l,int r){
	if (l==r){
		t[k]=pii(pos[l],pos[l]);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=t[k*2]+t[k*2+1];
}
void change(int k,int l,int r,int p,int v){
	if (l==r){
		t[k]=pii(v,v);
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p,v);
	else change(k*2+1,mid+1,r,p,v);
	t[k]=t[k*2]+t[k*2+1];
}
int ask(int k,int l,int r,pii v){
	if (l==r) return (v+t[k]==pii(-1,-1)?l:l+1);
	int mid=(l+r)/2;
	pii tmp=v+t[k*2];
	if (tmp!=pii(-1,-1))
		return ask(k*2+1,mid+1,r,tmp);
	return ask(k*2,l,mid,v);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),a[i]++,pos[a[i]]=i;
	For(i,2,n){
		scanf("%d",&fa[i][0]);
		dep[i]=dep[fa[i][0]]+1;
	}
	Rep(i,n,1) sz[i]++,sz[fa[i][0]]+=sz[i];
	For(i,1,n){
		las[i]=dfn[i]=las[fa[i][0]]+1;
		las[fa[i][0]]+=sz[i];
		ed[i]=dfn[i]+sz[i]-1;
	}
	For(i,1,17) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	build(1,1,n);
	scanf("%d",&Q);
	while (Q--){
		int tp; scanf("%d",&tp);
		if (tp==1){
			int x,y;
			scanf("%d%d",&x,&y);
			swap(a[x],a[y]);
			swap(pos[a[x]],pos[a[y]]);
			change(1,1,n,a[x],x);
			change(1,1,n,a[y],y);
		}
		else
			printf("%d\n",ask(1,1,n,pii(pos[1],pos[1]))-1);
	}
}