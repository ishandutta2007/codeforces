#include<stdio.h>
using namespace std;
int a1,a2,a3,b1,b2,b3,n,s;
int main()
{
	scanf("%d%d%d",&a1,&a2,&a3);
	scanf("%d%d%d",&b1,&b2,&b3);
	scanf("%d",&n);
	s=s+a1+a2+a3;
	if (s)
	s=(s-1)/5+1;
	n-=s;
	s=0;
	s=s+b1+b2+b3;
	if (s)
	s=(s-1)/10+1;
	n=n-s;
	if (n<0)
	printf("NO");
	else
	printf("YES");
}