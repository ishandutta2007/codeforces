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
const int maxn=5e3+5;
int n;
int ans;
char s[maxn];
int lcp[maxn][maxn],f[maxn];
void getlcp()
{
	for(int i=n;i>=1;i--)
		for(int j=n;j>=1;j--)
			lcp[i][j]=s[i]==s[j]?lcp[i+1][j+1]+1:0;
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();scanf("%s",s+1);
		getlcp();ans=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=n-i+1;
			for(int j=1;j<i;j++)
			{
				if(i+lcp[i][j]!=n+1&&s[i+lcp[i][j]]>s[j+lcp[i][j]])
					f[i]=max(f[i],f[j]+n-i+1-lcp[i][j]);
			}
			ans=max(ans,f[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}