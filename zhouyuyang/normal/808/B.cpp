#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1000005
#define ll long long 
using namespace std;
int n,k;
ll a[200005];
double ans;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for (int i=1;i<=n;i++) a[i]+=a[i-1];
	for (int i=1,j=k;j<=n;i++,j++)
		ans+=(a[j]-a[i-1])*1.0/(n-k+1);
	printf("%.10lf",ans);
}