#include <cstdio>
int T,x,y;
long long ans;
namespace basic{
	int lt,res,dig[50];
	long long nw;char cdc;
	template<typename T>T min(T x,T y){return x<y?x:y;}
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
}using basic::min;using basic::read;using basic::write;
inline long long f(int l,int r){
	if(r<0)return 0;if(l<0)l=0;
	return ((long long)(l+r)*(r-l+1))>>1;
}
int main(){
	T=read();
	while(T--){
		x=read(),y=read(),ans=0;
		for(int p,q,j=1;j<=x;j=p+1){
			p=x/(x/j),q=min(y,x/j-1);
			ans+=f(q-p,q-j);
		}
		write(ans);
	}
	return 0;
}