#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull h[5010],h2[5010],pw[5010]={1};
int n,dp[5010][5010],anses[5010];
char s[5010];
ull get(int l,int r){return h[r]-h[l-1]*pw[r-l+1];}
ull get2(int l,int r){return h2[r]-h2[l+1]*pw[l-r+1];}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)h[i]=h[i-1]*19260817+s[i],pw[i]=pw[i-1]*19260817;
	for(int i=n;i>=1;--i)h2[i]=h2[i+1]*19260817+s[i];
	for(int i=1;i<=n;++i)dp[i][i]=1;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j){
			int len=(j-i+1)/2;
		//	printf("[ok,%d,%d,%d,%d]",i,j,len,dp[i][i+len-1]);
			if(dp[i][i+len-1]&&get(i,i+len-1)==get(j-len+1,j))dp[i][j]=dp[i][i+len-1]+1;
			else dp[i][j]=(get(i,j)==get2(j,i));
		}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			anses[dp[i][j]]++;
	for(int i=n;i>=1;--i)anses[i]+=anses[i+1];
	for(int i=1;i<=n;++i)printf("%d ",anses[i]);
}