#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300005,M=30;
int a[N],f[N][M+5],j,n,i,ans,t;
inline void up(int&a,int b){
	if(!a || a>b)a=b;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i),a[i]/=100;
	for(i=0;i<n;++i)
		for(j=0;j<=M;++j)if(f[i][j] || (!i && !j)){
			up(f[i+1][j+a[i+1]/10],f[i][j]+a[i+1]);
			t=min(j,a[i+1]);
			up(f[i+1][j-t],f[i][j]+a[i+1]-t);
		}
	for(i=0;i<=M;++i)if(f[n][i])up(ans,f[n][i]);
	printf("%d\n",ans*100);
	return 0;
}