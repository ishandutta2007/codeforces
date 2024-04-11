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
#define INF ((ll)1e16)
//#define int long long
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
mt19937_64 rnd(time(0)); int Rnd(int l,int r) { return rnd()%(r-l+1)+l; }
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
const int MN=5e5+5;
int n; 
struct ele {
	int x,y,z,id;
	ele(){} ele(int X,int Y,int Z,int ID):x(X),y(Y),z(Z),id(ID){}
	bool operator < (const ele &b) const {
		if(x!=b.x) return x<b.x;
		if(y!=b.y) return y<b.y;
		return z<b.z;
	}
}a[MN]; 
map<int,vector<ele> >mp,mp2; 
vector<pii>ans; 
ele solve2(vector<ele>a) {
	int n=SZ(a); 
	sort(a.begin(),a.end()); 
	for(int i=0;i+1<n;i+=2) {
		ans.pb(mkp(a[i].id,a[i+1].id)); 
	}
	if(n%2==1) {
		return ele(a[n-1].z,a[n-1].x,a[n-1].y,a[n-1].id); 
	}
	else return ele(0,0,0,0); 
}
ele solve1(vector<ele>a) {
	mp2.clear(); 
	for(auto it:a) {
		mp2[it.x].pb(ele(it.y,it.z,it.x,it.id));
	}
	vector<ele>b; 
	for(auto it:mp2) {
		ele tmp=solve2(it.second); 
		if(tmp.id) b.pb(tmp); 
	}
	return solve2(b); 
}
void works() {
	n=read();
	For(i,1,n) a[i].x=read(),a[i].y=read(),a[i].z=read(),a[i].id=i; 
	sort(a+1,a+1+n); 
	For(i,1,n) mp[a[i].x].pb(ele(a[i].y,a[i].z,a[i].x,a[i].id));  
	vector<ele>b; 
	for(auto &it:mp) {
		ele tmp=solve1(it.second); 
		if(tmp.id) b.pb(tmp); 
	}
	solve2(b); 
	for(auto it:ans) {
		printf("%d %d\n",it.first,it.second); 
	}
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