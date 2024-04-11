#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int compare(const void * x1, const void * x2)  
{
  return ( (int)(*(char*)x1) - (int)(*(char*)x2) ); 
}

int main()
{
	int k;
	scanf("%d",&k);
	char str[1000];
	scanf("%s",str);
	int s=strlen(str);
	qsort(str, s, sizeof(char), compare);
	int d=1;
	for (int i=1;i<=s;i++)
	{
		if ((str[i]!=str[i-1]) && (d%k!=0))
		{
			printf("-1");
			return 0;
		}
		if ((str[i]!=str[i-1]) && (d%k==0)) d=1;
		if (str[i]==str[i-1]) d+=1;
	}
	for (int i=0;i<k;i++)
	{
		for (int j=i;j<s;j+=k)
		{
			printf("%c",str[j]);
		}
	}
}