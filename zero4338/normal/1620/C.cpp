#include<bits/stdc++.h>
typedef __int128 ll;
using namespace std;
ll read()
{
	ll ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=2e4+5;
int n,k;ll x;
char s[maxn];
int val[maxn],cnt;
ll suf[maxn];
int num[maxn];
bool over[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();k=read();x=read()-1;
		cnt=0;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			if(s[i]=='*')
			{
				cnt++;val[cnt]=0;
				while(i<=n&&s[i]=='*'){val[cnt]+=k;i++;}
				val[cnt]++;
			}
		suf[cnt+1]=1;
		for(int i=1;i<=cnt+1;i++)over[i]=0;
		for(int i=cnt;i>=1;i--)
		{
			if(over[i+1]||suf[i+1]*val[i]>x)over[i]=1;
			else suf[i]=suf[i+1]*val[i];
		}
		for(int i=1;i<=cnt;i++)
		{
			if(over[i+1])
			{
				num[i]=0;
				continue;
			}
			num[i]=x/suf[i+1];
			x-=num[i]*suf[i+1];
		}
		int now=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='*'&&s[i-1]!='*')
			{
				now++;
				for(int j=1;j<=num[now];j++)putchar('b');
			}
			if(s[i]=='a')putchar('a');
		}
		putchar('\n');
	}
	return 0;
}