#include<stdio.h>
bool a[52][52];int n,dp[52][52][52][52];
inline int Max(int a,int b){return a>b?a:b;}
inline int Min(int a,int b){return a<b?a:b;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		while(getchar()!='\n');
		for(int j=1;j<=n;j++)a[i][j]=getchar()=='#';
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n-i+1;k++){
				for(int l=1;l<=n-j+1;l++){
					if(i==1&&j==1)dp[k][l][k+i-1][l+j-1]=a[k][l];
					else{
						dp[k][l][k+i-1][l+j-1]=Max(i,j);
						for(int m=1;m<i;m++)dp[k][l][k+i-1][l+j-1]=Min(dp[k][l][k+i-1][l+j-1],dp[k][l][k+m-1][l+j-1]+dp[k+m][l][k+i-1][l+j-1]);
						for(int m=1;m<j;m++)dp[k][l][k+i-1][l+j-1]=Min(dp[k][l][k+i-1][l+j-1],dp[k][l][k+i-1][l+m-1]+dp[k][l+m][k+i-1][l+j-1]);
					}
				}
			}
		}
	}printf("%d",dp[1][1][n][n]);
}