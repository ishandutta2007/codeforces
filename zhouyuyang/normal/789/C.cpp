#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
ll a[100005],ans,f[100005];
int n;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	for (int i=1;i<n;i++) a[i]=abs(a[i]-a[i+1]);
	a[n]=0;
	ans=a[1];
	for (int i=2;i<n;i++){
		f[i]=max(0ll,f[i-2])+a[i-1]-a[i];
		ans=max(ans,f[i]+a[i+1]);
		ans=max(ans,a[i]);
	}
	printf("%I64d",ans);
}