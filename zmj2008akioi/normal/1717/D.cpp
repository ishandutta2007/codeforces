#include <cstdio>
const int N=1e5+10,P=1e9+7;
int n,k,prd[N],ipr[N];
int C(int n,int m){return 1ll*prd[n]*ipr[m]%P*ipr[n-m]%P;}
int qpow(int b,int p){
	int pw=1,rs=1,nw=b,rm=p;
	for(;rm;pw<<=1,nw=1ll*nw*nw%P)if(rm&pw)rm^=pw,rs=1ll*rs*nw%P;
	return rs;
}
int main(){
	scanf("%d %d",&n,&k);
	if(k>=n){printf("%d",qpow(2,n));return 0;}
	prd[0]=1;for(int i=1;i<=n;++i)prd[i]=1ll*prd[i-1]*i%P;
	ipr[n]=qpow(prd[n],P-2);for(int i=n-1;~i;--i)ipr[i]=1ll*ipr[i+1]*(i+1)%P;
	int ans=1;for(int i=1;i<=k;++i)ans=(ans+C(n,i))%P;
	printf("%d",ans);return 0;
}