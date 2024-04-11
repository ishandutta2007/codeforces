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
int cnt[26];
int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s+1);n=strlen(s+1);
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cnt[s[i]-'a']++;
		for(int i=1;i<=n;i++)
		{
			if(cnt[s[i]-'a']==1){printf("%s\n",s+i);break;}
			cnt[s[i]-'a']--;
		}
	}
	return 0;
}