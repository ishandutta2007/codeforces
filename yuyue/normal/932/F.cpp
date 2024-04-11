#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10,con=1e5+1,bd=2e5+2;
#define mid (l+r>>1)
#define lc (x<<1)
#define rc (x<<1|1)
struct Line{
	LL k,b;
	Line (LL _=0,LL __=0){
		k=_; b=__;
	}
};
int rt[M],a[M],b[M];
vector<int> v[M];
Line t[M<<2];
int L[M<<2],R[M<<2],tot;
LL gv(Line x,LL o){
	return o*x.k+x.b;
}
void ins(int &x,int l,int r,Line o){
	if (!x) {
		x=++tot;
		t[x]=o;
		return ;
	} 
	if (gv(o,mid)<gv(t[x],mid)) swap(t[x],o);
	if (l==r) return ;
	if (gv(o,l)<gv(t[x],l)) ins(L[x],l,mid,o);
	if (gv(o,r)<gv(t[x],r)) ins(R[x],mid+1,r,o); 
}
int merge(int x,int y,int l,int r){
	if (!x||!y) return x|y;
	ins(x,l,r,t[y]);
	L[x]=merge(L[x],L[y],l,mid);
	R[x]=merge(R[x],R[y],mid+1,r);
	return x;
}
LL ask(int x,int l,int r,int p){
	if (!x) return 1e17;
	if (l==r) return gv(t[x],p);
	LL tmp=gv(t[x],p);
	if (p<=mid) return min(ask(L[x],l,mid,p),tmp);
	return min(ask(R[x],mid+1,r,p),tmp);
}
LL f[M];
void dfs(int x,int fa){
	f[x]=1e17;
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (y==fa) continue;
		dfs(y,x);
		f[x]=min(f[x],ask(rt[y],0,bd,a[x]+con));
		rt[x]=merge(rt[x],rt[y],0,bd);
	}
	if (!(SZ(v[x])) && x!=1) f[x]=0;
	ins(rt[x],0,bd,Line{b[x],f[x]-1ll*con*b[x]});
}
int n;
int main(){
	n=read();
	F(i,1,n) a[i]=read();
	F(i,1,n) b[i]=read();
	F(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	dfs(1,0);
	F(i,1,n) cout<<f[i]<<" ";
	return 0;
}