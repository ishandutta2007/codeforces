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
inline void fprint(const int &x,char c=' ') {fprintf(stderr,"%d%c",x,c);}
inline void fprint(const pii &x,char c=' ') {fprintf(stderr,"{%d,%d}%c",x.first,x.second,c);}
inline void fprint(const int *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const pii *f,const int &n,char c='\n') {for(int i=1;i<=n;i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const vector<int> &f,char c='\n') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); fprintf(stderr,"%c",c);}
inline void fprint(const vector<pii> &f,char c='\n') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); fprintf(stderr,"%c",c);}
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
const int MN=4e5+5;
#define x first
#define y second
pii S[MN],T[MN];
map<pii,int>id; pii dv[MN]; int n=0,p[MN];
vi e[MN];
int getside(pii u,int x,int y,int bit) {
	int nx=x+(1<<bit),ny=y+(1<<bit);
	if(u.x<nx&&u.y<ny) return 0;
	if(u.x<nx) return 1; 
	return 2;
}
bool cmp(pii u,pii v) {
	int x=0,y=0;
	for(int i=30;i>=0;i--) {
		int p=getside(u,x,y,i),q=getside(v,x,y,i);
		if(p!=q) {
			if(!p) { if(q==1) return 1; return u.y==y;}
			if(!q) { if(p==1) return 0; return v.y!=y;}
			return p>q; 
		} else {
			
			if(p==1) y+=(1<<i);
			if(p==2) x+=(1<<i);	
		}
	} return 0;
}

pii lca(pii u,pii v) {
//	assert(u!=v); 
	int x=0,y=0;
	for(int i=30;i>=0;i--) {
		int p=getside(u,x,y,i),q=getside(v,x,y,i);
		if(p==q) {
			if(p==1) y+=(1<<i);
			if(p==2) x+=(1<<i);	
		} else {
			if(p+q==3) return mkp(x,y);
			if(!q) swap(p,q),swap(u,v); assert(!p);
			v=(q==1?mkp(x,y+(1<<i)-1):mkp(x+(1<<i)-1,y));
		}
	}
	
	if(u==v) return u;
	assert(0); return mkp(-1,-1);
}
int dep(const pii &a) {
	return a.x+a.y;	
}

int stk[MN],top;
void addedge(int u,int v) { 
//	cerr<<u<<' '<<v<<endl;
	e[u].pb(v),e[v].pb(u);
}
void ins(int now) { pii x=dv[now];
//	cerr<<"ins "<<now<<' '; fprint(x,'\n');
	pii L=lca(dv[stk[top]],x); if(!id[L]) dv[id[L]=++n]=L;
	if(L==dv[stk[top]]) return stk[++top]=now,void();
	while(cmp(L,dv[stk[top-1]])) addedge(stk[top-1],stk[top]),top--;
	addedge(id[L],stk[top--]); 
	if(id[L]!=stk[top]) stk[++top]=id[L];
	if(now!=stk[top]) stk[++top]=now;
}
map<int,int>SS;
int tag[MN],tag2[MN],f[MN];
void dfs1(int u,int fa) {
	f[u]=fa;
	for(auto v:e[u]) { if(v==fa) continue;
		dfs1(v,u);
	}
}
void dfs2(int u,int fa) {
	for(auto v:e[u]) { if(v==fa) continue;
		dfs2(v,u); tag[u]+=tag[v];
	}
	if(tag[u]) {
		SS[dep(dv[u])]^=1;
		SS[dep(dv[u])+1]^=1;
//		cerr<<u<<' '<<f[u]<<' '<<dep(dv[u])+1<<' '<<dep(dv[f[u]])+1<<endl;
	} tag[u]+=tag2[u];
	if(tag[u]&&fa) {
		SS[dep(dv[fa])+1]^=1;
		SS[dep(dv[u])]^=1;
	}
}
int m;
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	m=read(); For(i,1,MN-1) p[i]=i;
	For(i,1,m) S[i].x=read(),S[i].y=read(),T[i].x=read(),T[i].y=read();
	dv[id[mkp(0,0)]=++n]=mkp(0,0);
	For(i,1,m) {
		if(!id[S[i]]) dv[id[S[i]]=++n]=S[i];	
		if(!id[T[i]]) dv[id[T[i]]=++n]=T[i];
	}
	
	sort(p+1,p+1+n,[&](int i,int j){return cmp(dv[i],dv[j]);});
//	For(i,1,n) For(j,i+1,n) {
//		cerr<<i<<' '<<j<<' '<<cmp(dv[i],dv[j])<<' '<<cmp(dv[j],dv[i])<<endl;	
//	}
	assert(p[1]==1); stk[++top]=p[1];
//	fprint(dv,n); fprint(p,n);
	int tn=n; For(i,2,tn) { ins(p[i]); }
//	fprint(stk,top);
	while(top>1) addedge(stk[top-1],stk[top]),top--;
//	fprint(dv,n);
	dfs1(1,0);
	For(i,1,m) {
		tag[id[S[i]]]++,tag[id[T[i]]]++;
		tag2[id[lca(S[i],T[i])]]-=2;
	}
	dfs2(1,0);
//	fprint(tag,n);
	int ans=0,lst=0;
	for(auto it:SS) {
//		cerr<<it.first<<' '<<it.second<<endl;
		ans+=it.second;
	}
//	cerr<<ans<<endl;
	cout<<ans-SS[0]<<endl;
	return FastIO::Fflush(),0;
}
/*
  
*/