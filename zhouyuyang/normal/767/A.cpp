#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring> 
using namespace std; 
int n,x,top,a[100005];
int main(){
	scanf("%d",&n);
	top=n;
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		a[x]=1;
		while (a[top]==1) printf("%d ",top),top--;
		printf("\n");
	}
}