#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int a[200005],b[200005],n,k,ans;
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	for (int i=1;i<=n;i++) ans+=b[i];
	for (int i=1;i<=n;i++) a[i]-=b[i];
	sort(a+1,a+n+1);
	for (int i=1;(i<=k||a[i]<=0)&&i<=n;i++) ans+=a[i];
	printf("%d",ans);
}