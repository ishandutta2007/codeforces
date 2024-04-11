#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int a[10],b[10],c[10],n,x,ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]++;
	}
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		b[x]++;
	}
	for (int i=1;i<=5;i++) c[i]=a[i]+b[i];
	for (int i=1;i<=5;i++)
		if (c[i]&1){
			printf("-1");
			return 0;
		}
		else c[i]/=2;
	for (int i=1;i<=5;i++) ans+=abs(a[i]-c[i]);
	printf("%d",ans/2);
}