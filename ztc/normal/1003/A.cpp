#include<stdio.h>
#include<iostream>
#include<deque>
using namespace std;
int n,i,j,a[102],maxx=0;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		a[j]+=1;
		maxx=max(maxx,a[j]);
	}
	printf("%d",maxx);
	return 0;
}