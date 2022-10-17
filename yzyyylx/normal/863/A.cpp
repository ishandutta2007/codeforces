#include<bits/stdc++.h>
using namespace std;

char a[15];
int qi=1,zhi,l;

int main()
{
	int i,j;
	scanf("%s",a+1);
	l=strlen(a+1);
	for(i=1;i<=l;i++)
	{
		if(a[i]=='0') continue;
		else break;
	}
	qi=i;
	zhi=l;
	for(i=l;i>=1;i--)
	{
		if(a[i]=='0')
		{
			continue;
		}
		else break;
	}
	zhi=i;
	
	for(i=qi;i<=zhi;i++)
	{
		if(a[i]!=a[zhi+qi-i])
		{
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
}