#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
long long ans;
int n,m,x;
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		ans+=(x-1)/m+1;
	} 
	printf("%I64d",(ans-1)/2+1);
}