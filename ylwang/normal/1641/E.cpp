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
const int MN=3e5+5;
int n,m,fac[MN],ifac[MN],suf[MN],pre[MN],pw[MN];
int C(int n,int m) {
	if(n<m||n<0||m<0) return 0;
	return 1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
}
void init(int n=MN-5) {
	fac[0]=1; For(i,1,n) fac[i]=mul(fac[i-1],i); ifac[n]=inv(fac[n]);
	pw[0]=1; For(i,1,n) pw[i]=mul(pw[i-1],2);
	foR(i,n,1) ifac[i-1]=mul(ifac[i],i);
}
#define poly vector<int>
namespace POLY {
	const int GG=3,IG=inv(GG);
	poly REV,WW; int p_lim;
	void getR(int tn) {
		int cnt=0; p_lim=1; while(p_lim<=tn) p_lim<<=1,cnt++;
		REV.resize(p_lim); WW.resize(p_lim);  for(int i=1;i<p_lim;i++) REV[i]=(REV[i>>1]>>1)|((i&1)<<(cnt-1));
	}
	void ntt(poly &a,int op) {
		WW[0]=1; for(int i=0;i<p_lim;i++) if(i<REV[i]) swap(a[i],a[REV[i]]);
		for(int k=1;k<p_lim;k<<=1) {
			int Wn=ksm(op==1?GG:IG,(P-1)/(k<<1));
			for(int i=1;i<k;i++) WW[i]=mul(WW[i-1],Wn);
			for(int i=0;i<p_lim;i+=k<<1) {
				for(int j=0;j<k;j++) {
					int x=a[i+j],y=mul(WW[j],a[i+j+k]);
					a[i+j]=add(x,y),a[i+j+k]=sub(x,y);
				}
			}
		}
		if(op!=1) {
			int invL=inv(p_lim);
			for(int i=0;i<p_lim;i++) mulmod(a[i],invL);
		}
	}
	poly operator*(poly a,poly b) {
		unsigned int tlen=a.size()+b.size()-1;
		getR(a.size()+b.size()-1); a.resize(p_lim),b.resize(p_lim);
		ntt(a,1),ntt(b,1); for(int i=0;i<p_lim;i++) mulmod(a[i],b[i]);
		ntt(a,-1); a.resize(tlen); return a;
	}
	poly operator+(poly a,poly b) {
		if(a.size()<b.size()) swap(a,b);
		for(int i=0;i<b.size();i++) addmod(a[i],b[i]);
		return a;
	}
	poly operator-(poly a,poly b) {
		while(a.size()<b.size()) a.pb(0);
		for(int i=0;i<b.size();i++) submod(a[i],b[i]);
		return a;
	}
	poly operator*(int b,poly a) {
		for(int i=0;i<a.size();i++) mulmod(a[i],b);
		return a;
	}
	poly Inv(poly a) {
		if(a.size()==1) return a[0]=inv(a[0]),a;	int n=a.size();
		poly h=a; h.resize((n+1)>>1);
		poly b=Inv(h); getR(2*n); b.resize(p_lim),a.resize(p_lim);
		ntt(a,1),ntt(b,1); for(int i=0;i<p_lim;i++) mulmod(b[i],(P+2-mul(a[i],b[i])));
		ntt(b,-1); b.resize(n); return b;
	}
	void Dao(poly &a) {
		int n=a.size();
		for(int i=1;i<n;i++) a[i-1]=mul(i,a[i]);
		a[a.size()-1]=0;	
	}
	void Jifen(poly &a) {
		int n=a.size();
		foR(i,n-1,1) a[i]=mul(inv(i),a[i-1]);
		a[0]=0;	
	}
	poly Ln(poly a) {
		poly tmp=a; Dao(tmp);	
		int n=a.size(); a=tmp*Inv(a); Jifen(a);
		a.resize(n); return a;
	}
	poly Exp(poly a) {
		if(a.size()==1) return a[0]=1,a;
		int n=a.size(); poly h=a; h.resize((n+1)>>1);
		poly b=Exp(h); b.resize(n); poly tb=Ln(b); 
		for(int i=0;i<n;i++) tb[i]=(P+a[i]-tb[i]) % P; tb[0]++;
		b=b*tb; b.resize(n);
		return b;
	}
	poly submul(poly a,poly b) { // ans[i]=a(j)b(j-i)
		int n=a.size(); reverse(a.begin(),a.end());
		a=a*b; a.resize(n); reverse(a.begin(),a.end());
		return a;
	}
} using namespace POLY;
int a[MN],p[MN],para[MN],tpara[MN];
void solve(int l,int r) {
	if(l==r) return; int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r); 
	poly F(mid-l+1),G(r-mid);
	For(i,l,mid) F[i-l]=pw[pre[i]];
	For(i,mid+1,r) G[i-mid-1]=pw[suf[i]];
	F=F*G;
	For(i,0,SZ(F)-1) {
		int pos=i+l+mid+1;
		if(pos&1) continue;
//		cerr<<l<<' '<<r<<' '<<pos/2<<endl;
		addmod(para[pos/2],sub(F[i],min(i+1,SZ(F)-i)));	
	}
}

void works() {
	init();
	n=read(),m=read();
	For(i,1,n) a[i+n]=read();
	For(i,1,m) p[read()+n]=1;
	n*=3; 
	For(i,1,n) pre[i]=pre[i-1]+p[i];
	foR(i,n,1) suf[i]=suf[i+1]+p[i];
	int ans=0; 
//	For(A,1,n) {
//		For(B,A+1,n) {
//			if((A+B)&1) continue;
//			addmod(tpara[(A+B)/2],pw[pre[A]+suf[B]]-1);
//		}
//	}
	solve(1,n);
//	fprint(para,n),fprint(tpara,n);
	int fans=0;
	For(i,1,n) addmod(fans,mul(a[i],para[i]));
	cout<<mul(fans,inv(pw[m]-1))<<endl;
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
/*

*/