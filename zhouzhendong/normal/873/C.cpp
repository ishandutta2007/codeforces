#include <bits/stdc++.h>
using namespace std;
const int N=205;
int n,m,k,a[N][N],v[N][N];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for (int i=n;i>=1;i--)
		for (int j=1;j<=m;j++)
			v[i][j]=v[i+1][j]+a[i][j]-a[i+k][j];
	int ans1=0,ans2=0;
	for (int j=1;j<=m;j++){
		int Max=1;
		for (int i=2;i<=n;i++)
			if (v[i][j]>v[Max][j])
				Max=i;
		ans1+=v[Max][j];
		for (int i=1;i<Max;i++)
			ans2+=a[i][j];
	}
	printf("%d %d",ans1,ans2);
	return 0;
}