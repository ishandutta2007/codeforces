#include<cstdio> 
const int N=1005;
int f[N][15][N],n,d,i,j,mo,k,l,inv[N];
inline int C(int x,int y){
	if(x<y)return 0;
	register int ans=1,i=1;
	for(;i<=y;++i)ans=1ll*ans*inv[i]%mo*(x-i+1)%mo;return ans;
}
int main(){
	scanf("%d%d%d",&n,&d,&mo);
	if(n<=2)return puts("1"),0;
	for(i=2,inv[1]=1;i<=d;++i)inv[i]=1ll*(mo-mo/i)*inv[mo%i]%mo;
	for(i=0;i<=n;++i)f[1][0][i]=1;
	for(i=2;i<=n;++i)		
		for(j=1;j<i && j<=d;++j)
			for(k=1;k<=n;++k){
				f[i][j][k]=f[i][j][k-1];
				for(l=1;l*k<i && l<=j;++l)
					f[i][j][k]=(f[i][j][k]+1ll*f[i-k*l][j-l][k-1]*
						C(f[k][k>1?d-1:0][k-1]+l-1,l))%mo;
				//printf("f[%d][%d][%d]=%d\n",i,j,k,f[i][j][k]);
			}
	j=f[n][d][n>>1];
	if(!(n&1))j=(j+mo-C(f[n>>1][d-1][n>>1],2))%mo;
	return printf("%d\n",j),0;
}