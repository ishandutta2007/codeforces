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
inline int read() {int x=0; FI(x); return x;}
const int MN=2e5+5;
const int MB=405;
int n,m;
struct Base {
	int v[5];
	Base() { mst(v,0); }
	int &operator [] (int x) {return v[x];}
	int insert(int x) {
		for(int i=4;i>=0;i--) {
			if(!(x>>i&1)) continue;
			if(!v[i]) {
				v[i]=x;
				For(j,0,i-1) if(v[i]>>j&1) v[i]^=v[j];
				For(j,i+1,4) if(v[j]>>i&1) v[j]^=v[i]; 
				return 1;
			}
			x^=v[i];
		}
		return 0;
	}
	int Hash() {
		if(v[0]==-1) return 0;
		return ((v[4]<<10)|(v[3]<<6)|(v[2]<<3)|(v[1]<<1)|(v[0]))+1;
	}
};
inline void fprint(Base &x,char c='\n') {fprintf(stderr,"%d %d %d %d %d%c",x[4],x[3],x[2],x[1],x[0],c);}
Base operator + (Base &a,Base &b) {
	if(a[0]==-1) return a; if(b[0]==-1) return b;
	Base ans=a;
	For(i,0,4) if(b[i]&&!ans.insert(b[i])) {ans[0]=-1; return ans;}
	return ans;
}
Base b[MB];
int id[MN],tot,vis[MN],sum[MB][MB];
void gen(Base &now) { int h=now.Hash();
	if(vis[h]) return; vis[h]=1;
//	fprint(now);
	id[h]=++tot; b[tot]=now;
//	cerr<<tot<<endl; 
	Base tmp=now;
	For(i,0,31) {
		if(now.insert(i)) {
//			cerr<<i<<endl;
			gen(now);
			now=tmp;
		}
	}
}
vector<pii> e[MN];

int cnt=0,bel[MN],T[MN],ex[MN];
Base tmp; int val[MN],ok,ind;
void dfs(int u,int fa) {
//	cerr<<u<<' '<<fa<<endl;
	bel[u]=cnt,vis[u]=++ind;
	for(auto it:e[u]) { int v=it.first,w=it.second; if(v==fa||v==1) continue;
		
		if(!bel[v]) val[v]=val[u]^w,dfs(v,u);
		else if(vis[v]<vis[u]) {
			ok&=(tmp.insert(val[v]^val[u]^w));
//			cerr<<"? "<<u<<' '<<v<<' '<<(val[v]^val[u]^w)<<' '<<ok<<endl;
		}
	}
}
int f[MB],g[MB];
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),m=read();
	For(i,1,m) {
		int u=read(),v=read(),w=read();
		e[u].pb(mkp(v,w)),e[v].pb(mkp(u,w));
	} Base xyr; gen(xyr);
	cerr<<tot<<endl;
	For(i,1,tot) For(j,1,tot) {
		Base ans=b[i]+b[j];
		sum[i][j]=sum[j][i]=id[ans.Hash()];
	}
	mst(vis,0); vis[1]=1; mst(val,0);

	for(auto itu:e[1]) { int u=itu.first;
		if(!vis[u]) {
			tmp=Base(); ok=1;
			cnt++,dfs(u,1);	
			if(!ok) T[cnt]=0;
			else T[cnt]=id[tmp.Hash()];
		}
	}
	mst(val,-1);
	for(auto itu:e[1])
		val[itu.first]=itu.second;
//	fprint(bel,n);
	for(auto itu:e[1]) for(auto itv:e[itu.first]) {
		if(bel[itu.first]==bel[itv.first]&&val[itv.first]!=-1) { int tv=val[itu.first]^itv.second^val[itv.first];
//		cerr<<itu.first<<' '<<itv.first<<' '<<bel[itu.first]<<' '<<bel[itv.first]<<endl;
			if(!tv) {ex[bel[itu.first]]=-1; continue; }
			tmp=Base(); tmp.insert(tv);
			ex[bel[itu.first]]=id[tmp.Hash()];
		}
	}
//	fprint(T,cnt);
//	fprint(ex,cnt);
	f[id[1]]=1;
	For(x,1,cnt) { f[0]=g[0]=0;
		if(T[x]) {
			For(i,1,tot) g[i]=f[i];
			For(i,1,tot) {
				addmod(f[sum[i][T[x]]],g[i]);
				if(ex[x]>0) {
					addmod(f[sum[i][T[x]]],g[i]);
					addmod(f[sum[i][sum[ex[x]][T[x]]]],g[i]);
				} else if(ex[x]<0) addmod(f[sum[i][T[x]]],g[i]);
			}
		}
	}
	int ans=0;
	For(i,1,tot) addmod(ans,f[i]);
	cout<<ans<<endl;
	return 0;
}

/*
// p[i] < p[j] : iff pos[i] > j && a[i] < j
*/