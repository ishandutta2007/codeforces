#include<cstdio>
const int N=5005,mo=1000000007;
int n,k,f[N][N],i,j,a,ans,inv[N],l;
inline int pow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mo)if(b&1)ans=1ll*ans*a%mo;return ans;
}
inline int P(int a,int b){
	int ans=1,i;
	for(i=1;i<=b;++i)ans=1ll*ans*(a-i+1)%mo;
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=2,inv[1]=1;i<=n;++i)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;**f=1;
	for(i=1;i<=n;++i){
		scanf("%d",&a);
		for(j=*f[i]=1;j<=i;++j)f[i][j]=(f[i-1][j]+1ll*f[i-1][j-1]*a)%mo;
	}
	for(i=j=1,l=inv[n];i<=n && i<=k;++i,j=-j,l=1ll*l*inv[n]%mo)
		ans=(ans+mo+1ll*j*P(k,i)*l%mo*f[n][n-i]%mo)%mo;
	printf("%d\n",ans);
	return 0;
}