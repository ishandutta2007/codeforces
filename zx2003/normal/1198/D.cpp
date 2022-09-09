#include<bits/stdc++.h>
const int N=55;
int n,i,j,k,l,o,f[N][N][N][N],s1[N][N],s2[N][N];
char c[N][N];
inline void upi(int&a,const int&b){a>b?a=b:0;}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%s",c[i]+1);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)s1[i][j]=s1[i][j-1]+(c[i][j]=='#'),s2[i][j]=s2[i-1][j]+(c[i][j]=='#');
	for(i=0;i<n;++i)for(j=1;j+i<=n;++j)for(k=0;k<n;++k)for(l=1;l+k<=n;++l){
		f[j][j+i][l][l+k]=std::max(i+1,k+1);
		for(o=j;o<=j+i;++o)if(s1[o][l-1]==s1[o][l+k])upi(f[j][j+i][l][l+k],f[j][o-1][l][l+k]+f[o+1][j+i][l][l+k]);
		for(o=l;o<=l+k;++o)if(s2[j-1][o]==s2[j+i][o])upi(f[j][j+i][l][l+k],f[j][j+i][l][o-1]+f[j][j+i][o+1][l+k]);
	}
	printf("%d\n",f[1][n][1][n]);
	return 0;
}