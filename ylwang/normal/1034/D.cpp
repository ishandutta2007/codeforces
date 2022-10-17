#include<bits/stdc++.h>
#define ll long long
#define pb push_back
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
#define INF ((1<<30)-1)
#define int long long
const int P=998244353; //
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
inline void fprint(const pii &x,char c=' ') {fprintf(stderr,"{%d,%d}%c",x.first,x.second,c);}
inline void fprint(const int *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const pii *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const vector<int> &f,char c='\n') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const vector<pii> &f,char c='\n') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); fprintf(stderr,"%c",c);}
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
  void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x=0; FI(x); return x;}
const int MN=3e5+5;
int n,K,L[MN],R[MN];
struct Node {
	int l,r,v; Node(){} Node(int L,int R=INF,int V=INF):l(L),r(R),v(V) {} 
	bool operator < (const Node &b) const {
		if(l!=b.l) return l<b.l;
		return r<b.r;		
	}
	
};
set<Node>s;
vector<pii>qr[MN];
auto split(int pos) {
	auto it=s.lower_bound(Node(pos,INF,INF)); 
	if(it!=s.end()&&(it->l)==pos) return it; it--;
//	cerr<<pos<<endl;
	int l=it->l,r=it->r,v=it->v; s.erase(it);
//	cerr<<l<<' '<<r<<endl;
	s.insert(Node(l,pos-1,v));
//	cerr<<l<<' '<<r<<endl;
	return s.insert(Node(pos,r,v)).first; 
}
int d[MN];
struct BIT {
	static const int N=MN; int c[N],n;
	void init(int N) {n=N; For(i,0,N) c[i]=0;}
	void upd(int x,int v) {for(;x;x-=x&-x) c[x]+=v; }
	int qry(int x) { int ans=0; for(;x<=n;x+=x&-x) ans+=c[x]; return ans; }
}tr;

int calc(int mid) { // >= mid
	tr.init(n+1);	int now=0,ans=0;
	
//	cerr<<"calc "<<mid<<endl;
	For(i,1,n) {
		for(auto it:qr[i]) {
			tr.upd(it.first,it.second);
//			cerr<<i<<' '<<it.first<<' '<<it.second<<endl;
		}
		while(now<i&&tr.qry(now+1)>=mid) now++;
		ans+=now;
//		cerr<<i<<' '<<now<<endl;
	}
	return ans;
}
int gc(int mid) {
	
	tr.init(n+1);	int now=0,ans=0,sum=0;
	For(i,1,n) {
		for(auto it:qr[i]) {
			sum+=(min(now,it.first))*it.second;
			tr.upd(it.first,it.second);
		}
		
//		cerr<<"! "<<i<<' '<<sum<<endl;
		while(now<i&&tr.qry(now+1)>=mid) now++,sum+=tr.qry(now);
		ans+=sum;
//		cerr<<"! "<<i<<' '<<sum<<endl;
	}
	return ans;
}

signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),K=read(); s.insert(Node(1,1e9,0)) ;
	For(i,1,n) {
		L[i]=read(),R[i]=read()-1;
	}
	For(i,1,n) {
		int l=L[i],r=R[i]; auto itr=split(r+1),itl=split(l);
		for(auto it=itl;it!=itr;) {
			int l=it->l,r=it->r,v=it->v;
//			cerr<<l<<' '<<r<<' '<<v<<endl;
			if(v) qr[i].pb(mkp(v,-(r-l+1)));
			auto tmp=it; it++; s.erase(tmp); 
		}
		s.insert(Node(l,r,i));
		qr[i].pb(mkp(i,(r-l+1)));
	}
//	For(i,1,n) {
//		fprint(qr[i]);	
//	}
//	cerr<<"?"<<endl;
	int l=0,r=1e9,ans=0;
	while(l<=r) { int mid=(l+r)>>1;
		if(calc(mid)>=K) l=mid+1,ans=mid;
		else r=mid-1;
	}
//	cerr<<ans<<' '<<gc(ans)<<' '<<calc(ans)<<endl;
	printf("%lld\n",gc(ans)-(calc(ans)-K)*ans);
	return FastIO::Fflush(),0;
}
/*
  
*/