#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,p,a[N],L[N],R[N];
int main(){
	scanf("%d%d",&n,&p);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),L[i]=(L[i-1]+a[i])%p;
	for (int i=n;i>=1;i--)
		R[i]=(R[i+1]+a[i])%p;
	int ans=0;
	for (int i=1;i<n;i++)
		ans=max(ans,L[i]+R[i+1]);
	printf("%d",ans);
	return 0;
}