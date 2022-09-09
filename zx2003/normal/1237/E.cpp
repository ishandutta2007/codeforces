#include<bits/stdc++.h>
const int N=1e6+5;
int f[N][2],n,i,j;
int main(){
	f[1][1]=f[0][0]=1;
	scanf("%d",&n);
	for(i=2;i<=n;++i)if(i&1){
		int m=i/2;
		f[i][m+1&1]=f[m][m&1]&f[m][0];
	}else for(j=0;j<2;++j){
		int l=i/2-j,r=i-1-l;
		f[i][l+1&1]=f[l][l&1]&f[r][0];
	}
	printf("%d\n",f[n][0]+f[n][1]);
	return 0;
}