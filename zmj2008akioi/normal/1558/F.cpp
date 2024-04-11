#include <cstdio>
const int N=2e5+10,inf=1e9;
int T,n,a[N],p[N],l[N],r[N];
template<typename T>T md(T x,T y){return (x+y)/2;}
template<typename T>T max(T x,T y){return x>y?x:y;}
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
namespace IO{
	int lt,nw,res,dig[30];char c;
	int read(){
		res=0;for(;c<'0'||c>'9';c=getchar());
		for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
		return res;
	}
	void write(int x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);putchar('\n');
	}
}using IO::read;using IO::write; 
void erase(int x){l[r[x]]=l[x],r[l[x]]=r[x];}
namespace SGT{
	int mx[N<<2],tg[N<<2];
	int lc(int x){return x<<1;}
	int rc(int x){return (x<<1)|1;}
	void add(int x,int d){mx[x]+=d,tg[x]+=d;}
	void pushup(int x){mx[x]=max(mx[lc(x)],mx[rc(x)]);}
	void pushdown(int x){add(lc(x),tg[x]),add(rc(x),tg[x]),tg[x]=0;}
	void build(int l,int r,int u){
		tg[u]=0;if(l==r)mx[u]=-inf+(l&1)+l;
		else build(l,md(l,r),lc(u)),build(md(l,r)+1,r,rc(u)),pushup(u);
	}
	void modify(int l,int r,int u,int tl,int tr,int d){
		if(l>=tl&&r<=tr){add(u,d);return;}pushdown(u);
		if(md(l,r)>=tl)modify(l,md(l,r),lc(u),tl,tr,d);
		if(md(l,r)+1<=tr)modify(md(l,r)+1,r,rc(u),tl,tr,d);
		pushup(u);
	}
	int query(int l,int r,int u,int tl,int tr){
		if(l>=tl&&r<=tr)return mx[u];pushdown(u);int res=-inf;
		if(md(l,r)>=tl)cmax(res,query(l,md(l,r),lc(u),tl,tr));
		if(md(l,r)+1<=tr)cmax(res,query(md(l,r)+1,r,rc(u),tl,tr));
		return res;
	}
	void fb(){build(1,n,1);}
	void fm(int tl,int tr,int d){if(tl<=tr)modify(1,n,1,tl,tr,d);}
	int fq(int tl,int tr){return query(1,n,1,tl,tr);}
}
int main(){
	T=read();
	while(T--){
		n=read(),r[0]=1;
		for(int i=1;i<=n;++i){
			p[a[i]=read()]=i;
			l[i]=i-1,r[i]=i+1;
		}
		SGT::fb();int ans=0;
		for(int i=1;i<=n;++i){
			erase(p[i]),SGT::fm(p[i],p[i],inf);
			SGT::fm(p[i],n,-2),cmax(ans,SGT::fq(r[0],n)+i);
		}
		write(ans);
	}
	return 0;
}