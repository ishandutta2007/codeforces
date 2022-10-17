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
}
inline int read() {int x; FI(x); return x;}
const int MN=2e5+5;
int a[MN],n,rt[MN],ans[MN];
struct SMT {
	static const int N=MN*100;
	int c[N][2],tot;
	#define ls c[k][0]
	#define rs c[k][1]
	#define mid ((l+r)>>1)
	void insert(int &k,int l,int r,int p) {
		if(!k) k=++tot; if(l==r) return;
		p<=mid?insert(ls,l,mid,p):insert(rs,mid+1,r,p); 
	}
	int ttot;
	void merge(int &a,int &b) {
		if(!a||!b) return a=a+b,void();
		merge(c[a][0],c[b][0]),merge(c[a][1],c[b][1]);	
	}
	void merge(int &k,int &lst,int l,int r,int ql,int qr) { //assign lst to k
		if(qr<l||ql>r||!lst) return;
		if(ql<=l&&r<=qr) {
			merge(k,lst); lst=0;
			return;
		}
		if(!k) k=++tot; assert(tot<N);
//		cerr<<lst<<' '<<c[lst][0]<<' '<<c[lst][1]<<endl;
		merge(ls,c[lst][0],l,mid,ql,qr),merge(rs,c[lst][1],mid+1,r,ql,qr);
//		cerr<<lst<<' '<<c[lst][0]<<' '<<c[lst][1]<<endl;
//		assert(!lst||(c[lst][0]||c[lst][1]));
	}
	void print(int k,int l,int r,int x) {
		if(!k) return;
		if(l==r) return ans[l]=x,void();
		print(ls,l,mid,x),print(rs,mid+1,r,x);
	}
}tr;
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read();
	For(i,1,n) {
		a[i]=read();	
		tr.insert(rt[a[i]],1,n,i);
	}
//	cerr<<tr.tot<<endl;
//	For(i,1,n) fprintf(stderr,"%d ",rt[i]);
//	fprintf(stderr,"\n");
	int q=read();
	while(q--) {
//		cerr<<q<<endl;
		int l=read(),r=read(),x=read(),y=read();
		if(x==y) continue;
		tr.ttot=0;
		tr.merge(rt[y],rt[x],1,n,l,r);
	cerr<<tr.tot<<' '<<tr.ttot<<endl;
//		mst(ans,0);
//		For(i,1,100) tr.print(rt[i],1,n,i);
//		For(i,1,n) {
//			printf("%d ",ans[i]);	
//		}
//		printf("\n");
	}
	mst(ans,0);
	For(i,1,100) tr.print(rt[i],1,n,i);
	For(i,1,n) {
		printf("%d ",ans[i]);	
	}
	printf("\n");
	return FastIO::Fflush(),0;
}