#include<stdio.h>
int p,cnt=4,a[500002],n,l,r;
main()
{
	while((a[++n]=getchar())!=EOF);n--;
	l=1;r=n;p=1;
	while(p&&l<n)p=(a[l++]!='[');p=1;
	while(p&&l<n)p=(a[l++]!=':');p=1;
	while(p&&r>0)p=(a[r--]!=']');p=1;
	while(p&&r>0)p=(a[r--]!=':');p=1;
	if(l-1>r)printf("-1");
	else
	{
		for(p=l;p<=r;p++)cnt+=(a[p]=='|');
		printf("%d",cnt);
	}
}