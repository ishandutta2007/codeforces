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
#define INF ((1<<30)-1)
#define int long long
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
inline int ksm(int a,int b) {if(b<0) return 1; int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
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
inline int read() {int x=0; FI(x); return x;} // !
const int MN=1e5+5;
int n,a[MN],rt[10],tot,q,val[10][MN];
#define ls c[k][0]
#define rs c[k][1]
#define mid ((l+r)>>1)
const int N=MN*4*20;
int t[N],c[N][2];
void pushup(int k) {
	t[k]=t[ls]+t[rs];	
}
void build(int &k,int l,int r,int *v) {
	k=++tot;
	if(l==r) return t[k]=v[l],void();
	build(ls,l,mid,v),build(rs,mid+1,r,v);
	pushup(k);
}
void doit(int &k,int &lst,int l,int r,int ql,int qr) {
	if(!lst||l>qr||r<ql) return; 
	if(ql<=l&&r<=qr) {
		if(!k) {
			int x=lst; 
			return k=x,lst=0,void();
		}
		if(l==r) t[k]+=t[lst];
		else doit(ls,c[lst][0],l,mid,ql,qr),doit(rs,c[lst][1],mid+1,r,ql,qr),pushup(k);
		lst=0; return;
	}
	if(!k) k=++tot;
	doit(ls,c[lst][0],l,mid,ql,qr),doit(rs,c[lst][1],mid+1,r,ql,qr);
	pushup(k),pushup(lst);
}
int qry(int k,int l,int r,int ql,int qr) {
	if(!k||l>qr||r<ql) return 0; if(ql<=l&&r<=qr) return t[k];
	return qry(ls,l,mid,ql,qr)+qry(rs,mid+1,r,ql,qr);
}

signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),q=read(); For(i,1,n) a[i]=read();
	For(o,0,9) {
		For(i,1,n) {
			int x=a[i],p=1;
			while(x) {
				if(x%10==o) val[o][i]+=p;
				p*=10,x/=10;
			}
		}
//		fprint(val[o],n);
		build(rt[o],1,n,val[o]);
	}
	while(q--) {
		int op=read(),l=read(),r=read();
		if(op==1) {
			int x=read(),y=read();
			if(x!=y) doit(rt[y],rt[x],1,n,l,r);	
		} else {
			int ans=0;
//			cerr<<l<<' '<<r<<endl;
			For(i,1,9) {
				ans+=i*qry(rt[i],1,n,l,r);
//				cerr<<i<<' '<<qry(rt[i],1,n,l,r)<<endl;
			}
			FO(ans); FO('\n');
//			cerr<<endl;
		}
			
	}
	return FastIO::Fflush(),0;
}
/*
  
*/