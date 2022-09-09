#include<bits/stdc++.h>
const int N=1005,mo=1000000007;
int k,i,j,f[1005],C[N][N],n,x,ans;
char c[1005];
inline int calc(int y){
	int ans=0,i,j;
	for(i=1,j=0;i<=n;++i)j+=c[i];
	ans=j==y;j=0;
	for(i=1;i<=n;++i){
		if(c[i] && y>=j)ans=(ans+C[n-i][y-j])%mo;
		j+=c[i];
	}
	return ans;
}
int main(){
	scanf("%s%d",c+1,&k);n=strlen(c+1);
	if(k==0)return puts("1"),0;
	for(i=1;i<=n;++i)c[i]-=48;	
	for(i=**C=1;i<=n;++i)
		for(j=*C[i]=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mo;
	for(i=2;i<N;++i){
		x=0;
		for(j=9;j>=0;--j)x+=i>>j&1;
		f[i]=f[x]+1;
	}
	for(i=1;i<N;++i)
		if(f[i]==k-1)
			ans=(ans+calc(i))%mo;
	if(k==1)--ans;
	printf("%d\n",ans);
	return 0;
}