#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int a[30];
char s[30];

int main()
{
	scanf("%s",s);
	for (int i=0;i<strlen(s);i++)
	{
		a[i]=s[i]-'0';
		if (a[i]>4)
		{
			if (!(i==0&&a[i]==9))
				a[i]=9-a[i];
		}
		printf("%d",a[i]);
	}
	
}