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
inline int read() {int x; cin>>x; return x;}
const int MN=5e5+5;
int n1,n2,m,sum[MN][2],f[MN],pw[MN],rev[MN],to[MN];
int res=0;
int find(int x) {
	if(x==f[x]) return x;
	if(f[x]==f[f[x]]) return f[x];
	int F=find(f[x]);
	rev[x]^=rev[f[x]];
	return f[x]=F;
}
int is_rev(int x) {
	int F=find(x);
	if(F==x) return rev[x];
	return rev[x]^rev[F];
}
void dorev(int id) {
//	assert(find(id)==id); 
	id=find(id);
	submod(res,sum[id][rev[id]]);
	rev[id]^=1;
	addmod(res,sum[id][rev[id]]);
}
void merge(int x,int y) {
	x=find(x),y=find(y); if(x==y) return;
	rev[y]^=rev[x]; 
	addmod(sum[x][0],sum[y][rev[y]]);
	addmod(sum[x][1],sum[y][rev[y]^1]);
	f[y]=x;
}
void addedge(int x,int y,int id) {
	f[id]=id,sum[id][1]=pw[id]; 
	if(!to[x]&&!to[y]) {
//		cerr<<"* "<<x<<' '<<y<<' '<<id<<endl;
		to[x]=to[y]=id;  return;
	} if(!to[x]) swap(x,y); 
	if(!to[y]) {
//		cerr<<"! "<<x<<' '<<y<<' '<<id<<endl;
		if(!is_rev(to[x])) dorev(id);
		merge(to[x],id); to[x]=0,to[y]=id;
		return;
	}
//	cerr<<". "<<x<<' '<<y<<' '<<id<<endl;
//	if(is_rev(to[x])!=is_rev(to[y])) dorev(to[x]);
//	if(!is_rev(to[x])) dorev(id);
	
	int rx=is_rev(to[x]),ry=is_rev(to[y]);
	if(rx==ry) {
		if(!rx) dorev(id);	
	} else {
		if(!rx) dorev(to[x]);
		else dorev(to[y]);
	}
	merge(to[x],id),merge(to[y],id);
	to[x]=to[y]=0;
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	IOS;
	pw[0]=1; For(i,1,MN-5) pw[i]=mul(pw[i-1],2);
	n1=read(),n2=read(),m=read();
	For(i,1,m) {
		int x=read(),y=read();
		addedge(x,y+n1,i);
	}
	cerr<<"(())"<<endl;
	int q=read(),now=m;
	while(q--) {
		int op=read();
		if(op==1) {
			int x=read(),y=read(); addedge(x,y+n1,++now);
			cerr<<x<<' '<<y<<endl;
			cout<<res<<endl;
		} else { int cnt=0;
			For(x,1,now)
				if(is_rev(x)) cnt++;
			cout<<cnt<<' ';
			For(x,1,now)
				if(is_rev(x)) cout<<x<<' ';
			cout<<endl;
		}
	}
	return FastIO::Fflush(),0;
}

/*
// p[i] < p[j] : iff pos[i] > j && a[i] < j
*/