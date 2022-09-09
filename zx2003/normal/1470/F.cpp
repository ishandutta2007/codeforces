#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,I=1<<30;
int T,n,i,j,k;
ll ans;
struct P{int x,y;}a[N];
struct info{
	int l,r,d,u;
	info(int _l=I,int _r=0,int _d=I,int _u=0):l(_l),r(_r),d(_d),u(_u){}
	inline info operator+(info a){return (info){min(l,a.l),max(r,a.r),min(d,a.d),max(u,a.u)};}
	inline void ins(const P&a){l=min(l,a.x);r=max(r,a.x);d=min(d,a.y);u=max(u,a.y);}
	inline ll area(){return 1ll*(r-l)*(u-d);}
}A;
inline bool cmpx(const P&a,const P&b){return a.x<b.x;}
namespace N1{
info ps[N],ss[N];
inline void solve(){
	sort(a+1,a+n+1,cmpx);
	ps[0]=ss[n+1]=info();
	for(i=1;i<=n;++i)ps[i]=ps[i-1],ps[i].ins(a[i]);
	for(i=n;i;--i)ss[i]=ss[i+1],ss[i].ins(a[i]);
	for(i=1;i<n;++i)ans=min(ans,ps[i].area()+ss[i+1].area());
}
inline void main(){
	solve();
	for(i=1;i<=n;++i)swap(a[i].x,a[i].y);swap(A.l,A.d);swap(A.r,A.u);
	solve();
}
}
namespace N2{
P b1[N],b2[N];int w1,w2;
inline P operator-(const P&a,const P&b){return P{a.x-b.x,a.y-b.y};}
inline ll cross(const P&a,const P&b){return 1ll*a.x*b.y-1ll*b.x*a.y;}
inline ll dot(const P&a,const P&b){return 1ll*a.x*b.x+1ll*a.y*b.y;}
vector<P>T[N*3];int pos[N*3];
void build(int i,int l,int r){
	static P st[N];int w=0;
	for(int i=l;i<=r;++i){
		P u=P{b2[i].x-A.l,b2[i+1].y-A.d};
		for(;w>1 && cross(u-st[w-1],st[w]-st[w-1])>=0;--w);st[++w]=u;
	}
	T[i]=vector<P>(st+1,st+w+1);pos[i]=w-1;
	if(l==r)return;int m=l+r>>1;build(i<<1,l,m);build(i<<1|1,m+1,r);
}
inline ll ask(int i,int l,int r,int ql,int qr,P p){
	if(ql<=l && r<=qr){
		for(;pos[i] && dot(p,T[i][pos[i]])>=dot(p,T[i][pos[i]-1]);--pos[i]);
		return dot(p,T[i][pos[i]]);
	}
	int m=l+r>>1;return min(ql<=m?ask(i<<1,l,m,ql,qr,p):1ll<<61,m<qr?ask(i<<1|1,m+1,r,ql,qr,p):1ll<<61);
}
inline void solve(){
	sort(a+1,a+n+1,cmpx);w1=w2=0;
	for(i=1;i<=n;++i)if(!w1 || (b1[w1].x<a[i].x && b1[w1].y>a[i].y))b1[++w1]=a[i];
		else if(w1 && b1[w1].x==a[i].x)b1[w1].y=min(b1[w1].y,a[i].y);
	for(i=n;i;--i)if(!w2 || (b2[w2].x>a[i].x && b2[w2].y<a[i].y))b2[++w2]=a[i];
		else if(w2 && b2[w2].x==a[i].x)b2[w2].y=max(b2[w2].y,a[i].y);
	if(w1==1 || w2==1)return;
	reverse(b2+1,b2+w2+1);
	build(1,1,w2-1);
	int p1=1,p2=0;
	for(i=j=k=1;i<w1;++i){
		for(;p1<w2 && b1[i+1].x>b2[p1].x;++p1);
		for(;p2+1<w2 && b1[i].y<=b2[p2+2].y;++p2);
		if(p1<=p2)ans=min(ans,ask(1,1,w2-1,p1,p2,P{A.u-b1[i].y,A.r-b1[i+1].x}));
	}
}
inline void main(){
	solve();
	for(i=1;i<=n;++i)a[i].x=I-a[i].x;swap(A.l=I-A.l,A.r=I-A.r);
	solve();
}
}
namespace N3{
info ps[N],ss[N];int M;
inline bool contain(const info&a,const info&b){return a.u>=b.u && b.d>=a.d;}
struct segtree{
	ll T[N*3];
	segtree(){for(i=0;i<N*3;++i)T[i]=1ll<<61;}
	inline void ini(){for(i=M-1;i;--i)T[i]=min(T[i<<1],T[i<<1|1]);}
	inline ll ask(int l,int r){
		ll ans=1ll<<61;
		for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1){
			if(!(l&1))ans=min(ans,T[l^1]);
			if(r&1)ans=min(ans,T[r^1]);
		}
		return ans;
	}
}T1,T2,T3;
inline void main(){
	sort(a+1,a+n+1,cmpx);ps[0]=ss[n+1]=info();
	ps[0]=ss[n+1]=info();
	for(i=1;i<=n;++i)ps[i]=ps[i-1],ps[i].ins(a[i]);
	for(i=n;i;--i)ss[i]=ss[i+1],ss[i].ins(a[i]);
	for(M=1;M<n+2;M<<=1);
	for(i=1;i<=n;++i)T1.T[M+i]=1ll*a[i].x*(A.u-A.d)-1ll*ss[i+1].d*(A.r-A.l);T1.ini();
	for(i=1;i<=n;++i)T2.T[M+i]=1ll*a[i].x*(A.u-A.d)+1ll*ss[i+1].u*(A.r-A.l);T2.ini();
	for(i=1;i<=n;++i)T3.T[M+i]=1ll*a[i].x*(A.u-A.d)+1ll*(ss[i+1].u-ss[i+1].d)*(A.r-A.l);T3.ini();
	for(i=1;i<=n;++i){
		int l,r,m,p1,p2;
		for(l=i,r=n;l<r;)m=l+r>>1,contain(ps[i-1],ss[m+1])?r=m:l=m+1;p1=l;
		for(l=i,r=p1;l<r;)m=l+r>>1,!contain(ss[m+1],ps[i-1])?r=m:l=m+1;p2=l;
		ans=min(ans,1ll*(a[p1].x-a[i].x)*(A.u-A.d)+max(0ll,1ll*(ps[i-1].u-ps[i-1].d)*(A.r-A.l)));
		if(p2<p1){
			if(ss[p2+1].d<ps[i-1].d){
				ans=min(ans,T1.ask(p2,p1-1)-1ll*a[i].x*(A.u-A.d)+1ll*ps[i-1].u*(A.r-A.l));
			}else{
				ans=min(ans,T2.ask(p2,p1-1)-1ll*a[i].x*(A.u-A.d)-1ll*ps[i-1].d*(A.r-A.l));
			}
		}
		if(i<p2)ans=min(ans,T3.ask(i,p2-1)-1ll*a[i].x*(A.u-A.d));
	}
}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	for(cin>>T;T--;){
		cin>>n;
		A=info();
		for(i=1;i<=n;++i)cin>>a[i].x>>a[i].y,A.ins(a[i]);
		ans=A.area();if(!ans){cout<<ans<<'\n';continue;}
		N3::main();N2::main();N1::main();cout<<ans<<'\n';
	}
}