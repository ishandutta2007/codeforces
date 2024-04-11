#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
int a,b,c,n;
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&n);
	if(n-a-b+c<1||min(a,b)<c)printf("-1");
	else printf("%d",n-a-b+c);
}