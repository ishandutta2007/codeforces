#include<cstdio>
#include<cctype>
inline int getint(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-1;
		c=getchar();
	}
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x*f;
}
const int A=1000005,N=200005,mo=1000000007;
int n,i,w,a[N],j,tw[N],d[A],ma,s[A],ans,x;
inline int got(int x){
	return 1ll*x*tw[x-1]%mo;
}
int main(){
	n=getint();
	for(i=1;i<=n;++i){
		a[i]=getint();
		if(a[i]>ma)ma=a[i];
		++s[a[i]];
	}
	for(i=*tw=1;i<=n;++i)tw[i]=(tw[i-1]<<1)%mo;
	for(i=ma;i>1;--i){
		x=0;
		for(j=i;j<=ma;j+=i)x+=s[j];
		if(x){
			d[i]=got(x);
			for(j=i<<1;j<=ma;j+=i)d[i]=(d[i]+mo-d[j])%mo;
			ans=(ans+1ll*d[i]*i)%mo;
		}
	}
	printf("%d\n",ans);
	return 0;
}