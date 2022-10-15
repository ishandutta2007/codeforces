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
char s[maxn],ans[maxn];
int cnt[2];
int main()
{
	T=read();
	while(T--)
	{
		n=read();scanf("%s",s+1);
		cnt[0]=cnt[1]=0;
		for(int i=1;i<=n;i++)cnt[s[i]-'0']++;
		if((cnt[0]&1)||s[1]=='0'||s[n]=='0')puts("NO");
		else
		{
			int tmp0=0,tmp1=0;
			for(int i=1;i<=n;i++)
			{
				if(s[i]=='1')ans[i]=((++tmp0)<=cnt[1]/2)?'(':')';
				else ans[i]=((++tmp1)&1)?'(':')';
			}
			puts("YES");
			for(int i=1;i<=n;i++)putchar(ans[i]);putchar('\n');
			for(int i=1;i<=n;i++)
			{
				if(s[i]=='1')putchar(ans[i]);
				else putchar(ans[i]=='('?')':'(');
			}
			putchar('\n');
		}
	}
	return 0;
}