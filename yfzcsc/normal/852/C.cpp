#include<bits/stdc++.h>
#define maxn 50010
using namespace std;
typedef pair<int,int> par;
int n,a[maxn];
par b[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	a[n+1]=a[1];
	for(int i=1;i<=n;++i)
		b[i]=par(a[i]+a[i+1],i);
	sort(b+1,b+n+1);
	for(int i=1;i<=n;++i)
		a[b[i].second]=i-1;
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
}