#include<bits/stdc++.h>
using namespace std;
int n,a[55555],i=1;
pair<int,int>p[55555];
int main(){
	for (scanf("%d",&n);i<=n;scanf("%d",&a[i++]));
	a[0]=a[n];
	for (i=1;i<=n;i++) p[i]=make_pair(a[i-1]+a[i],i);
	sort(p+1,p+n+1);
	for (i=1;i<=n;i++) a[(int)p[i].second]=i-1;
	a[n+1]=a[1];
	for (i=2;i<=n+1;printf("%d ",a[i++]));
}