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
#define INF ((1ll<<60)-1)
#define int ll
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
int n,a[MN],b[MN],m,x,p[MN],q[MN],T=2e5+1;
int s[MN],top,mx[MN];
void solve(int *a,int n,int *ans) {
	For(i,1,n) ans[i]=T;
	top=0; reverse(a+1,a+1+n);
	For(i,1,n) {
		int nmx=a[i];
		while(top&&a[s[top]]>=a[i]) {
			ckmax(nmx,mx[top]); top--;
		}
		if(top) ckmin(ans[n-i+1],nmx); 
		mx[++top]=nmx,s[top]=i;
	}
	top=0; reverse(a+1,a+1+n);
	For(i,1,n) {
		int nmx=a[i];
		while(top&&a[s[top]]>a[i]) {
			ckmax(nmx,mx[top]); top--;
		}
//		cerr<<i<<' '<<top<<' '<<a[i]<<' '<<s[top]<<endl;
		if(top) ckmin(ans[i],nmx); 
		mx[++top]=nmx,s[top]=i;
	}
//	fprint(ans,n);
}
pii A[MN],B[MN];
struct BIT {
	static const int N=MN;
	int c[N];
	void upd(int x,int v) { x++;
		for(;x<=T+1;x+=x&-x) c[x]+=v;
	}
	int qry(int x) { x++; int ans=0;
		for(;x;x-=x&-x) ans+=c[x]; return ans;
	}
}tr;
bool cmp(pii x,pii y) {
	if(y.second!=x.second) return x.second>y.second;
	return x.first<y.first;	
}
void works() {
	n=read(),m=read(),x=read();
	For(i,1,n) a[i]=read();
	For(i,1,m) b[i]=read();
	solve(a,n,p);
	solve(b,m,q);
	For(i,1,n) A[i]=mkp(a[i],p[i]);
	For(i,1,m) B[i]=mkp(b[i],q[i]);
	sort(A+1,A+1+n); sort(B+1,B+1+m,cmp);
	ll ans=0; int now=1;
//	For(i,1,n) fprint(A[i]);
//	For(i,1,m) fprint(B[i]);
//	cerr<<"?";
	For(i,1,n) {
		if(A[i].first>x) continue;
		while(now<=m&&B[now].second>x-A[i].first) {
			tr.upd(B[now].first,1); now++;
		}
//		cerr<<"?"<<' '<<i<<' '<<now<<endl;
		ans+=tr.qry(x-A[i].first)-tr.qry(max(x-A[i].second,0ll));
	}
	cout<<ans<<endl;
//	fprint(p,n),fprint(q,m);
	
}
signed main() {
	#ifndef ONLINE_JUDGE
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
5 5 5
2 3 5 4 3 
2 3 2 2 5 
*/