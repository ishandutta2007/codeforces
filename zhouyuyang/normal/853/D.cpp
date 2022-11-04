#include<bits/stdc++.h>
#define N 300005
using namespace std;
int a[N],f[N][35],n,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i]/=100;
	memset(f,60,sizeof(f));
	f[0][0]=0;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=31;j++){
			if (j+a[i]/10<=31)
				f[i][j+a[i]/10]=min(f[i][j+a[i]/10],f[i-1][j]+a[i]);
			f[i][j-min(a[i],j)]=min(f[i][j-min(a[i],j)],f[i-1][j]+a[i]-min(a[i],j));
		}
	ans=1e9;
	for (int i=0;i<=31;i++)
		ans=min(ans,f[n][i]);
	printf("%d",ans*100);
}