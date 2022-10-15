#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
const int maxn=1e5+5;
int n;
int ans;
char s[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();scanf("%s",s+1);
		ans=n+1;
		for(int i=0;i<26;i++)
		{
			int l=1,r=n;
			int sum=0;
			while(l<=r)
			{
				if(s[l]==s[r]){l++;r--;}
				else if(s[l]-'a'==i)l++,sum++;
				else if(s[r]-'a'==i)r--,sum++;
				else{sum=n+1;break;}
			}
			ans=min(ans,sum);
		}
		printf("%d\n",ans==n+1?-1:ans);
	}
	return 0;
}