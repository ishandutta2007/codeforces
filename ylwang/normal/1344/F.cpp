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
inline int read_c() { char s[10]; FI(s); return s[0];}
const int MN=2e3+5;
#define bi bitset<MN<<1>
int n,m;
int getval(char c) {
	if(c=='W') return 0;
	if(c=='R') return 1;
	if(c=='B') return 2;
	if(c=='Y') return 3;
	assert(0); return -1;
}

vector<bi > e;
bi ept;
inline void fprint(const bi &x,char c='\n') {For(i,0,2*n) cerr<<x[i]; cerr<<c;}
inline void fprint(const vector<bi> &f,char c=' ') {for(int i=0;i<(int)f.size();i++) fprint(f[i]); }
pair<int,vector<int> > solve(vector<bi >a) {
	int n=a.size(),m=::n*2,r=0;
//	fprint(a); 
	vi ans(m);
	For(i,0,m-1) {
		if(r>=n) break;
		For(j,r,n-1) if(a[j][i]) {swap(a[j],a[r]); break;}
		if(!a[r][i]) continue;
		For(j,0,n-1) if(j!=r&&a[j][i]) a[j]^=a[r];
		r++; 
	}
	For(i,r,n-1) if(a[i][m]) return mkp(0,ans);
	For(i,0,r-1) {int j=0;
		while(!a[i][j]) j++;
		ans[j]=a[i][m];
	}
	return mkp(1,ans);
}
int para[MN<<1];

signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read(),m=read();
	For(i,0,n-1) para[i<<1]=1,para[i<<1|1]=2;
	For(tt,1,m) {
		char op[10]; FI(op);
		vi pos(read()); for(auto &it:pos) it=read()-1;
		if(op[0]=='m') {
			int res=getval(read_c());
			bi now; now.reset();
			for(auto it:pos) {
				if(para[it<<1]&1) now.set(it<<1);
				if(para[it<<1]>>1) now.set(it<<1|1);
			} if(res&1) now.set(2*n); e.pb(now);
			now.reset();
			for(auto it:pos) {
				if(para[it<<1|1]&1) now.set(it<<1);
				if(para[it<<1|1]>>1) now.set(it<<1|1);
			} if(res>>1) now.set(2*n); e.pb(now);
		} else {
			for(auto it:pos) {
				if(op[0]=='R') {
					if(op[1]=='B') swap(para[it<<1],para[it<<1|1]); 
					else para[it<<1|1]^=para[it<<1];
				} else para[it<<1]^=para[it<<1|1]; 	
			}
			
		}
	}
//	if(n==1000) return 0;
	pair<int,vi>ans=solve(e);
	if(!ans.first) return printf("NO\n"),0;
	printf("YES\n");
	For(i,0,n-1) printf("%c",".RBY"[ans.second[i<<1|1]<<1|ans.second[i<<1]]);
	printf("\n");
	return 0;
}

/*
// p[i] < p[j] : iff pos[i] > j && a[i] < j
*/