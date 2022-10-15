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
const int maxn=105;
int n;
char s[maxn];
bool exi[26];
int main()
{
	T=read();
	while(T--)
	{
		scanf("%s",s+1);n=strlen(s+1);
		for(int i=0;i<26;i++)exi[i]=0;
		for(int i=1;i<=n;i++)exi[s[i]-'a']=1;
		for(int i=0;i<26;i++)
		{
			if(exi[i])
			{
				printf("%c ",i+'a');
				bool flag=0;
				for(int j=1;j<=n;j++)
				{
					if(!flag&&s[j]-'a'==i){flag=1;continue;}
					printf("%c",s[j]);
				}
				printf("\n");
				break;
			}
		}
	}
	return 0;
}