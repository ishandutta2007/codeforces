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
const int maxn=5e5+5;
int n;
char s[maxn],t[30];
int cnt[26],num;
bool exi[26];
bool check(int x)
{
	int tmp=0;
	for(int i=1;i<=num;i++)
	{
		for(int j=1;j<=x;j++)
			if(exi[s[j]-'a'])
			{
				tmp++;
				if(s[tmp]!=s[j])return false;
			}
		exi[t[i]-'a']=0;
	}
	return tmp==n;
}
int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s+1);n=strlen(s+1);
		num=0;
		for(int i=0;i<26;i++)exi[i]=cnt[i]=0;
		for(int i=n;i>=1;i--)if(!exi[s[i]-'a'])t[++num]=s[i],exi[s[i]-'a']=1;
		reverse(t+1,t+num+1);
		for(int i=1;i<=n;i++)cnt[s[i]-'a']++;
		int len=0;
		bool flag=1;
		for(int i=1;i<=num;i++)
		{
			if(cnt[t[i]-'a']%i){flag=0;break;}
			len+=cnt[t[i]-'a']/i;
		}
		if(!flag||!check(len)){puts("-1");continue;}
		for(int i=1;i<=len;i++)putchar(s[i]);putchar(' ');for(int i=1;i<=num;i++)putchar(t[i]);putchar('\n');
	}
	return 0;
}