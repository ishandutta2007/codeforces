#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring> 
#define ll long long
using namespace std; 
ll bt,et,t,a[100005],mx,ans,n,flag;
int main(){
	scanf("%I64d%I64d%I64d",&bt,&et,&t);
	scanf("%I64d",&n);
	for (int i=1;i<=n;i++) scanf("%I64d",&a[i]);
	if (a[1]>bt){
	    printf("%I64d",bt);
	    return 0;
	}
	ans=0;
	mx=1e18;
	for (int i=1;i<=n;i++){
		if (bt+t-a[i]+1<mx) mx=bt+t-a[i]+1,ans=i;
		bt=max(bt+t,a[i]+t);
		if (bt+t>et) {flag=1;break;}
	}
	if (!flag&&bt+t<=et) ans=n+1,a[n+1]=bt+1; 
	printf("%I64d",a[ans]-1);
}