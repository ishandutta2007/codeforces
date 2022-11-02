#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,k,x,a[N];
int main(){
	scanf("%d%d%d",&n,&k,&x);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for (int i=1;i<=n-k;i++)
		ans+=a[i];
	ans+=k*x;
	printf("%d",ans);
	return 0;
}