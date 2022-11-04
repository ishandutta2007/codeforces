#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
ll a[300005],p,l,m,ans,b[300005];
int main(){
	scanf("%I64d%I64d%I64d%I64d",&a[1],&p,&l,&m);
	for (int i=1;i<=m;i++) scanf("%I64d",&b[i]);
	b[m+1]=1e18; b[m+2]=-1e18;
	sort(b+1,b+m+3);
	ans=0;
	for (int i=1;i<=300000;i++){
		if (i!=1) a[i]=a[i-1]*p;
		if (a[i]>l||a[i]<-l) break;
		int k=lower_bound(b+1,b+m+3,a[i])-b;
		if (b[k]!=a[i]) ans++;
	}
	if (ans>110000) printf("inf");
	else printf("%I64d",ans);
}