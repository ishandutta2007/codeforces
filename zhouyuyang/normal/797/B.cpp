#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,a[100005],f[100005][2];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0][0]=0; f[0][1]=-2000000000;
	for (int i=1;i<=n;i++){
		f[i][0]=f[i-1][0]; f[i][1]=f[i-1][1];
		f[i][(a[i]+10000)%2]=max(f[i][(a[i]+10000)%2],f[i-1][0]+a[i]);
		f[i][(a[i]+10001)%2]=max(f[i][(a[i]+10001)%2],f[i-1][1]+a[i]);
	}
	printf("%d",f[n][1]);
}