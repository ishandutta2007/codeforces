#include<bits/stdc++.h>
const int N=4005;
int T,n,i,j,f[N][N],p[N];
inline void upa(int&a,const int&b){a<b?a=b:0;}
int main(){
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);for(i=1;i<=n*2;++i)scanf("%d",p+i);
		for(i=0;i<=n*2;++i)for(j=0;j<=n*2;++j)f[i][j]=0;
		f[n*2][0]=n*2+1;
		for(i=n*2-1;i;--i)for(j=0;j<n*2-i;++j)if(f[i+1][j]>0){
			if(p[i]<f[i+1][j])upa(f[i][j],f[i+1][j]);
			if(p[i]<p[i+1])upa(f[i][n*2-i-j],p[i+1]);
		}
		puts(f[1][n]>0?"YES":"NO");
	}
}