#include<bits/stdc++.h>
#define maxn 1001000
#define mod 1000000007
using namespace std;
int n,l,m,A[maxn],B[maxn],C[maxn];
int D[110],E[110],F[110];
struct matrix{
	int a[110][110];
	matrix(){memset(a,0,sizeof(a));}
	matrix operator*(const matrix& ma)const{
		matrix ret;
		for(int i=0;i<m;++i)
			for(int j=0;j<m;++j)
				for(int k=0;k<m;++k)
					ret.a[i][j]=(ret.a[i][j]+1ll*a[i][k]*ma.a[k][j])%mod;
		return ret;
	}
}ans,tmp;
int sum=0;
int qpow(int a,int b){
	int ans=1,tmp=a;
	for(;b;b>>=1,tmp=1ll*tmp*tmp%mod)
		if(b&1)ans=1ll*ans*tmp%mod;
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&l,&m);
	for(int i=1;i<=n;++i)scanf("%d",&A[i]),D[A[i]%m]++;
	for(int i=1;i<=n;++i)scanf("%d",&B[i]),E[B[i]%m]++;
	for(int i=1;i<=n;++i)scanf("%d",&C[i]),F[(C[i]+B[i])%m]++;
	for(int i=0;i<m;++i)ans.a[i][i]=1;
	for(int i=0;i<m;++i)
		for(int j=0;j<m;++j)
			tmp.a[i][(i+j)%m]=E[j];
	l-=2;
	for(;l;l>>=1,tmp=tmp*tmp)if(l&1)ans=ans*tmp;
	for(int i=0;i<m;++i)
		for(int j=0;j<m;++j)
			sum=(sum+1ll*D[i]*ans.a[i][j]%mod*F[(m-j)%m])%mod;
	printf("%d",sum);	
}