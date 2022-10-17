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
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define Fin(s) freopen(s,"r",stdin)
#define Fout(s) freopen(s,"w",stdout)
#define file(s) Fin(s".in"),Fout(s".out")
#define INF ((1ll<<60)-1)
#define int long long
const int P=998244353; //
using namespace std;
template<typename T>void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>void ckmin(T &a,T b) {(a>b)&&(a=b);}
inline int mul(int a,int b) {return 1ull*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
void fprint(const int &x,char c=' ') {fprintf(stderr,"%d%c",x,c);}
void fprint(const pii &x,char c=' ') {fprintf(stderr,"{%d,%d}%c",x.first,x.second,c);}
template<typename T> void fprint(const T &f) { for(auto &it:f) fprint(it); fprintf(stderr,"%c",'\n');}
template<typename T> void fprint(const T *f,const int &n) {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",'\n');}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
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
const int MN=1e6+5;
int n,q,a[MN],pos[MN];
vector<pii>qr[MN];
struct SMT {
	static const int N=MN<<2;
	int sa[N],sb[N],t[N],taga[N],tagb[N]; 
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid ((l+r)>>1)
	void init() { For(i,1,N-2) taga[i]=0,tagb[i]=0; }
	void pushr(int k,int l,int r,int A,int B) {
		sa[k]+=(r-l+1)*A,taga[k]+=A;
		sb[k]+=(r-l+1)*B,tagb[k]+=B;
	}
	void pushup(int k) {
		t[k]=t[ls]+t[rs];
		sa[k]=sa[ls]+sa[rs];
		sb[k]=sb[ls]+sb[rs];
	}
	void pushdown(int k,int l,int r) {
		pushr(ls,l,mid,taga[k],tagb[k]),pushr(rs,mid+1,r,taga[k],tagb[k]);
		taga[k]=tagb[k]=0; 
	}
	void upd(int k,int l,int r,int ql,int qr,int A,int B) {
		if(l>qr||r<ql) return ; if(ql<=l&&r<=qr) return pushr(k,l,r,A,B); pushdown(k,l,r);
		upd(ls,l,mid,ql,qr,A,B),upd(rs,mid+1,r,ql,qr,A,B);
		pushup(k);
	}
	int qry(int k,int l,int r,int ql,int qr,int p) {
		if(l>qr||r<ql) return 0; if(ql<=l&&r<=qr) return p*sa[k]+sb[k]; pushdown(k,l,r);
		return qry(ls,l,mid,ql,qr,p)+qry(rs,mid+1,r,ql,qr,p);
	}
} tr;
struct ele {
	int x,y,z;
	ele(){} ele(int X,int Y,int Z):x(X),y(Y),z(Z){}
	bool operator < (const ele &b) const {
		if(x!=b.x) return x<b.x;
		if(y!=b.y) return y<b.y;
		return z<b.z;
	}
};

vi d[MN];
int s[MN],top,ins[MN],r[MN],ans[MN];
vector<ele>op[MN];
void rmv(int j,int r) {
	for(auto it:op[j]) {
//		cerr<<it.x<<' '<<it.y<<' '<<it.z<<endl;
		tr.upd(1,1,n,it.x,it.y,-1,(it.z-1));
		tr.upd(1,1,n,it.x,it.y,0,(r-it.z));
	}	
//	cerr<<"? "<<j<<' '<<r<<endl;
}
signed main() { 
	#ifdef wasa855
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),q=read();
	For(i,1,n) a[i]=read(),pos[a[i]]=i;
	For(i,1,n) for(int j=i+i;j<=n;j+=i) d[j].pb(i);
	For(i,1,q) {
		int l=read(),r=read();
		qr[r].pb(mkp(l,i));	
	}
	
	For(i,1,n) {
		while(top>0&&a[i]>a[s[top]]) {
			ins[a[s[top]]]=0; rmv(a[s[top]],i);
			top--;
		}
		for(int j=a[i];j<=n;j+=a[i]) {
			int k=j/a[i],nr=min(pos[k],pos[j]); if(pos[k]>i) continue;
			if(k==a[i]) continue;
			if(ins[j]&&nr>r[j]) {
				tr.upd(1,1,n,r[j]+1,nr,1,-(i-1)); op[j].pb(ele(r[j]+1,nr,i));
				r[j]=nr;	
			}
		}
		r[a[i]]=s[top];
		for(auto j:d[a[i]]) if(j*j!=a[i]&&pos[j]<=i&&pos[a[i]/j]<=i) ckmax(r[a[i]],min(pos[j],pos[a[i]/j]));
		tr.upd(1,1,n,s[top]+1,r[a[i]],1,-(i-1)); op[a[i]].pb(ele(s[top]+1,r[a[i]],i));
//		fprint(r,n);
		s[++top]=i,ins[a[i]]=1;
		
		for(auto it:qr[i]) {
			int x=it.first,y=it.second;
			ans[y]=tr.qry(1,1,n,x,i,i);	
		}
	}
	For(i,1,q) {
		FO(ans[i]); FO('\n');	
	}
	return FastIO::Fflush(),0;
}
/*
  
*/