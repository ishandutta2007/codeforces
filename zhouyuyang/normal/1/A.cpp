#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
long long n,m,a;
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&a);
	printf("%I64d",((n-1)/a+1)*((m-1)/a+1));
}