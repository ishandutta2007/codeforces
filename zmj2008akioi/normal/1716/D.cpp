#include <cstdio>
const int b=650,N=2e5+10,P=998244353;
int n,k,ans[N],f[N],g[N];
int main(){
	scanf("%d %d",&n,&k),f[0]=1;
	for(int i=k;i<k+b;++i){
		for(int j=0;j<=n;++j)g[j]=0;
		for(int j=i;j<=n;++j)g[j]=(g[j-i]+f[j-i])%P;
		for(int j=0;j<=n;++j)ans[j]=(ans[j]+(f[j]=g[j]))%P;
	}
	for(int i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}