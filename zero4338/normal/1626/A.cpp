#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=100;
int n;
char s[maxn];
int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s+1);n=strlen(s+1);
		sort(s+1,s+n+1);
		printf("%s\n",s+1);
	}
	return 0;
}