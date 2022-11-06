#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
priority_queue<int>Q;
int a,b=0,c=0,n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		Q.push(-a);
		c+=a;
	}
	n=(n*9+1)/2;
	while(c<n)
	{
		c+=5+Q.top();
		b++;
		Q.pop();
	}
	printf("%d",b);
}