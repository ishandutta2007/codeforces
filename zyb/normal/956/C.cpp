#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,now,i,a[N],G[N];
long long ans;
int main() {
	scanf("%d",&n);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	G[n+1]=-1000000000;
	for (i=n;i;i--) G[i]=max(G[i+1],a[i]+1-i);
	for (i=1;i<=n;i++) {
		if (now<a[i]+1) now=a[i]+1;
		else if (now-i<G[i]) now++;
		ans+=now-a[i]-1;
	}
	printf("%I64d\n",ans);
}