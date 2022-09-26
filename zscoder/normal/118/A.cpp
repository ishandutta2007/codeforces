#include <iostream>
#include <cstdio>
#include<cstring>
using namespace std;

int main()
{
	char a[105];
	int i,length;
	scanf("%s",&a);
	length=strlen(a);
	for(i=0;i<length;i++)
	{
		if(a[i]=='a'||a[i]=='A'||a[i]=='o'||a[i]=='O'||a[i]=='y'||a[i]=='Y'||a[i]=='e'||a[i]=='E'||a[i]=='u'||a[i]=='U'||a[i]=='i'||a[i]=='I')
		{
			continue;
		}
		else
		{
			if(a[i]>='A'&&a[i]<='Z')
			{
				a[i]=a[i]+32;
			}
			printf(".%c",a[i]);
		}
	}
	printf("\n");
	return 0;
}