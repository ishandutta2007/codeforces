#include<stdio.h>
#include<cstring>
using namespace std;
char c[1005],b[1005];
int a[1005],d[1005];
int i,j,k,l,s,m,n,ll;
int main()
{
	scanf("%s%s",&c,&b);
	l=strlen(c);
	ll=strlen(b);
	int bb=0,bbb=0;
	if (l>ll)
	bb=1;
	for (i=0;i<l;i++)
	a[int(c[i])-96]++;
	for (i=0;i<ll;i++)
	d[int(b[i])-96]++;
	bbb=1;
	for (i=1;i<=26;i++)
	if (d[i]>a[i])
	bbb=0;
	if (bbb==0)
	{
		printf("need tree");
		return 0;
	}
	i=0;j=0;
	while (i<l)
	{
		if (c[i]==b[j])
		j++;
		i++;
		if (j>=ll)
		{
			bbb=0;
			break;
		}
	}
	if (bbb&&bb)
	{
		printf("both");
		return 0;
	}
	if (bbb)
	{
		printf("array");
		return 0;
	}
	if (bb)
	{
		printf("automaton");
		return 0;
	}
}