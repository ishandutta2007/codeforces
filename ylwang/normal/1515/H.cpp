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
#define INF ((1<<30)-1)
//#define int long long
const int P=998244353; //
using namespace std;
template<typename T>inline void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>inline void ckmin(T &a,T b) {(a>b)&&(a=b);}
inline int mul(int a,int b) {return 1ll*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline void fprint(const vector<int> &f) {for(int i=0;i<(int)f.size();i++) fprintf(stderr,"%d ",f[i]); fprintf(stderr,"\n");}
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
const int M=(1<<20)-1;
int n,q,m=20;
struct Trie {
	static const int N=MN*45;
	int c[N][2],tot=1,cnt[N],rev[N],dep[N],t[2][N];
	
	#define ls (c[k][0])
	#define rs (c[k][1])
	void pushup(int k) {
		cnt[k]=cnt[ls]+cnt[rs];
		t[0][k]=t[0][ls]|t[0][rs];
		t[1][k]=t[1][ls]|t[1][rs];
	}
	void pushr(int k,int v) {
		if(!k) return;
		rev[k]^=v;
		if(dep[k]!=-1) {
			if(v>>dep[k]&1) swap(ls,rs);
		}
		int x=(t[0][k]&(~v))|(t[1][k]&v),y=(t[1][k]&(~v))|(t[0][k]&v);
		t[0][k]=x,t[1][k]=y;
			
	}
	void pushdown(int k) {
		if(rev[k]) {
			pushr(ls,rev[k]),pushr(rs,rev[k]);
			rev[k]=0;
		}
	}
	void insert(int &k,int d,int x) {
		if(!k) k=++tot; dep[k]=d;
//		cerr<<k<<' '<<d<<' '<<x<<endl; 
		if(d==-1) return cnt[k]=1,t[1][k]=x&M,t[0][k]=t[1][k]^M,void();
		(x>>d&1)?insert(rs,d-1,x):insert(ls,d-1,x);	
		pushup(k);
	}
	#define mid ((l+r)>>1)
	void split(int &p,int &q,int l,int r,int ql,int qr) {
		if(!p||r<ql||l>qr) return q=0,void();
//		cerr<<p<<' '<<q<<' '<<l<<' '<<r<<' '<<ql<<' '<<qr<<endl;
		if(ql<=l&&r<=qr) return q=p,p=0,void(); pushdown(p);
		dep[q=++tot]=dep[p];
		split(c[p][0],c[q][0],l,mid,ql,qr);
		split(c[p][1],c[q][1],mid+1,r,ql,qr);
//		cerr<<q<<' '<<c[q][0]<<' '<<c[q][1]<<' '<<cnt[c[q][0]]<<' '<<cnt[c[q][1]]<<endl;
		pushup(p),pushup(q);
	}
	void merge(int &p,int q) {
		if(!p||!q) return p=p|q,void();
		pushdown(p),pushdown(q); 
		merge(c[p][0],c[q][0]),merge(c[p][1],c[q][1]);
		if(dep[p]!=-1) pushup(p);
	}
	void Mor(int k,int x) {
		if(!k) return;
		if(!(x&t[0][k]&t[1][k])) return pushr(k,x&t[0][k]);
		pushdown(k);
		if(x>>dep[k]&1) pushr(ls,1<<dep[k]),merge(rs,ls),ls=0;
		Mor(ls,x),Mor(rs,x);
		pushup(k);
	}
}tr;
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),q=read(); int p=0;
	For(i,1,n) {
		tr.insert(p,m-1,read());	
	}
//	cerr<<"?";
//	cerr<<tr.cnt[p]<<endl;
//	cerr<<p<<endl;
	while(q--) {
//		cerr<<"!"<<q<<endl;
		int op=read(),l=read(),r=read(),x=(op!=4?read():0),q=0;
//		cerr<<op<<' '<<l<<' '<<r<<endl;
		
		tr.split(p,q,0,M,l,r);
//		cerr<<q<<endl;
		if(op==1) tr.pushr(q,M),tr.Mor(q,x^M),tr.pushr(q,M);
		if(op==2) tr.Mor(q,x);
		if(op==3) tr.pushr(q,x);
		if(op==4) printf("%d\n",tr.cnt[q]);
//		cerr<<q<<endl;
		tr.merge(p,q);
	}
	return FastIO::Fflush(),0;
}