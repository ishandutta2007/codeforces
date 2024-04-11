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
//const int P=998244353; //
using namespace std;
template<typename T>inline void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>inline void ckmin(T &a,T b) {(a>b)&&(a=b);}
//inline int mul(int a,int b) {return 1ull*a*b%P;}
//inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
//inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
//inline void mulmod(int &a,int b) {a=mul(a, b);}
//inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
//inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
//inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline void fprint(const pii &x,char c='\n') {fprintf(stderr,"%d %d%c",x.first,x.second,c);}
inline void fprint(const int &x,char c=' ') {fprintf(stderr,"%d%c",x,c);}
inline void fprint(const int *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const vector<int> &f,char c='\n') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); fprintf(stderr,"%c",c);}
//inline int inv(int a) {return ksm(a,P-2);}
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
int n,m; struct Edge {int v,A,B;};
vector<Edge>e[MN];
#define s128 __int128 
struct P {ll x,y; P(){} P(ll X,ll Y):x(X),y(Y){} 
	bool operator < (const P &b) const {return x!=b.x?x<b.x:y<b.y;}	
	bool operator == (const P &b) const {return x==b.x&&y==b.y;}	
};
P operator + (const P &a,const P &b) { return P(a.x+b.x,a.y+b.y);}
P operator - (const P &a,const P &b) { return P(a.x-b.x,a.y-b.y);}
P dot(const P &a,const P &b) { return P((s128)a.x*b.x,(s128)a.y*b.y);}
s128 cross(const P &a,const P &b) { return a.x*b.y-a.y*b.x; }
bool check(const P &a,const P &b,const P &c) { // check whether bc is on the counterclockwise of ab
//cerr<<(int)cross(b-a,c-a)<<endl;
	return cross(b-a,c-a)>0;
}
bool cmp(const P &a,const P &b) {
	return atan2(a.y,a.x)>atan2(b.y,b.x);	
}
#define double long double
double slope(const P &a,const P &b) {
	return (double)(b.y-a.y)/(b.x-a.x);
}

inline void fprint(const P &x,char c=' ') {fprintf(stderr,"{%lld,%lld}%c",x.x,x.y,c);}
inline void fprint(const P *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const vector<P> &f,char c='\n') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); fprintf(stderr,"%c",c);}

struct Hull {
	vector<P>H;
	Hull() {H.clear();}  void add(P A) {H.pb(A);}
	void build() { sort(H.begin(),H.end());	H.erase(unique(H.begin(),H.end()),H.end());
		vector<P>ans;
//		fprint(H);
		for(auto it:H) {
			while(ans.size()>=1&&ans[ans.size()-1].y<=it.y) ans.pop_back(); 
			while(ans.size()>=2&&check(ans[ans.size()-2],ans[ans.size()-1],it)) {
				ans.pop_back();	
			} ans.push_back(it);
		}
		H=ans;
	}
	void printans() {
		if(!H.size()) {
			while(m--) printf("0 ");
			return;
		}
		int now=0;
		for(int i=0;i<H.size()-1;i++) {
			double slp=abs(slope(H[i],H[i+1]));
//			cerr<<i<<' '<<slp<<endl;
			while(now<m&&now<=slp) {
				printf("%lld ",now*H[i].x+H[i].y),now++;
			}
		}
		while(now<m) {
			printf("%lld ",now*H[H.size()-1].x+H[H.size()-1].y),now++;
		}
	}
	inline unsigned size() {return H.size();}
};
inline void fprint(const Hull &x) { fprint(x.H);}
Hull operator + (Hull &A,Hull &B) {
	if(!A.size()) return B; if(!B.size()) return A;
	Hull ans; int n=A.size(),m=B.size(),p=0,q=0;
	ans.add(A.H[0]+B.H[0]);
	while(p<n-1||q<m-1) {
		if(p==n-1) q++;
		else if(q==m-1) p++;
		else {
			if( cmp(A.H[p+1]-A.H[p],B.H[q+1]-B.H[q]) ) p++;
			else q++;	
		}
		
		if(p>n-1||q>m-1) break;
		ans.add(A.H[p]+B.H[q]);
	}
	return ans;
}
int vrt=INF,rt,vis[MN],siz[MN];
void getroot(int u,int fa,int allsiz) {
	int mx=0; siz[u]=1;
	for(auto it:e[u]) { int v=it.v; if(v==fa||vis[v]) continue;
		getroot(v,u,allsiz); siz[u]+=siz[v]; ckmax(mx,siz[v]);
	} ckmax(mx,allsiz-siz[u]);
	if(mx<vrt) vrt=mx,rt=u;
}
Hull h[MN],fans; int tot;
void dfs(int u,int fa,ll sa,ll sb) { assert(!vis[u]);
	h[tot].add(P(sa,sb));
	for(auto it:e[u]) { int v=it.v; if(v==fa||vis[v]) continue;
		dfs(v,u,sa+it.A,sb+it.B); 
	}	
}
priority_queue<pii>q;
void dfz(int u,int allsiz) {
//	cerr<<allsiz<<' '<<siz[u]<<endl;
	vis[u]=1; For(i,1,tot) h[i].H.clear(); tot=0;
	for(auto it:e[u]) { int v=it.v; if(vis[v]) continue; 
		tot++; dfs(v,u,it.A,it.B);
	}
	if(!tot) return;
	For(i,1,tot) h[i].build();
	For(i,1,tot) {
		for(auto it:h[i].H) fans.add(it);
	}
	For(i,1,tot) q.push(mkp(-h[i].size(),i));
	
	while(q.size()>1) {
		int x=q.top().second; q.pop(); 
		int y=q.top().second; q.pop(); swap(x,y);
		Hull tmp=h[x]+h[y]; 
//		cerr<<"?"; fprint(tmp); 
		
		for(auto it:h[y].H) h[x].add(it);
		for(auto it:tmp.H) fans.add(it);
		h[x].build();
		q.push(mkp(-h[x].size(),x));
	}
	while(q.size()) q.pop();
	for(auto it:e[u]) { int v=it.v; if(vis[v]) continue; 
//		cerr<<u<<' '<<v<<' '<<siz[u]<<' '<<siz[v]<<endl;
//	cerr<<siz[u]<<' '<<siz[v]<<endl;
		int tsiz=siz[v]<siz[u]?siz[v]:allsiz-siz[u]; vrt=INF,rt=0; getroot(v,u,tsiz);

		dfz(rt,tsiz);
	}
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),m=read();
	For(i,1,n-1) {
		int u=read(),v=read(),A=read(),B=read();
		e[u].pb((Edge){v,A,B}),e[v].pb((Edge){u,A,B});
	}	
	getroot(1,0,n); 
//	fprint(siz,n);
//cerr<<rt<<' '<<siz[rt]<<endl;
	dfz(rt,n);
	
//	cerr<<"DONE!!"<<endl;
	
//	fprint(fans);
	assert(fans.size()<=1e7);
	fans.build();
//	fprint(fans);
	fans.printans();
	return FastIO::Fflush(),0;
}