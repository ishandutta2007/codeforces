#include<bits/stdc++.h>
using namespace std;
int a[300005],n;
int ans[300005];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ans[n-1]=max(ans[n-1],a[i]);
	}
	for (int i=1;i<n;i++){
		int tmp=abs((i-1)-(n-i-1));
		ans[tmp]=max(ans[tmp],max(a[i],a[i+1]));
	}
	for (int i=2;i<n;i++){
		int tmp=abs((i-2)-(n-i-1));
		ans[tmp]=max(ans[tmp],min(a[i],max(a[i-1],a[i+1])));
	}
	for (int i=3;i<=n;i++)
		ans[i]=max(ans[i],ans[i-2]);
	for (int i=0;i<n;i++)
		printf("%d ",ans[i]);
}