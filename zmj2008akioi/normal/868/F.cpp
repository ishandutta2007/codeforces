#include <cstdio>
const int N=1e5+10,K=30;
const long long inf=1e18;
int n,k,lay,a[N],bkt[N];
long long dp[K][N];
namespace basic{
	int lt,res,dig[50];
	long long nw;
	char cdc;
	inline int md(int x,int y){return (x+y)>>1;}
	inline int read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
	inline void write(long long x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);
		putchar('\n');
	}
}using basic::md;using basic::read;using basic::write;
long long f(int l,int r){
	static int p=1,q=0;static long long rec=0;
	while(q<r)rec+=bkt[a[++q]]++;
	while(p>l)rec+=bkt[a[--p]]++;
	while(q>r)rec-=--bkt[a[q--]];
	while(p<l)rec-=--bkt[a[p++]];
	return rec;
}
void megsolve(int l,int r,int ql,int qr){
	int g=ql,mid=md(l,r);dp[lay][mid]=dp[lay-1][ql]+f(ql+1,mid);
	for(int i=ql+1;i<=qr;++i)if(dp[lay][mid]>dp[lay-1][i]+f(i+1,mid))g=i,dp[lay][mid]=dp[lay-1][i]+f(i+1,mid);
	if(l==r)return;megsolve(l,mid,ql,g),megsolve(mid+1,r,g,qr);
}
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i)a[i]=read(),dp[1][i]=f(1,i);
	for(lay=2;lay<=k;++lay)megsolve(1,n,0,n-1);
	write(dp[k][n]);
	return 0;
}