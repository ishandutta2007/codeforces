#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
int n,m,i;
int main(){
	scanf("%d%d",&n,&m);
	for (;n<=m;i++,n*=3,m*=2);
	printf("%d",i); 
}