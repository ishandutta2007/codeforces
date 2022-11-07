#include<cstdio>
/*****//*****/
long long ans,n,p,q,r[200002];
long long k[200002];
int main(){
	scanf("%lld",&n);ans=n;
	k[1]=1;
	for(int i=2;i<=n;i++)k[i]=k[i-1]*(long long)i%998244353ll;
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&p,&q);
		r[p]++;r[q]++;
	}
	for(int i=1;i<=n;i++)ans=ans*k[r[i]]%998244353ll;
	printf("%lld",ans);
}