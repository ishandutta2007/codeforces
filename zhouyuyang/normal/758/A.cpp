#include<cstring>
#include<cmath>   
#include<cstdio>  
#include<iostream>  
#include<cstdlib>   
#include<algorithm>
#define ll long long
using namespace std;
int n,ma,ans,a[105];
int main(){
	scanf("%d",&n);
	ma=0;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ma=max(ma,a[i]);
	}
	for (int i=1;i<=n;i++) ans+=ma-a[i];
	printf("%d",ans);
}