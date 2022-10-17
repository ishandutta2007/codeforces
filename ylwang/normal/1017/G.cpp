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
inline int mul(int a,int b) {return 1ull*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline void fprint(const pii &x,char c='\n') {fprintf(stderr,"%d %d%c",x.first,x.second,c);}
inline void fprint(const int &x,char c=' ') {fprintf(stderr,"%d%c",x,c);}
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
const int MN=1e5+5,MB=2e3+5;
const int S=305;
int n,q,f[MN],col[MN]; vi e[MN];
pii o[MN];
struct ele {
	int x,y,z;
	ele(){} ele(int X,int Y,int Z):x(X),y(Y),z(Z){}
	bool operator < (const ele &b) const {
		if(x!=b.x) return x<b.x;
		if(y!=b.y) return y<b.y;
		return z<b.z;
	}
};
vector<ele>h[MN]; int vis[MN];
int cnt[MN],cov[MN];
void build(int u,int fa,int d,int w) {
	if(vis[u]) {
		if(fa) {
//			cerr<<fa<<' '<<u<<' '<<d<<' '<<w<<endl;
			h[fa].pb(ele(u,d,w));
		}
		for(int v:e[u]) {
//			cerr<<u<<' '<<v<<endl;
			build(v,u,0,0);
		}	
	} else {
		for(int v:e[u]) {
			build(v,fa,d+1,w+(!col[u]));
		}	
	}	
	
}
void modify1(int u) {
//	cerr<<u<<endl;
	if(col[u]==1) cnt[u]++;
	else col[u]=1,cnt[u]=0;
	for(auto &it:h[u]) { int v=it.x,d=it.y,w=it.z;
//	cerr<<u<<' '<<v<<' '<<cnt[u]<<' '<<w<<endl;
		if(w<cnt[u]) modify1(v);
	}
}
void modify2(int u) {
	col[u]=cnt[u]=0; cov[u]=1;
	for(auto &it:h[u]) {
		it.z=it.y; modify2(it.x);
	}
}
int tmp[MN];
void doit(int u,int nowcnt,int fl) {
	if(vis[u]) {
		nowcnt=cnt[u],fl|=cov[u];
	} else {
		col[u]=tmp[u];
		if(fl) col[u]=0;
		if(!col[u]&&nowcnt>0) nowcnt--,col[u]=1;
		
	}
	for(auto v:e[u]) {
		doit(v,nowcnt,fl);
	}	
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),q=read();
	For(i,2,n) { f[i]=read(); e[f[i]].pb(i);}
	
	For(i,1,q) o[i].first=read(),o[i].second=read();
	e[0].pb(1);
	for(int L=1,R;L<=q;L=R+1) {
		R=min(L+S-1,q);
//		cerr<<L<<' '<<R<<endl;
		For(i,1,n) tmp[i]=col[i],vis[i]=0,cov[i]=cnt[i]=0,h[i].clear();
		For(i,L,R) vis[o[i].second]=1;
		build(1,0,0,0);
		For(i,L,R) {
			if(o[i].first==1) {
				modify1(o[i].second);
//				fprint(col,n);
			} else if(o[i].first==2) {
				modify2(o[i].second);
			} else {
				printf(col[o[i].second]?"black\n":"white\n");
			}
		}
		doit(1,0,0);
	}
	
	return FastIO::Fflush(),0;
}