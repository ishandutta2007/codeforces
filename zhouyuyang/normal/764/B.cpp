#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int n,a[200005];
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i+i<=n;i++)
    	if (i%2) swap(a[i],a[n-i+1]);
    for (int i=1;i<n;i++) printf("%d ",a[i]);
    printf("%d",a[n]);
}