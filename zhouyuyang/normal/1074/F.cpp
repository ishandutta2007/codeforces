#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define uint unsigned
#define db double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pli pair<ll,int>
#define vi vector<int>
#define vpi vector<pii >
#define IT iterator
 
#define PB push_back
#define MK make_pair
#define LB lower_bound
#define UB upper_bound
#define y1 wzpakking
#define fi first
#define se second
#define BG begin
#define ED end
 
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define UPD(x,y) (((x)+=(y))>=mo?(x)-=mo:233)%s
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define sqr(x) (1ll*x*x)
 
#define LS3 k*2,l,mid
#define RS3 k*2+1,mid+1,r
#define LS5 k*2,l,mid,x,y
#define RS5 k*2+1,mid+1,r,x,y
#define GET pushdown(k);int mid=(l+r)/2
#define INF (1ll<<60)
using namespace std;

namespace FastInput{
	/*const int LBC=2333333;
	char LZH[LBC],*SSS=LZH,*TTT=LZH;
	inline char gc(){
		if (SSS==TTT){
			TTT=(SSS=LZH)+fread(LZH,1,LBC,stdin);
			if (SSS==TTT) return EOF;
		}
		return *SSS++;
	}*/
	#define gc getchar
	inline int read(){
		int x=0;
		char ch=gc();
		for (;ch<'0'||ch>'9';ch=gc());
		for (;ch>='0'&&ch<='9';ch=gc())
			x=x*10-48+ch;
		return x;
	}
}
using namespace FastInput;
const int N=200005;
int tg[N*4];
pii t[N*4];
void build(int k,int l,int r){
	t[k].se=r-l+1;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void pushdown(int k){
	tg[k*2]+=tg[k]; tg[k*2+1]+=tg[k];
	t[k*2].fi+=tg[k]; t[k*2+1].fi+=tg[k];
	tg[k]=0;
}
void pushup(int k){
	t[k].fi=max(t[k*2].fi,t[k*2+1].fi);
	t[k].se=(t[k].fi==t[k*2].fi?t[k*2].se:0);
	t[k].se+=(t[k].fi==t[k*2+1].fi?t[k*2+1].se:0);
}
void change(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		tg[k]+=v; t[k].fi+=v;
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else{
		change(k*2,l,mid,x,mid,v);
		change(k*2+1,mid+1,r,mid+1,y,v);
	}
	pushup(k);
}
int n,Q,T,cnt,dfn[N],ed[N];
int fa[N][20],dep[N];
vector<int> e[N];
void dfs(int x){
	dfn[x]=++T;
	for (auto i:e[x])
		if (i!=fa[x][0]){
			fa[i][0]=x;
			dep[i]=dep[x]+1;
			dfs(i);
		}
	ed[x]=T;
}
int LCA(int x,int y){
	if (dep[x]>dep[y]) swap(x,y);
	Rep(i,17,0) if (dep[fa[y][i]]>=dep[x]) y=fa[y][i];
	Rep(i,17,0) if (fa[x][i]!=fa[y][i])
		x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int jump(int x,int y){
	Rep(i,17,0) if (dep[fa[y][i]]>dep[x]) y=fa[y][i];
	return y;
}
map<pii,int> vis;
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dep[1]=1; dfs(1);
	For(i,1,17) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	build(1,1,n);
	while (Q--){
		int x,y,v;
		scanf("%d%d",&x,&y);
		if (x>y) swap(x,y);
		v=(vis[pii(x,y)]?-1:1);
		vis[pii(x,y)]^=1; cnt+=v;
		int L=LCA(x,y);
		if (L==x||L==y){
			if (L==y) swap(x,y);
			change(1,1,n,1,n,v);
			int X=jump(x,y);
			change(1,1,n,dfn[X],ed[X],-v);
			change(1,1,n,dfn[y],ed[y],v);
		}
		else{
			change(1,1,n,dfn[x],ed[x],v);
			change(1,1,n,dfn[y],ed[y],v);
		}
		printf("%d\n",(t[1].fi==cnt)*t[1].se);
	}
}