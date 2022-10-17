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
#define INF ((1<<30)-1)
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
const int MN=2005+10;
string s[105]; 

char get(string s,string t) {
	int cnt[26]; mst(cnt,0); 
	for(auto it:s) cnt[it-'a']++; 
	for(auto it:t) cnt[it-'a']--; 
	For(i,0,25) if(cnt[i]) {cnt[i]=0; return i+'a';}
	return -1;  
}
string solve(int n) {
	cout<<"? "<<1<<' '<<n<<endl; 
	multiset<string>tmp;  
	For(i,1,(n+1)*n/2) {string s; cin>>s; sort(s.begin(),s.end()); tmp.insert(s); }
	if(n==1) {
		return *tmp.begin(); 	
	}
	cout<<"? "<<2<<' '<<n<<endl; 
	For(i,1,n*(n-1)/2) {string s; cin>>s; sort(s.begin(),s.end()); tmp.erase(tmp.find(s)); }
	int t=0; for(auto it:tmp) s[++t]=it; 
	sort(s+1,s+1+t,[&](string x,string y){return SZ(x)<SZ(y);}); 
	string ans; 
	For(i,1,n) {
		if(i==1) ans+=s[1][0]; 
		else {
			ans+=get(s[i],s[i-1]); 
		}
	}
	return ans; 
}
int cnt[MN][26],suf[MN][26],now[26],z[26]; 
void works() {
	int n; cin>>n; 
	if(n<=2) {
		string ans=solve(n); 
		cout<<"! "<<ans<<endl; 
	}	
	else {
		string tmp=solve(n/2); 
		cout<<"? "<<1<<' '<<n<<endl; 
		For(i,1,(n+1)*n/2) {
			string s; cin>>s; 
			int l=SZ(s); 
			for(auto it:s) cnt[l][it-'a']++; 
		}
		For(l,0,n/2) {
			For(i,0,25) cnt[l][i]=cnt[l+1][i]-cnt[l][i]; 
		}
		foR(i,n/2,0) {
			if(i) suf[i][tmp[i-1]-'a']++; 
			For(j,0,25) suf[i][j]+=suf[i+1][j];  
		}
		foR(i,(n-1)/2,0) {
			int l=i+1,r=n-i;
			For(j,0,25) z[j]=cnt[i][j]-suf[l][j]-now[j]; 
			For(j,0,25) {
				if(z[j]) {
					
					now[j]++,tmp.pb(j+'a');
					z[j]=0; break;  	
				}	
			}
		}
		cout<<"! "<<tmp<<endl; 
	}
}
signed main() {
//	#ifdef wasa855
//		freopen("pro.in","r",stdin);
//		freopen("pro.out","w",stdout);
//	#endif
//	IOS; 
	int T=1;
	while(T--) {
		works(); 	
	}
	return FastIO::Fflush(),0;
}
/*
  
*/