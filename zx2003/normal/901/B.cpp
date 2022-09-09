#include<cstdio>
const int N=155;
int f[N][N],n,i,j;
bool b;
int main(){
	f[1][0]=1;scanf("%d",&n);
	for(i=1;i<=n;++i){
		for(j=0;j<i;++j)f[i+1][j+1]=f[i][j];
		for(j=b=0;j<i-1;++j)if(f[i+1][j] && f[i-1][j] && f[i+1][j]==f[i-1][j])b=1;
		if(b)for(j=0;j<i-1;++j)f[i+1][j]-=f[i-1][j];
			else for(j=0;j<i-1;++j)f[i+1][j]+=f[i-1][j];
	}
	printf("%d\n",n);
	for(i=0;i<=n;++i)printf("%d ",f[n+1][i]);
	printf("\n%d\n",n-1);
	for(i=0;i<n;++i)printf("%d ",f[n][i]);
	return 0;
}