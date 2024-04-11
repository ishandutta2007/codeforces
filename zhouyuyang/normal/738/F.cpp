#include<bits/stdc++.h>
using namespace std;
int s[4005],f[2105][190][90][2];
bool vis[2105][190][90][2];
int n,x;
int dfs(int l,int r,int k,int fl){
	int d=(l-1)-(n-r);
	if (vis[l][d+92][k][fl])
		return f[l][d+92][k][fl];
	vis[l][d+92][k][fl]=1;
	int &ans=f[l][d+92][k][fl];
	if (fl==0){
		if (l+k-1==r) return ans=s[r]-s[l-1];
		if (l+k-1>r) return ans=0;
		return ans=max(dfs(l+k,r,k,fl^1)+s[l+k-1]-s[l-1],
					   dfs(l+k+1,r,k+1,fl^1)+s[l+k]-s[l-1]);
	}
	else{
		if (l+k-1==r) return ans=-s[r]+s[l-1];
		if (l+k-1>r) return ans=0;
		return ans=min(dfs(l,r-k,k,fl^1)-s[r]+s[r-k],
					   dfs(l,r-k-1,k+1,fl^1)-s[r]+s[r-k-1]);
	}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&x),s[i]=s[i-1]+x;
	printf("%d\n",dfs(1,n,1,0));
}