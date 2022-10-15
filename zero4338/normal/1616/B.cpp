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
const int maxn=1e5+5;
int n;
char s[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();scanf("%s",s+1);
		if(n>=2&&s[1]==s[2]){putchar(s[1]);putchar(s[1]);putchar('\n');continue;}
		int pos=0;
		for(int i=1;i<=n;i++)
			if(s[i+1]>s[i]){pos=i;break;}
		if(!pos)pos=n;
		for(int i=1;i<=pos;i++)putchar(s[i]);
		for(int i=pos;i>=1;i--)putchar(s[i]);putchar('\n');
	}
	return 0;
}