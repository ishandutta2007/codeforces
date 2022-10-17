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
inline int read() {int x=0; FI(x); return x;}
const int MN=2e5+5;
int n,dx[MN],dy[MN],t,X[MN],Y[MN],R[MN],C[MN];
int vis[MN];
struct SMT {
	static const int N=MN<<3;
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid ((l+r)>>1)
	set<int>s[N]; 
	int mx[N],mn[N];
	SMT() { mst(mx,-1); }
	void pushup(int k) {
		mx[k]=max(mx[ls],mx[rs]); mn[k]=min(mn[ls],mn[rs]);
		if(s[k].size()) {
			int v=*s[k].rbegin();
			if(mx[k]<v) {
				if(v<mn[k]) mx[k]=-1;
				else if(vis[v]) mx[k]=-1;
				else mx[k]=v;	
			}
			ckmax(mn[k],v);
		}
	}
	void upd(int k,int l,int r,int ql,int qr,int v) { // op=0:erase
		if(l>qr||r<ql) return; if(ql<=l&&r<=qr) {
			v>0?(s[k].insert(v),void()):(s[k].erase(-v),void()); pushup(k);
			return;
		}
		upd(ls,l,mid,ql,qr,v),upd(rs,mid+1,r,ql,qr,v);
		pushup(k);
	}
}	tr;
struct ele {
	int x,y,z;
	ele(){} ele(int X,int Y,int Z):x(X),y(Y),z(Z){}
};

vector<ele> qr[MN];
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read();
	For(i,1,n) {
		dx[++t]=X[i]=read();
		dy[t]=Y[i]=read();
		dx[++t]=R[i]=read();
		dy[t]=C[i]=read();
	}
	sort(dx+1,dx+1+t),sort(dy+1,dy+1+t);
	For(i,1,n) {
		X[i]=lower_bound(dx+1,dx+1+t,X[i])-dx;
		Y[i]=lower_bound(dy+1,dy+1+t,Y[i])-dy;
		R[i]=lower_bound(dx+1,dx+1+t,R[i])-dx-1;
		C[i]=lower_bound(dy+1,dy+1+t,C[i])-dy-1;
		cerr<<X[i]<<' '<<Y[i]<<' '<<R[i]<<' '<<C[i]<<endl;
		qr[X[i]].pb(ele(Y[i],C[i],i));
		qr[R[i]+1].pb(ele(Y[i],C[i],-i));
	}
	int ans=1; vis[0]=1;
	For(i,1,t) {
		for(auto it:qr[i]) {
			int l=it.x,r=it.y,z=it.z;
			tr.upd(1,1,t,l,r,z);
		}
		int u;
		while(~(u=tr.mx[1])) {
//			cerr<<i<<' '<<u<<' '<<tr.mx[1]<<' '<<tr.mn[1]<<' '<<tr.mn[2]<<' '<<tr.mn[3]<<endl;
			vis[u]=1,ans++;	
			tr.upd(1,1,t,Y[u],C[u],0);
		}
	}
//	fprint(vis,n);
	cout<<ans<<endl;
	return FastIO::Fflush(),0;
}
/*
  
*/