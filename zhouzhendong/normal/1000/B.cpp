#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,a[N],t[N];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(t,0,sizeof t);
	a[n+1]=m;
	for (int i=1;i<=n+1;i++){
		t[i]=t[i-1];
		if (i&1)
			t[i]+=a[i]-a[i-1];
	}
	int ans=t[n+1];
	for (int i=1;i<=n+1;i++){
		if (a[i]-a[i-1]<=1)
			continue;
		ans=max(ans,t[i-1]+a[i]-a[i-1]-1+(m-a[i])-(t[n+1]-t[i]));
	}
	printf("%d",ans);
	return 0;
}