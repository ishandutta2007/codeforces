#include <cstdio>
typedef long long LL;
const int N=2e3+10,P=998244353;
int T,n,m,k,s[N][N];
template<typename T>T min(T x,T y){return x<y?x:y;}
int qpow(int b,int p){
	int pw=1,rs=1,nw=b,rm=p;
	for(;rm;pw<<=1,nw=(LL)nw*nw%P)if(rm&pw)rm^=pw,rs=(LL)rs*nw%P;
	return rs;
}
namespace IO{
	int lt,nw,res,dig[30];char c;
	int read(){
		res=0;for(;c<'0'||c>'9';c=getchar());
		for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
		return res;
	}
	void write(int x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);putchar('\n');
	}
}using IO::read;using IO::write;
void init(){
	const int n=2e3;s[0][0]=1;
	for(int i=1;i<=n;++i)for(int j=1;j<=i;++j)s[i][j]=(s[i-1][j-1]+(LL)j*s[i-1][j])%P;
}
int main(){
	T=read(),init();
	while(T--){
		n=read(),m=read(),k=read();
		int x=(m+1)>>1,p=qpow(m,n),iv=qpow(m,P-2);LL ans=0;
		for(int i=1;i<=k;++i)p=(LL)p*(n-i+1)%P*x%P*iv%P,ans+=(LL)s[k][i]*p%P;
		write(ans%P);
	}
	return 0;
}