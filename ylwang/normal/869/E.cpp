#pragma GCC optimize("Ofast")
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
inline int read() {int x=0; FI(x); return x;}
const int MN=2505+5;
int n,m,q;
ull c[MN][MN];
void Upd(int x,int y,ull v) {
//	cerr<<x<<' '<<y<<' '<<v<<endl;
	for(int i=x;i<=n;i+=i&-i) for(int j=y;j<=m;j+=j&-j) c[i][j]+=v;	
}
void upd(int x,int y,int r,int c,ull v) {
//	cerr<<x<<' '<<y<<' '<<r<<' '<<c<<' '<<v<<endl;
	Upd(r+1,c+1,v);
	Upd(r+1,y,-v);
	Upd(x,c+1,-v);
	Upd(x,y,v);
//	For(i,x,r) For(j,y,c) ::c[i][j]+=v;
}
ull qry(int x,int y) {
//	return c[x][y];
//	cerr<<endl;
	ull ans=0;
	for(int i=x;i;i-=i&-i) for(int j=y;j;j-=j&-j) ans+=c[i][j];
	return ans; 
}
mt19937_64 rnd(2323);
struct ele {
	int x,y,z,w;
	ele(){} ele(int X,int Y,int Z,int W):x(X),y(Y),z(Z),w(W){}
	bool operator < (const ele &b) const {
		if(x!=b.x) return x<b.x;
		if(y!=b.y) return y<b.y;
		if(z!=b.z) return z<b.z;
		return w<b.w;
	}
};

map<ele,ull>val;
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),m=read(),q=read();
	while(q--) {
		int op=read(),x=read(),y=read(),r=read(),c=read();
		if(op==1) {
			ull v=rnd(); val[ele(x,y,r,c)]=v;
			upd(x,y,r,c,v);
		} else if(op==2) {
			ull v=val[ele(x,y,r,c)]; val.erase(ele(x,y,r,c));
			upd(x,y,r,c,-v);
		} else {
//			cerr<<qry(x,y)<<' '<<qry(r,c)<<endl;
			printf(qry(x,y)==qry(r,c)?"Yes\n":"No\n");
		}
	}
	return FastIO::Fflush(),0;
}
/*
?t??? 1??? 12?
*/