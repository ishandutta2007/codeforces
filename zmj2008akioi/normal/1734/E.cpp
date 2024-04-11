#include <cstdio>
const int N=360;
int n,a[N][N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i][i]),a[i][i]=(a[i][i]-i*i+n*n)%n;
	for(int i=2;i<=n;++i){
		a[i][1]=0;
		for(int j=2;j<i;++j)a[i][j]=(a[i][j-1]+a[i-1][j]+n-a[i-1][j-1])%n;
		a[i-1][i]=(a[i][i]+a[i-1][i-1]-a[i][i-1]+n)%n;
		for(int j=i-2;j;--j)a[j][i]=(a[j+1][i]+a[j][i-1]+n-a[j+1][i-1])%n;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)printf("%d ",(a[i][j]+i*j)%n);
		putchar('\n');
	}
	return 0;
}