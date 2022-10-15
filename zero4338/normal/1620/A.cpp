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
const int maxn=55;
int n;
char s[maxn];
int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s);n=strlen(s);
		int cnt=0;
		for(int i=0;i<n;i++)if(s[i]=='N')cnt++;
		puts(cnt!=1?"YES":"NO");
	}
	return 0;
}