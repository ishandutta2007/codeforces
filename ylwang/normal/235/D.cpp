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
//#define int ll
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
inline int read() {int x=0; cin>>x; return x;}
const int MN=5e5+5;
const int N=MN;
int siz[N],f[N],dep[N],id[N],up[N][5],ind,dfn[N],top[N],bel[N]; vi e[N],g[N]; 
int n,deg[MN],cyc[MN],tot,onc[MN],idcyc[MN]; 
void dfs1(int u,int fa,int rt) {
	cerr<<"dfs1 "<<u<<' '<<fa<<' '<<rt<<' '<<fa<<' '<<dep[fa]<<endl;
	siz[u]=1,dep[u]=dep[f[u]=fa]+1,bel[u]=rt;
	for(auto v:e[u]) if(v!=f[u]&&!onc[v]) dfs1(v,u,rt),siz[u]+=siz[v];
}
#define upd(i) up[u][i]=up[f[up[u][i-1]]][i-1]
void dfs2(int u,int fir) {
//	cerr<<u<<' '<<fir<<endl;
	int hson=0; top[u]=up[u][0]=fir, id[dfn[u]=++ind]=u;
	upd(1); upd(2); upd(3); upd(4);
	for(auto v:e[u]) if(v!=f[u]&&siz[v]>siz[hson]&&!onc[v]) hson = v;
	if(!hson) return; dfs2(hson,fir);
	for(auto v:e[u]) if(v!=f[u]&&v!=hson&&!onc[v]) dfs2(v,v);
}
int lca(int u,int v) {
	while(top[u]!=top[v])
		dep[top[u]]>dep[top[v]]?u=f[top[u]]:v=f[top[v]];
	return dep[u]<dep[v]?u:v;
}
inline int dist(int u,int v) {return dep[u]+dep[v]-2*dep[lca(u,v)]+1;}

void works() {
	n=read();
	For(i,1,n) {
		int u=read()+1,v=read()+1;
		e[u].pb(v),e[v].pb(u); deg[u]++,deg[v]++;	
	}
	queue<int>q;
	For(i,1,n) if(deg[i]==1) q.push(i);
	For(i,1,n) onc[i]=1;
	while(q.size()) {
		int u=q.front(); q.pop(); onc[u]=0; 
		for(auto v:e[u]) {
			if((--deg[v])==1) q.push(v);
		}
			
	}
	dep[0]=0;
	For(i,1,n) {
		if(onc[i]) {
			dfs1(i,0,i);
			dfs2(i,i);
		}
	}
	
	For(i,1,n) {
		if(onc[i]) {
			int u=i;
			while(1) {
				tot++,idcyc[cyc[tot]=u]=tot; int stu=u;
				for(auto v:e[u]) {
					if(!onc[v]) continue;
					if(idcyc[v]) continue;
					u=v;
				}
				if(stu==u) break;
			}
			break;
		}
	}
	fprint(onc,n);
	fprint(bel,n);
	fprint(dep,n);
	fprint(idcyc,n);
//	fprint(cyc,tot);
	double ans=0;
	For(i,1,n) {
		For(j,1,n) {
			if(bel[i]==bel[j]) {
				ans+=1.0/dist(i,j);
			} else {
				int x=dep[i]+dep[j],y=abs(idcyc[bel[i]]-idcyc[bel[j]])-1,z=tot-2-y;
//				cerr<<i<<' '<<j<<' '<<x<<' '<<y<<' '<<z<<endl;
				ans+=1.0/(x+y),ans+=1.0/(x+z),ans-=(1.0)/(x+y+z);
			}
		}
	}
	printf("%.10lf\n",ans);
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