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
#define INF (2e9)
#define int long long
const int P=998244353; //
using namespace std;
template<typename T>void ckmax(T &a,T b) {if(a<b) a=b; ;}
template<typename T>void ckmin(T &a,T b) {if(a>b) a=b; ;}
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
const int MN=2e5+5; 
const int dx[]={1,-1,0,0}; 
const int dy[]={0,0,1,-1}; 
int n,m;
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
vector<vi >a; 
vector<pii> fk; 
int chk(int x,int y) {
//	cerr<<x<<' '<<y<<endl;
	if(a[x][y]==1) return 1; 
	For(i,0,3) {
		int tx=x+dx[i],ty=y+dy[i]; 
		if(tx<=0||tx>n||ty<=0||ty>m) continue; 
//		cerr<<x<<' '<<y<<' '<<tx<<' '<<ty<<endl;
		if(a[tx][ty]<a[x][y]) return 1;  
	}
	return 0; 
}
int chk2() {
	for(auto it:fk) {
		if(!chk(it.first,it.second)) return 0; 
	}
//	fprint(fk); 
//	For(i,1,n) For(j,1,m) cerr<<a[i][j]<<' '; 
	
	return 1; 
}
set<ele>s; 
void works() {
	n=read(),m=read(); 
	a.resize(n+5); for(auto &it:a) it.resize(m+5);
	For(i,1,n) For(j,1,m) a[i][j]=read();
//	cerr<<"?"<<endl;
	int fl0=1; For(i,1,n) For(j,1,m) if(!chk(i,j)) fl0=0; 
	
//	cerr<<"?"; 
	if(fl0) return printf("0\n"),void(); 
	For(x,1,n) For(y,1,m) {
		if(!chk(x,y)) {
			cerr<<x<<' '<<y<<endl;
			fk.pb(mkp(x,y)); 
			For(i,0,3) {
				int tx=x+dx[i],ty=y+dy[i]; 
				if(tx<=0||tx>n||ty<=0||ty>m) continue; 
				fk.pb(mkp(tx,ty)); 
			}
		}
	}
	sort(fk.begin(),fk.end()); 
	fk.erase(unique(fk.begin(),fk.end()),fk.end()); 
	fprint(fk); 
	if(SZ(fk)>20) return printf("2\n"),void(); 
	int z=SZ(fk); 
	For(i,0,z-1) {
		int itx=fk[i].first,ity=fk[i].second; 
//		cerr<<itx<<' '<<ity<<endl;
		For(x,1,n) For(y,1,m) {
			
			int cnt=0; fk.pb(mkp(x,y)),cnt++; 
			For(i,0,3) {
				int tx=x+dx[i],ty=y+dy[i]; 
				if(tx<=0||tx>n||ty<=0||ty>m) continue; 
				fk.pb(mkp(tx,ty)); cnt++; 
			}
			swap(a[itx][ity],a[x][y]); 
			
			if(chk2()) {
//				cerr<<x<<' '<<y<<' '<<itx<<' '<<ity<<endl;
				s.insert(ele(itx,ity,x,y)); 
				s.insert(ele(x,y,itx,ity)); 
			}
			swap(a[itx][ity],a[x][y]); 
			while(cnt--) fk.pop_back(); 
		}
	}
//	For(i,1,n) For(j,1,m) cerr<<a[i][j]<<' '; 
//	cerr<<SZ(s)<<endl;
	if(SZ(s)) printf("1 %d\n",SZ(s)/2); 
	else printf("2\n"); 
} 
signed main() {
	#ifdef wasa855
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
  
*/