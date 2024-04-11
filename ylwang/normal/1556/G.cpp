#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define ull unsigned long long
#define mst(a,b) memset(a,b,sizeof(a))
#define foR(i,k,j) for(int i=(k);i>=(j);i--)
#define For(i,k,j) for(int i=(k);i<=(j);i++)
#define Foe(i,u) for(int i=lst[u],v=e[i].v;i;i=e[i].nxt,v=e[i].v)
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define Fin(s) freopen(s,"r",stdin)
#define Fout(s) freopen(s,"w",stdout)
#define file(s) Fin(s".in"),Fout(s".out")
#define INF ((1ll<<60)-1)
//#define int long long
const int P=1e9+7; //
using namespace std;
template<typename T>inline void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>inline void ckmin(T &a,T b) {(a>b)&&(a=b);}
inline int mul(int a,int b) {return 1ull*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline void fprint(const int &x,char c=' ') {fprintf(stderr,"%d%c",x,c);}
inline void fprint(const pii &x,char c='\n') {fprintf(stderr,"%d %d%c",x.first,x.second,c);}
inline void fprint(const int *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const vector<int> &f,char c='\n') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline int inv(int a) {return ksm(a,P-2);}
namespace FastIO {
  const int SIZE=1<<16; char buf[SIZE],obuf[SIZE],str[64]; int bi=SIZE,bn=SIZE,opt;
  int read(char *s) {
    while (bn) {for (;bi<bn&&buf[bi]<=' ';bi++);if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}
    int sn=0;while (bn) {for (;bi<bn&&buf[bi]>' ';bi++) s[sn++]=buf[bi];if (bi<bn) break; bn=fread(buf,1,SIZE,stdin),bi=0;}s[sn]=0;return sn;
  }
  bool read(int& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
  bool read(ll& x) {if(x)x=0;int bf=0,n=read(str); if(!n) return 0; int i=0; if (str[i]=='-') bf=1,i=1; for(x=0;i<n;i++) x=x*10+str[i]-'0'; if(bf) x=-x; return 1;}
  void write(int x) {
    if(!x) obuf[opt++]='0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
    if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}
  }
  void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
inline ll read_ll() {ll x; FI(x); ; return x;}
const int MN=52,MM=5e4+5,N=MN*MM*2;
int n,m;
struct Qry {
	int o; ll l,r;	
}qr[MM];

int stot=0,a[N],rt,tot,ls[N],rs[N];
bool vis[N];
vi e[N/2],g[MM];
#define mid ((l+r)>>1)
void upd(int &k,ll l,ll r,ll ql,ll qr) {
	if(ql>r||qr<l||l>r) return; if(!k) k=++stot; 
	if(ql<=l&&r<=qr) return a[k]=++tot,void();
	upd(ls[k],l,mid,ql,qr),upd(rs[k],mid+1,r,ql,qr);
}
void build(int p,int q,int nowd,int d) {
	if(!p||!q) return;
	if(nowd>d) { 
		if(a[p]) return; build(ls[p],ls[q],nowd-1,d),build(rs[p],rs[q],nowd-1,d); return; 
	}
	if(nowd==d) {
		if(a[p]) return; build(ls[p],rs[q],nowd-1,d); return;
	}
	if(a[p]&&a[q]) {
		e[a[p]].pb(a[q]),e[a[q]].pb(a[p]);
	} else if(a[p]) {
		build(p,ls[q],nowd-1,d),build(p,rs[q],nowd-1,d);
	} else if(a[q]) {
		build(ls[p],q,nowd-1,d),build(rs[p],q,nowd-1,d);
	} else {
		build(ls[p],ls[q],nowd-1,d),build(rs[p],rs[q],nowd-1,d);
	}
}
void qry(int k,ll l,ll r,ll ql,ll qr,int x) {
	if(!k||ql>r||qr<l) return;
	if(ql<=l&&r<=qr) return g[x].pb(a[k]),vis[a[k]]=1,void();
	qry(ls[k],l,mid,ql,qr,x),qry(rs[k],mid+1,r,ql,qr,x);
	
}
int get(ll x) { int k=rt;
	for(int i=n-1;i>=0;i--) {
		if(a[k]) return a[k];
		if(x>>i&1) k=rs[k];
		else k=ls[k];
	}
	if(a[k]) return a[k];
	return -1;
}
int f[N];
inline int find(int x) {return x==f[x]?x:f[x]=find(f[x]);}
void insert(int u) {
	f[u]=u;
	for(auto v:e[u]) {
		if(f[v]) {
			f[find(u)]=find(v);
		}
	}
}
void works() {
	n=read(),m=read(); ll ALL=(1ll<<n);
	vector<ll> pos;
	For(i,1,m) {
		char s[55]; FI(s); 
		ll L=read_ll();
//		cerr<<L<<endl;
		qr[i].l=L,qr[i].r=read_ll();
//		cerr<<qr[i].l<<' '<<qr[i].r<<endl;
		qr[i].o=s[0]=='b';
		if(qr[i].o==1) {
			pos.pb(qr[i].l),pos.pb(qr[i].r+1);
		}
	} pos.pb(0),pos.pb(ALL);
	
	sort(pos.begin(),pos.end());
	pos.erase(unique(pos.begin(),pos.end()),pos.end());
	for(int i=0;i+1<(int)pos.size();i++) {
		upd(rt,0,ALL-1,pos[i],pos[i+1]-1);
	}
	For(d,0,n-1) {
		build(rt,rt,n-1,d);
	}
	For(i,1,m) {
		if(qr[i].o==1) {
			qry(rt,0,ALL-1,qr[i].l,qr[i].r,i);
		}	
	}
	For(u,1,tot) if(!vis[u]) {
		insert(u);
	}
	vi fans; 
	foR(i,m,1) {
		if(qr[i].o==1) {
			for(auto u:g[i])
				insert(u);
		}	else {
			ll x=qr[i].l,y=qr[i].r;
			x=get(x),y=get(y);
			x=find(x),y=find(y);
			fans.pb(x==y?1:0);
		}
	}
	reverse(fans.begin(),fans.end());
	for(auto it:fans) printf("%d\n",it);
	
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	int T=1; 
	while(T--) {
		works();
	}
	return FastIO::Fflush(),0;
}
/*
3
1
3
0
3

2
*/