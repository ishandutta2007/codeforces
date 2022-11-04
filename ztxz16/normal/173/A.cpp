#include <stdio.h>
#include <stdlib.h>

int n,i,s,s1,s2,l1,l2,now1,now2;
char a1[1005],a2[1005];
char a,b;

int main()
{
    scanf("%d\n",&n);
    gets(a1+1);
    gets(a2+1);
    for(i=1;a1[i]!=0;i++);
    l1=i-1;
    for(i=1;a2[i]!=0;i++);
    l2=i-1;
    s=l1*l2;
    now1=now2=1;
    for(i=1;i<=s;i++)
    {
		a=a1[now1],b=a2[now2];
		if (a=='R' && b=='S')
			s1++;
		else if (a=='S' && b=='P')
			s1++;
		else if (a=='P' && b=='R')
			s1++;
		else if (a!=b) s2++;
		now1++,now2++;
		if (now1>l1) now1=1;
		if (now2>l2) now2=1;
	}
	s1*=(n/s);
	s2*=(n/s);
	now1=now2=1;
	for(i=(n/s)*s+1;i<=n;i++)
    {
		a=a1[now1],b=a2[now2];
		if (a=='R' && b=='S')
			s1++;
		else if (a=='S' && b=='P')
			s1++;
		else if (a=='P' && b=='R')
			s1++;
		else if (a!=b) s2++;
		now1++,now2++;
		if (now1>l1) now1=1;
		if (now2>l2) now2=1;
	}
	printf("%d %d\n",s2,s1);
    return 0;
}