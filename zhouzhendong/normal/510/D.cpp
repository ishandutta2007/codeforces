#include <bits/stdc++.h>
using namespace std;
const int N=305;
int n,a[N],b[N],v[300000],tot=0;
map <int,int> dp;
int gcd(int a,int b){
	return b?gcd(b,a%b):a;
}
int main(){
	dp.clear();
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	v[1]=tot=1;
	dp[1]=1e9;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=tot;j++){
			int x=v[j];
			int y=gcd(x,a[i]);
			if (!dp[y])
				dp[y]=1e9,v[++tot]=y;
			dp[y]=min(dp[y],dp[x]+b[i]);
		}
		if (!dp[a[i]])
			dp[a[i]]=1e9,v[++tot]=a[i];
		dp[a[i]]=min(dp[a[i]],b[i]);
	}
	printf("%d",dp[1]<1e9?dp[1]:-1);
	return 0;
}