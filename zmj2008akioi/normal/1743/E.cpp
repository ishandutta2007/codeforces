#include <cstdio>
typedef long long LL;
const int N=5e3+10;const LL inf=1e18;
int h,s,ls,gls,atk,p1,p2;LL t1,t2,f[N],g[N],dp[N];
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
int main(){
	scanf("%d %lld",&p1,&t1);
	scanf("%d %lld",&p2,&t2);
	scanf("%d %d",&h,&s);
	LL s1=t1,s2=t2;do{
		if(s1<s2){
			for(int i=gls+1;i<=atk+p1+p2-s&&i<=h;++i)g[i]=s2;
			gls=atk+p1+p2-s,atk+=p1-s;
			for(int i=ls+1;i<=atk&&i<=h;++i)f[i]=s1;
			ls=atk,s1+=t1;
		}
		else{
			for(int i=gls+1;i<=atk+p1+p2-s&&i<=h;++i)g[i]=s1;
			gls=atk+p1+p2-s,atk+=p2-s;
			for(int i=ls+1;i<=atk&&i<=h;++i)f[i]=s2;
			ls=atk,s2+=t2;
		}
	}while(atk<h);
	LL ans=f[h];
	for(int i=1;i<=h;++i){
		dp[i]=inf;
		for(int j=0;j<i;++j)cmin(dp[i],dp[j]+g[i-j]);
		cmin(ans,dp[i]+f[h-i]);
	}
	printf("%lld",ans);return 0;
}