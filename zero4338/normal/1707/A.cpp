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
int n,q,a[maxn];
bool ans[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();q=read();
		generate_n(a+1,n,read);
		int cur=0;
		for(int i=n;i>=1;i--)
		{
			if(cur>=a[i])ans[i]=true;
			else if(cur<q&&cur<a[i])cur++,ans[i]=true;
			else ans[i]=false;
		}
		for(int i=1;i<=n;i++)putchar(ans[i]?'1':'0');putchar('\n');
	}
	return 0;
}