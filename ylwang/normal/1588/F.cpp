#include<bits/stdc++.h>
#define ll long long
#define pb emplace_back
#define mkp make_pair
#define vi vector<int>
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
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
  void write(int x) {
    if(!x) obuf[opt++]='0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
    if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}
  }
  void write(ll x) {
    if(!x) obuf[opt++]='0'; else {if(x<0) obuf[opt++]='-',x=-x;int sn=0; while(x)str[sn++]=x%10+'0',x/=10;for (int i=sn-1;i>=0;i--) obuf[opt++]=str[i];}
    if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}
  }
  void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x=0; FI(x); return x;}
const int MN=2e5+5,B=700;
int n,q,p[MN],op[MN],x[MN],y[MN];
int fl[MN],cyc[MN],nxt[MN],bel[MN],vis[MN],sz[MN]; 
int *pt,_pool[MN],*t[MN];
ll s[MN],S[MN],val[MN];
void solve(int L,int R) {
	mst(bel,0),mst(vis,0);
	
	For(i,L,R) {
		if(op[i]==2) fl[x[i]]=1;
		else fl[x[i]]=fl[y[i]]=1;
	}
	vi ky;
	For(i,1,n) if(!vis[i]&&fl[i]) {
		static int cyc[MN];
		int u=i,cnt=0; do { cyc[++cnt]=u,vis[u]=1,u=p[u]; } while(u!=i);
		for(int i=cnt;i>=1;i--) {
			if(fl[cyc[i]]) nxt[cyc[i]]=u,u=cyc[i],ky.pb(cyc[i]);
			bel[cyc[i]]=u,sz[u]++;
		}
	}
	pt=_pool;
	for(auto i:ky) t[i]=pt+1,pt+=sz[i],sz[i]=0;
	For(i,1,n) if(bel[i]) t[bel[i]][++sz[bel[i]]]=i;
	For(now,L,R) {
		int op=::op[now],x=::x[now],y=::y[now];
		if(op==1) {
			ll ans=s[y]-s[x-1];
			for(auto it:ky) {
				int r=upper_bound(t[it]+1,t[it]+1+sz[it],y)-t[it]-1,l=lower_bound(t[it]+1,t[it]+1+sz[it],x)-t[it];
				ans+=1ull*(r-l+1)*val[it];
			}
			FO(ans); FO('\n');
		} else if(op==2) {
			int u=x; do {val[u]+=y,u=nxt[u];} while(u!=x); 
		} else swap(nxt[x],nxt[y]),swap(p[x],p[y]);
	}
	For(i,1,n) S[i]=(bel[i]?val[bel[i]]:0)+S[i-1],s[i]+=S[i];
	for(auto i:ky) sz[i]=val[i]=nxt[i]=0;
	For(i,L,R) {
		if(op[i]==2) fl[x[i]]=0;
		else fl[x[i]]=fl[y[i]]=0;
	}
	
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read();
	For(i,1,n) s[i]=read()+s[i-1];
	For(i,1,n) p[i]=read();
	q=read();
	For(i,1,q) {
		op[i]=read(),x[i]=read(),y[i]=read();	
	}
	for(int l=1,r;l<=q;l=r+1) {
		r=min(q,l+B-1); solve(l,r);
	}
	return FastIO::Fflush(),0;
}