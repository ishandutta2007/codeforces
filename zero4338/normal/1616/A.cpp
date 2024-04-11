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
int n,a[maxn];
int ans;
map<int,bool>exi;
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		ans=0;exi.clear();
		for(int i=1;i<=n;i++)
		{
			if(!exi.count(a[i]))
			{
				exi[a[i]]=1;ans++;
			}
			else if(!exi.count(-a[i]))
			{
				exi[-a[i]]=1;ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}