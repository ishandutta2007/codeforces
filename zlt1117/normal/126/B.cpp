#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=1e6+5;
char s[maxn];
int fail[maxn];
int main()
{
	scanf("%s",s);
	fail[0]=-1;
	int len=strlen(s);
	for(int i=1;i<len;++i)
	{
		int j=fail[i-1];
		while(j>=0&&s[i]!=s[j+1])j=fail[j];
		if(s[i]==s[j+1])j++;
		fail[i]=j;
	}
	int k=fail[len-1];
	if(k==-1)
	{
		printf("Just a legend\n");
		return 0;
	}
	else
	{
		while(k>=0)
		{
			for(int i=k+1;i<len-1;++i)
			{
				if(fail[i]==k)
				{
					for(int i=0;i<=k;++i)putchar(s[i]);
					putchar('\n');
					return 0;
				}
			}
			k=fail[k];
		}
	} 
	printf("Just a legend\n");
	return 0;
}