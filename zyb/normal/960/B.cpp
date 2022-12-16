#include<bits/stdc++.h>
#define N 100005
using namespace std;
int a[N],b[N],i,j,k,l,s,n,m,k1,k2;
priority_queue<int>GT;
long long ans;
int main() {
	scanf("%d%d%d",&n,&k1,&k2);
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	for (i=1;i<=n;i++) scanf("%d",&b[i]);
	for (i=1;i<=n;i++) GT.push(abs(b[i]-a[i]));
	k=k1+k2;
	while(k) {
		int gt=GT.top();
		GT.pop();
		GT.push(abs(gt-1));
		k--;
	}
	while(!GT.empty()) {
		int gt=GT.top();
		ans+=1ll*gt*gt;
		GT.pop();
	}
	printf("%I64d\n",ans);
}