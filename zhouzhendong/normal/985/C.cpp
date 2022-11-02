#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int n,k,L,m,a[N];
int main(){
	scanf("%d%d%d",&n,&k,&L);
	m=n*k;
	for (int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+m+1);
	int p=1;
	while (p<=m&&a[p+1]-a[1]<=L)
		p++;
	if (p<n){
		puts("0");
		return 0;
	}
	// p<=x+k*(n-x)
	// (k-1)x<=m-p
	// x<=(m-p)/(k-1)
	if (k==1){
		LL ans=0;
		for (int i=1;i<=n;i++)
			ans+=a[i];
		printf("%I64d",ans);
		return 0;
	}
	int x=(m-p)/(k-1),y=n-x;
	LL ans=0;
	for (int i=1;i<=y;i++)
		ans+=a[(i-1)*k+1];
	for (int i=p;i>=p-x+1;i--)
		ans+=a[i];
	printf("%I64d",ans);
	return 0;
}