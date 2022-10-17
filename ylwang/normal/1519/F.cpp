#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mkp make_pair
#define vi vector<int>
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
#define pii pair<int,int>
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
const int MN=6;
int n,m,a[MN],b[MN],c[MN][MN];
struct state {
	vector<int>t; int v1,v2,r;
	state() {} state(vi T,int V1,int V2,int R) : t(T),v1(V1),v2(V2),r(R) {}
};
int Hash(vi &v) {
	int ans=0;
	for(auto it:v) ans=ans*5+it;
	return ans;	
}
vi gvi(int x) {
	vi ans(n);
	foR(i,n-1,0) {
		ans[i]=x%5; x/=5;
	}
	return ans;
}
int Hash(state &v) {
	int ans=Hash(v.t);
	ans=ans*6+v.v2;ans=ans*6+v.v1;
	ans=ans*5+v.r; return ans;
}
state gst(int x) {
	int r=x%5; x/=5;
	int v1=x%6; x/=6;
	int v2=x%6; x/=6;
	return state(gvi(x),v1,v2,r);
}
const int N=5e6+5,TN=N-5; int f[N];
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),m=read();
	For(i,0,n-1) a[i]=read();	
	For(i,0,m-1) b[i]=read();
	For(i,0,n-1) {
		For(j,0,m-1) c[i][j]=read();
	}
	mst(f,127/2); f[0]=0; int ans=1e9;
	For(i,0,TN-1) {
		if(f[i]>1e9) continue;
		state now=gst(i),nxt;
		For(o,0,4) {
			int u=now.v1,v=now.v2;
			if(now.t[u]+o>a[u]) continue;
			if(now.r+o>b[v]) continue;
			int add=(!!o)*c[u][v];
			nxt=now; nxt.t[u]+=o,nxt.r+=o;
			if(u==n-1) {
				nxt.v1=0,nxt.v2++,nxt.r=0;	
			} else nxt.v1++;
			if(nxt.t==vi(a,a+n)) {
//				fprint(nxt.t);
//				cerr<<i<<endl;
				ckmin(ans,f[i]+add);
			}
			if(nxt.v2<m) ckmin(f[Hash(nxt)],f[i]+add);
		}
	}
	if(ans>=1e9) ans=-1; cout<<ans<<endl;
	return FastIO::Fflush(),0;
}