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
#define INF ((1ll<<61)-1)
#define int long long
const int P=998244353; //
using namespace std;
template<typename T>inline void ckmax(T &a,T b) {(a<b)&&(a=b);}
template<typename T>inline void ckmin(T &a,T b) {(a>b)&&(a=b);}
inline int mul(int a,int b) {return 1ll*a*b%P;}
inline int add(int a,int b) {return a+b>=P?a+b-P:a+b;}
inline int sub(int a,int b) {return a-b>=0?a-b:a-b+P;}
inline void mulmod(int &a,int b) {a=mul(a, b);}
inline void addmod(int &a,int b) {((a+=b)>=P)&&(a-=P);}
inline void submod(int &a,int b) {((a-=b)<0)&&(a+=P);}
inline int ksm(int a,int b) {int ans=1; for(;b;b>>=1) {if(b&1) ans=1ll*ans*a%P;a=1ll*a*a%P;}return ans;}
inline void fprint(const vector<int> &f) {for(int i=0;i<(int)f.size();i++) fprintf(stderr,"%d ",f[i]); fprintf(stderr,"\n");}
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
int n,q,pos[MN];
struct Node {
	int cnt,w,v,id;
	bool operator < (const Node &b) {
		if(v!=b.v) return v>b.v;
		if(w!=b.w) return w<b.w;
		return cnt<b.cnt;
	}
}a[MN];
// w: v: 
struct SMT {
	static const int N=MN<<2,M=30;
	int sw[N][M+2],sv[N][M+2],ex[N][M+2];
	#define ls (k<<1)
	#define rs (k<<1|1)
	#define mid ((l+r)>>1)
	void doit(int k,int pos) {
		For(i,1,M) sw[k][i]=sv[k][i]=0,ex[k][i]=INF;
		For(i,1,M) {
			if(a[pos].w<(1ll<<i)) {
//				cerr<<"?"<<' '<<k<<' '<<pos<<' '<<i<<' '<<a[pos].w<<' '<<a[pos].v<<' '<<a[pos].cnt<<endl;
				sw[k][i]+=a[pos].cnt*a[pos].w,sv[k][i]+=a[pos].cnt;
			} else if(a[pos].w<(1ll<<(i+1))&&a[pos].cnt) ex[k][i]=a[pos].w;
		}
	}
	void pushup(int k) {
		For(i,1,M) {
			sw[k][i]=sw[ls][i]+sw[rs][i];
			sv[k][i]=sv[ls][i]+sv[rs][i];
//			cerr<<"!"<<' '<<k<<' '<<i<<' '<<sw[k][i]<<' '<<sv[k][i]<<endl;
			ex[k][i]=min(ex[ls][i],sw[ls][i]+ex[rs][i]);
		}
	}
	int w,c;
	void getw() {
		if(!c) return;
		w=M-1; while((1<<w)>c) w--;
	}
	void build(int k,int l,int r) {
//		fprintf(stderr,"BUILD %d %d %d\n",k,l,r);
		if(l==r) { doit(k,l); return; }
		build(ls,l,mid),build(rs,mid+1,r);
		pushup(k);
	}
	void upd(int k,int l,int r,int pos) {
//		fprintf(stderr,"UPD %d %d %d\n",k,l,r);
		if(l==r) { doit(k,l); return;}
		pos<=mid?upd(ls,l,mid,pos):upd(rs,mid+1,r,pos);
		pushup(k);
	}
	int qry(int k,int l,int r) {
//		fprintf(stderr,"QRY %d %d %d\n",k,l,r); 
		if(l==r) {
			int tot=min(a[l].cnt,c/a[l].w);
			c-=tot*a[l].w; getw();
			return tot;
		}
		
//		cerr<<c<<' '<<w<<endl;
		if(sw[k][w+1]<=c) {
			c-=sw[k][w+1]; int res=sv[k][w+1]; getw();
//			cerr<<sw[k][w+1]<<' '<<sv[k][w+1]<<endl;
			return res;
		}
		if(sw[k][w]<=c&&c<ex[k][w]) {
			c-=sw[k][w]; int res=sv[k][w]; getw();
			return res;
		}
		
		int lftans=qry(ls,l,mid);
		if(!c) return lftans;
		int rgtans=qry(rs,mid+1,r);
		return lftans+rgtans;
	}
}tr;
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	n=read();
	For(i,1,n) {
		a[i].cnt=1,a[i].w=read(),a[i].v=read(),a[i].id=i;	
//		cerr<<a[i].w<<' '<<a[i].v<<endl;
	}
//	n++; a[n].w=INF;
	sort(a+1,a+1+n);
//	For(i,1,n) cerr<<a[i].w<<' '<<a[i].v<<endl;
	For(i,1,n) {
		pos[a[i].id]=i;
	}
	q=read();
	tr.build(1,1,n);
	while(q--) {
//		int op=read();
//		if(op==1||op==2) {
//			int k=read(),d=read();
//			a[pos[d]].cnt+=k*(op==1?1:-1); tr.upd(1,1,n,pos[d]);
//		} else {
			tr.c=read(); tr.getw();
			printf("%lld ",tr.qry(1,1,n));	
//		}
	}
	return FastIO::Fflush(),0;
}