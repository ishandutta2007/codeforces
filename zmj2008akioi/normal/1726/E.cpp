#include <cstdio>
const int N=3e5+10,P=998244353;
int T,n,g[N],prd[N],qprd[N],ipr[N];
int C(int n,int m){return 1ll*prd[n]*ipr[m]%P*ipr[n-m]%P;}
int qpow(int b,int p){
	int pw=1,rs=1,nw=b,rm=p;
	for(;rm;pw<<=1,nw=1ll*nw*nw%P)if(rm&pw)rm^=pw,rs=1ll*rs*nw%P;
	return rs;
}
int main(){
	scanf("%d",&T),prd[0]=1,n=3e5;
	for(int i=1;i<=n;++i)prd[i]=1ll*prd[i-1]*i%P;
	ipr[n]=qpow(prd[n],P-2);
	for(int i=n-1;~i;--i)ipr[i]=1ll*ipr[i+1]*(i+1)%P;
	qprd[0]=1;
	for(int i=1;(i<<2)<=n;++i)qprd[i]=2ll*qprd[i-1]*C(i<<1,2)%P;
	g[0]=g[1]=1;for(int i=2;i<=n;++i)g[i]=(g[i-1]+1ll*(i-1)*g[i-2])%P;
	while(T--){
		scanf("%d",&n);long long ans=0;
		for(int i=0;(i<<2)<=n;++i)ans+=1ll*C(n-(i<<2)+(i<<1),i<<1)*qprd[i]%P*ipr[i]%P*g[n-(i<<2)]%P;
		printf("%lld\n",ans%P);
	}
	return 0;
}