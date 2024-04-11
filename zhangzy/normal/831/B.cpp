#include<cstdio>
#include<iostream>
#include<cstring>
#define xxx 50000
using namespace std;
int n,l,to[2333];
char s[23333],s1[23333],s2[23333];

int main()
{
	scanf("%s",s1);
	scanf("%s",s2);
	for (int i=0;i<26;i++)
		to[s1[i]]=s2[i];
	for (int i=1;i<=233;i++)
		if (!to[i])
			to[i]=i;
	scanf("%s",s);
	l=strlen(s);
	for (int i=0;i<l;i++)
	{
		if (s[i]>='A'&&s[i]<='Z')
			printf("%c",to[s[i]-'A'+'a']-'a'+'A');
		else
			printf("%c",to[s[i]]);
	}
}