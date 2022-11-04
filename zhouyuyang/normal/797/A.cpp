#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
int n,k,top,ans[25];
int main(){
	scanf("%d%d",&n,&k);
	for (int i=2;i<=n;i++)
		while (n%i==0&&top!=k-1){
			n/=i; ans[++top]=i;
		}
	if (top!=k-1||n==1){
		printf("-1");
		return 0;
	}
	for (int i=1;i<k;i++)
		printf("%d ",ans[i]);
	printf("%d",n);
}