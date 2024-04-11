#include<stdio.h>
#include<cstring>
using namespace std;
int i,j,k,l,s,m,n;
char c[100005],c1[100005];
int ll,rr,l1;
int main()
{
	scanf("%s",&c);
	l1=strlen(c);
	s=0;
	for (i=0;i<l1;i++)
	{
		if (c[i]=='|')
		{
			ll=s;
			s=0;
		}
		else
		s++;
	}
	rr=s;
	scanf("%s",&c1);
	l=strlen(c1);
	int ans=0;
	bool b=false;
	for (i=0;i<=l;i++)
	if ((ll+i)==(rr+l-i))		
	{
		b=true;
		ans=i;
		break;
	}
	if (!b)
	printf("Impossible");
	else
	{
		for (i=0;i<l1;i++)
		{
			if (c[i]=='|')
			break;
			else
			putchar(c[i]);
		}
		for (j=0;j<ans;j++)
		putchar(c1[j]);
		for (;i<l1;i++)
		putchar(c[i]);
		for (j=ans;j<l;j++)
		putchar(c1[j]);
	}
}