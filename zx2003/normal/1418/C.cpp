#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,a[N],f[N][2],i,j,k;
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d",a+i);
		f[0][1]=0;f[0][0]=1<<30;
		for(i=1;i<=n;++i)for(j=0;j<2;++j){
			f[i][j]=1<<30;
			int x=0;
			for(k=1;k<=2 && k<=i;++k){
				x+=a[i-k+1]==1 && !j; 
				f[i][j]=min(f[i][j],f[i-k][j^1]+x);
			}
		}
		printf("%d\n",min(f[n][0],f[n][1]));
	}
}