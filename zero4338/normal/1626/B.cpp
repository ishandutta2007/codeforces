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
const int maxn=2e5+5;
int n;
char s[maxn];
int a[maxn];
int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s+1);n=strlen(s+1);
		for(int i=1;i<=n;i++)a[i]=s[i]-'0';
		int pos=0;
		for(int i=n-1;i>=1;i--)
			if(a[i]+a[i+1]>=10){pos=i;break;}
		if(pos)
		{
			for(int i=1;i<pos;i++)printf("%d",a[i]);
			printf("%d",a[pos]+a[pos+1]);
			for(int i=pos+2;i<=n;i++)printf("%d",a[i]);putchar('\n');
		}
		else
		{
			printf("%d",a[1]+a[2]);
			for(int i=3;i<=n;i++)printf("%d",a[i]);putchar('\n');
		}
	}
	return 0;
}