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
#define INF ((1ll<<60)-1)
#define int long long
int P=1e9+7; //
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
inline int read() {int x=0; cin>>x; return x;}
unordered_map<int,int>fr1,fr2;
int doit(int x,int op) {
	return op==1?add(x,1):(op==2?sub(x,1):inv(x));
}
void dfs1(int x,int d,int fr) {
	if(fr1.count(x)) return;
	fr1[x]=fr;
//	cerr<<x<<endl;
	if(d>=70) return;
	if(fr==3) {
		dfs1(add(x,1),d+1,1);
		dfs1(sub(x,1),d+1,2);	
	} else {
		dfs1(inv(x),d+1,3);
		if(fr!=1) dfs1(doit(x,1),d+1,1);
		if(fr!=2) dfs1(doit(x,2),d+1,2);
	}
}
void dfs2(int x,int d,int fr) {
	if(fr2.count(x)) return;
	fr2[x]=fr;
	if(d>=70) return;
	if(fr==0) {
		dfs2(add(x,1),d+1,1);
		dfs2(sub(x,1),d+1,2);	
	} else {
		dfs2(inv(x),d+1,0);
		if(fr!=1) dfs2(doit(x,1),d+1,1);
		if(fr!=2) dfs2(doit(x,2),d+1,2);
	}
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	int x=read(),y=read(); P=read();
	dfs1(x,0,-1); dfs2(y,0,-1);
	cerr<<fr1.size()<<endl;
	for(auto it:fr1) {
		
		int t=it.first;
//		cerr<<t<<endl;
		if(fr2.count(t)) {
			vi ans; int tmp=t,oo;
			while(tmp!=x) {
				assert(fr1.count(tmp));
				ans.pb(oo=fr1[tmp]),tmp=doit(tmp,3-oo);
			}
			reverse(ans.begin(),ans.end()); tmp=t; 
			while(tmp!=y) {
				assert(fr2.count(tmp));
				ans.pb(oo=3-fr2[tmp]),tmp=doit(tmp,oo);
			}
			printf("%d\n",SZ(ans));
			for(auto it:ans) {
				printf("%d ",it);
			}
			printf("\n");
			return 0;
		}
	}
	assert(0);
	return FastIO::Fflush(),0;
}