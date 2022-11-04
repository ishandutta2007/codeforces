#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	printf("%d\n",n/2);
	for (int i=1;i<n/2;i++) printf("2 ");
	if (n%2) printf("3"); else printf("2");
	return 0;
}