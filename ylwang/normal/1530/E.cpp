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
inline int read() {int x; FI(x); return x;}
const int MN=4e5+5;
char s[MN]; 
int ans[MN]; int n,cnt[28];
void doit(int x) {
	int now=x-1;
	For(i,0,25) {
		while(cnt[i]) ans[++now]=i,cnt[i]--;
	}
}
int check(int mn,int se) {
	if(cnt[mn]-2>(n-2)/2) return 0;
	else {
//	cerr<<mn<<' '<<cnt[mn]<<endl;;
		ans[0]=ans[1]=mn; cnt[mn]-=2;
		for(int i=3;i<=n;i+=2) {
			if(cnt[mn]) {
//				cerr<<i<<endl;
				ans[i]=mn;
				cnt[mn]--;
			}
		}
		
//		For(i,0,n-1) printf("%d",ans[i]);
//		printf("\n");
//		assert(!cnt[mn]);
		int now=2;
		For(i,mn+1,25) {
			while(cnt[i]) {
				while(ans[now]!=-1) {
					assert(now<=n);
					now++;
				}
				ans[now]=i; cnt[i]--;
			}
		}
	}
	return 1;
}
void doit2(int mn,int se) {
	

	int oth=n-cnt[mn]-cnt[se],now=0;
	ans[0]=mn,ans[1]=se;
	cnt[mn]--,cnt[se]--;
	if(oth==0) {
		now=1; 
//		cerr<<cnt[se]<<endl;
		while(cnt[se]) ans[++now]=se,cnt[se]--;
		while(cnt[mn]) ans[++now]=mn,cnt[mn]--;
	} else {
		now=1;
		
		while(cnt[mn]) ans[++now]=mn,cnt[mn]--;
//		fprint(cnt-1,26);
//		cerr<<cnt[se+1]<<' '<<cnt[se]<<endl;
//		cerr<<"?"<<' '<<mn<<' '<<se<<endl;
		For(i,se+1,25) if(cnt[i]) {
//			cerr<<i<<endl;
			ans[++now]=i; cnt[i]--; break;	
		}
		doit(now+1);
	}
}
void work() {
	FI(s+1); n=strlen(s+1);
	For(i,0,25) cnt[i]=0; For(i,0,n) ans[i]=-1;
	For(i,1,n) {
		cnt[s[i]-'a']++;
	}
//	fprint(cnt,26);
//	c
	int mn=-1,se=-1;
	For(i,0,25) {
		if(cnt[i]==1) {
			ans[0]=i; cnt[i]--; doit(1);
			goto end;	
		} else if(cnt[i]>1) {
			if(mn==-1) mn=i;
			else if(se==-1) {se=i; }
		}
	}
//	cerr<<"?";
	if(se==-1) {doit(0); goto end;}
	if(check(mn,se)) goto end;
	doit2(mn,se);
	end:;
	For(i,0,n-1) printf("%c",ans[i]+'a');
	printf("\n");
}
signed main() {
	#ifndef ONLINE_JUDGE
		freopen("pro.in","r",stdin);
		freopen("pro.out","w",stdout);
	#endif
	int T=read();
	while(T--) {
		work();
		
	}
	return FastIO::Fflush(),0;
}