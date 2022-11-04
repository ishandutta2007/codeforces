#include<bits/stdc++.h>
using namespace std;
int n,a[50010];
pair<int,int> b[50010];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	a[n+1]=a[1];
	for(int i=1;i<=n;++i)
		b[i]=make_pair(a[i]+a[i+1],i);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
		a[b[i].second]=i-1;
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
}