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
  void write(char x) {obuf[opt++]=x;if (opt>=(SIZE>>1)){fwrite(obuf,1,opt,stdout); opt=0;}}
	void Fflush() {if (opt) fwrite(obuf,1,opt,stdout); opt=0;}
};
inline int read() {int x; FI(x); return x;}
const int MN=2e5+5;
const int N=MN<<2;
int n,a[MN],q,b[MN];
#define ls (k<<1)
#define rs (k<<1|1)
#define mid ((l+r)>>1) 

struct ele {
	int x,y,z;
	ele(){x=-INF,y=INF,z=0;} ele(int X,int Y,int Z):x(X),y(Y),z(Z){}
	bool operator < (const ele &b) const {
		if(x!=b.x) return x<b.x;
		if(y!=b.y) return y<b.y;
		return z<b.z;
	}
	ele operator + (const ele &b) {
		ele ans;
		ans.x=max(x,z+b.x);	
		ans.y=min(y,z+b.y);	
		ans.z=z+b.z;
		return ans;
	}
}t[N];
void build(int k,int l,int r) {
	if(l==r) return t[k]=ele(a[l],a[l],a[l]),void();
	build(ls,l,mid),build(rs,mid+1,r);
	t[k]=t[ls]+t[rs];
}


ele qry(int k,int l,int r,int ql,int qr) {
	if(l>qr||r<ql) return ele();
	if(ql<=l&&r<=qr) return t[k];
	return qry(ls,l,mid,ql,qr)+qry(rs,mid+1,r,ql,qr);
}
int ans[N],L[N],R[N]; 
void works() {
	n=read(),q=read();
	For(i,1,n) a[i]=read();
	For(i,1,n) a[i]-=read();
	build(1,1,n);
	For(i,1,q) {
		L[i]=read(),R[i]=read();
		int l=L[i],r=R[i];
		ele it=qry(1,1,n,l,r);
//		cerr<<it.x<<' '<<it.y<<' '<<it.z<<endl;
		if(it.x>0||it.z) ans[i]=INF;
		ckmax(ans[i],-it.y);
	}
	reverse(a+1,a+1+n);
	For(i,1,n) a[i]=-a[i];
	For(i,1,q) L[i]=n-L[i]+1,R[i]=n-R[i]+1,swap(L[i],R[i]);
	
	build(1,1,n);
	For(i,1,q) {
		int l=L[i],r=R[i];
		ele it=qry(1,1,n,l,r);
		if(it.x>0||it.z) ans[i]=INF;
		ckmax(ans[i],-it.y);
	}
	For(i,1,q) {
		printf("%lld\n",ans[i]!=INF?ans[i]:-1);	
	}
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