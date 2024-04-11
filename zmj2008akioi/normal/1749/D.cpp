#include <cstdio>
typedef long long LL;
const int N=100,P=998244353;const LL inf=1e12;
int n,p;LL m,s[N];
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
bool isprm(int x){
	for(int i=2;i<x;++i)if(x%i==0)return false;
	return true;
}
int main(){
	scanf("%d %lld",&n,&m),s[0]=1;
	while(s[p]<=inf){
		++p,s[p]=s[p-1];
		if(isprm(p))s[p]*=p;
	}
	int ns=1,np=1;LL ans=0;
	for(int i=1;i<=n;++i){
		ans+=(np=(LL)np*(m%P)%P);
		if(i<=p)ns=(LL)ns*((m/s[i])%P)%P;else ns=0;
		ans+=P-ns;
	}
	printf("%lld",ans%P);return 0;
}