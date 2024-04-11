#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
#define For(i,x,y,...) for(int i=x,##__VA_ARGS__;i<=(y);++i)
#define rFor(i,x,y,...) for(int i=x,##__VA_ARGS__;i>=(y);--i)
#define Rep(i,x,y,...) for(int i=x,##__VA_ARGS__;i<(y);++i)
#define mem(a,x,n) memset(a,x,sizeof(*(a+0))*(n+1))
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())
#define MT make_tuple
#define pb emplace_back
#define MP make_pair
#define fi first
#define se second
#define priority_queue __gnu_pbds::priority_queue
typedef long long LL; typedef unsigned long long ULL;
typedef pair<int,int> PII; typedef vector<int> VI;
char buf[1<<22],*p1=buf,*p2=buf,pbuf[1<<22],*pp=pbuf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<22,stdin),p1==p2)?EOF:*p1++)
#define ocl() fwrite(pbuf,1,pp-pbuf,stdout),pp=pbuf,0
#define putchar(x) pp-pbuf==1<<22&&(ocl()),*pp++=x
template<typename T>void read(T &x){
	x=0;bool f=1;char c;
	while(!isdigit(c=getchar()))if(c=='-')f=0;
	if(f)for(;isdigit(c);c=getchar())x=x*10+c-48;
	else for(;isdigit(c);c=getchar())x=x*10-c+48;
	if(c=='.')for(T i=f?10:-10;isdigit(c=getchar());i*=10)x+=(c^48)/i;
}
template<typename T,typename ...Args>void read(T &x, Args &...args)
	{ read(x),read(args...); }
template<typename T>void write(T x,char y=10) {
	if(!x)putchar(48);
	else{static int s[44];int l=0;if(x<0)putchar('-'),x=-x;
		for(;x;x/=10)s[l++]=x%10;while(l)putchar(s[--l]|48);}
	putchar(y);
}
template<typename X,typename Y>void ckmax(X &x,Y y) { if( x < y ) x = y; }
template<typename X,typename Y>void ckmin(X &x,Y y) { if( y < x ) x = y; }
const int mod = 1e9+7;
template<typename X,typename Y>void ckadd(X &x,Y y) { x = x+y<mod?x+y:x+y-mod; }
template<typename X,typename Y>void ckdel(X &x,Y y) { x = x-y<0?x-y+mod:x-y; }
LL Pow(LL x,LL y=mod-2) {LL z=1;for(;y;y>>=1,x=x*x%mod)if(y&1)z=z*x%mod;return z;}

struct custom_hash
{
	static uint64_t splitmix64(uint64_t x)
	{
		x+=0x9e3779b97f4a7c15;
		x=(x^(x>>30))*0xbf58476d1ce4e5b9;
		x=(x^(x>>27))*0x94d049bb133111eb;
		return x^(x>>31);
	}
	size_t operator()(uint64_t x)const
	{
		static const uint64_t FIXED_RANDOM=(unsigned long long)(new int);
		return splitmix64(x+ FIXED_RANDOM);
	}
};

const int N = 2e5+5;
int n,b[N];
gp_hash_table<LL,LL,custom_hash> f;

void MAIN() {
	LL del = 0, ans = 0;
	read(n); For(i,1,n) read(b[i]);
	f[b[1]] = ans = 1;
	For(i,2,n) {
		LL tmp = (ans - f[0-del] +mod) %mod;
		del += b[i];
		ckadd(f[b[i]-del],tmp), ckadd(ans,tmp);
	}
	write((ans+mod)%mod);
} signed main() {
#ifdef JK
	freopen("a.in","r",stdin);// freopen("a.out","w",stdout);
#endif
	int t; read(t); while( t-- ) f.clear(), MAIN();
	return ocl();
}