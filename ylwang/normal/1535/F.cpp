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
#define int long long
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
inline int read() {int x; FI(x); return x;}
const int MN=2e5+5;
int n; string s[MN];
bool operator < (const vi &a,const vi &b) {
	if(a.size()!=b.size()) return a.size()<b.size();
	For(i,0,25) if(a[i]!=b[i]) return a[i]<b[i];
	return 1;
}
bool operator == (const vi &a,const vi &b) {
	if(a.size()!=b.size()) return 0;
	For(i,0,25) if(a[i]!=b[i]) return 0;
	return 1;
}
map<vi,vector<string>>mp;
vi getHash(const string &s) {
	vi ans(26);
	for(auto c:s)
		ans[c-'a']++;
	return ans;
}
struct SAM {
	static const int N=MN*4;
	int nxt[N][27],fa[N],mxlen[N],lst=1,tot=1,ep[N] ;
	vi e[N];
	void clear() {
		For(i,1,tot) e[i].clear(),fa[i]=mxlen[i]=0,mst(nxt[i],0),ep[i]=0;
		lst=tot=1;
	}
	void insert(int c) {
		int p=lst,cur=++tot; mxlen[cur]=mxlen[p]+1,ep[cur]=1;
		for(;p&&!nxt[p][c];p=fa[p]) nxt[p][c]=cur;
		if(!p) fa[cur]=1;
		else {
			int q=nxt[p][c];
			if(mxlen[p]+1==mxlen[q]) fa[cur]=q;
			else { 
				int tmp=++tot; mxlen[tmp]=mxlen[p]+1; For(i,0,26) nxt[tmp][i]=nxt[q][i]; fa[tmp]=fa[q];
				for(;p&&nxt[p][c]==q;p=fa[p]) nxt[p][c]=tmp; fa[cur]=fa[q]=tmp;
			}
		}
		lst=cur;
	}
	void dfs(int u) {
		for(auto v:e[u]) { dfs(v);
			ep[u]+=ep[v];
		}
	}
	void init() {
		For(i,1,tot) e[i].clear();
		For(i,2,tot) e[fa[i]].pb(i);
//		For(i,1,tot) cerr<<mxlen[i]<<' '<<fa[i]<<endl;cerr<<endl;
		dfs(1);
	}
	int qry(const string &s) {
//		cerr<<s<<endl;
		int p=1;
		for(auto c:s) p=nxt[p][c-'a'];
		p=nxt[p][26]; assert(p); int nowlen=s.size()+1,ans=0;
		for(int i=0;i<(int)s.size();) {
			int j=i; while(j+1<(int)s.size()&&s[j]<=s[j+1]) j++;
//			cerr<<i<<' '<<j<<endl;
			nowlen-=j-i+1; while(mxlen[fa[p]]>=nowlen) p=fa[p];
//			cerr<<p<<' '<<ep[p]<<' '<<mxlen[p]<<' '<<nowlen<<endl;
			ans+=ep[p]-1; 
//			cerr<<ep[p]<<endl;
			For(k,i,j) {
//				while(!nxt[p][s[k]-'a']) p=fa[p];
//				cerr<<s[k]<<endl;
//				cerr<<p<<' '<<nxt[p][s[k]-'a']<<endl;
				p=nxt[p][s[k]-'a'],nowlen++;				
			}
			i=j+1;
			assert(p);
		} 
		return ans;
	}
}sam;
int doit(vector<string>v) {
	string all=""; for(auto it:v) all+=it,all+='{',all+=it;
//	cerr<<all<<endl;
	sam.clear(); for(auto c:all) sam.insert(c-'a'); sam.init();
	int ans=2ll*(v.size())*(v.size()-1)/2;
	for(auto it:v) {
//		cerr<<it<<endl;
		int now=sam.qry(it);
		ans-=now;
//		cerr<<now<<endl;
	}
	return ans;
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	IOS; cin>>n;
	For(i,1,n) {
		string s;cin>>s;
		mp[getHash(s)].pb(s);
	}
	int now=0,ans=0;
	for(auto it:mp) {
		ans+=doit(it.second);
		ans+=it.second.size()*now*1337;
		now+=it.second.size();
	}
	cout<<ans<<endl;
	return FastIO::Fflush(),0;
}