#include<bits/stdc++.h>
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Rep(i,a,b) for(register int i=(a);i<=int(b);++i)
#define Dep(i,a,b) for(register int i=(a);i>=int(b);--i)
#define rep(i,a,b) for(register int i=(a);i<int(b);++i)
#define mem(x,v) memset(x,v,sizeof(x))
#define fi first
#define se second
#define debug(x) cout << #x" = " << x << endl;
#define pp(x,y) cout << "pp: " << x << " " << y << endl;
namespace IO{  
	const int L=1<<15;char ibuf[L|1],*iS=ibuf,*iT=ibuf,obuf[L|1],*oS=obuf,*oT=obuf+L,c,st[66];int tp=0,f;
	inline char gc(){if(iS==iT) iT=(iS=ibuf)+fread(ibuf,sizeof(char),L,stdin);return (*iS++);}
	inline void flush(){fwrite(obuf,sizeof(char),oS-obuf,stdout);oS = obuf;}
	inline void pc(char c){*oS++=c;if(oS==oT) flush();}
	#define gc getchar
	#define pc putchar
	inline ll read(){ll x=0;f=1,c=gc();for(;!isdigit(c);c=gc())if(c=='-')f=-1;for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c&15);return x*f;}
	inline void write(ll x){if(!x) pc('0');if(x<0) pc('-'),x=-x;while(x) st[++tp]=x%10+'0',x/=10;while(tp) pc(st[tp--]);}
	inline void writeln(ll x){write(x);pc('\n');}
	inline void wri(ll x){write(x),pc(' ');}
	struct IOflusher{~IOflusher(){flush();}}_ioflusher_;
}using IO::read;using IO::write;using IO::writeln;using IO::wri;//using IO::gc;using IO::pc;
#define rd read
const int maxn = 205;
const int maxm = 205 * 205;
struct Edge{
	int to,nxt;
	Edge(){}
	Edge(int to,int nxt):to(to),nxt(nxt){}
}edge[maxm];
int first[maxn],nume = 0;
int deg[maxn],a[maxm],t;
int mark[maxm];
int n,m;
bool vis[maxm];
inline void dfs(int u){
	for(int e = first[u];~e;e=first[u]){
		first[u]=edge[first[u]].nxt;
		if(!vis[e]){
			vis[e] = vis[e^1] = true;
			dfs(edge[e].to);
			mark[(e>>1)+1] = (e&1) ? -1 : 1;
		}
	}
}

void Addedge(int a,int b){
	edge[nume] = Edge(b,first[a]);
	first[a] = nume++;
}

void solve(){
	n = rd(),m = rd();
	mem(first,-1);nume = 0;
	mem(deg,0);
	Rep(i,1,m){
		int x = rd(),y = rd();
		Addedge(x,y);
		Addedge(y,x);
		deg[x]^=1,deg[y]^=1;
	}
	Rep(i,1,n)
		if(deg[i]) Addedge(i,n+1),Addedge(n+1,i);
	rep(i,0,nume) vis[i] = false;
	int num = 0;
	Rep(i,1,n){
		dfs(i);
		if(!deg[i]) num++;
	}
	writeln(num);
	for(int i=0;i<2*m;i+=2){
		if(mark[(i>>1)+1]==1){
			wri(edge[i^1].to),writeln(edge[i].to);
		} else{
			wri(edge[i].to),writeln(edge[i^1].to);
		}
	}
}
int main(){
	for(int T=rd();T;T--) solve();
	return 0;
}