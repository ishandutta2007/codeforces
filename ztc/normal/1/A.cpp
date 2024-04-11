#include<stdio.h>
#include<iostream>
#include<cstring>
#include<queue>
#define inf 998244353
using namespace std;
long long a,b,c;
int main()
{
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	printf("%I64d",((a-1)/c+1)*((b-1)/c+1));
}