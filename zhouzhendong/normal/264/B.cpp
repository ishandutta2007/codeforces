#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,dp[N],a[N];
int f[N],p[N],cnp;
void Prime(){
	cnp=0;
	for (int i=2;i<N;i++){
		if (f[i])
			continue;
		p[++cnp]=i;
		for (int j=i*2;j<N;j+=i)
			f[j]=1;
	}
}
int main(){
	scanf("%d",&n);
	int ans=1;
	Prime();
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]==1)
			continue;
		int x[233],tot=0;
		int v=1;
		for (int j=1;p[j]*p[j]<=a[i]&&j<=cnp;j++){
			if (a[i]%p[j])
				continue;
			x[++tot]=p[j];
			v=max(dp[p[j]]+1,v);
			while (a[i]%p[j]==0)
				a[i]/=p[j];
		}
		if (a[i]>1){
			x[++tot]=a[i];
			v=max(dp[a[i]]+1,v);
		}
		for (int i=1;i<=tot;i++)
			dp[x[i]]=max(dp[x[i]],v);
		ans=max(ans,v);
	}
	printf("%d",ans);
	return 0;
}