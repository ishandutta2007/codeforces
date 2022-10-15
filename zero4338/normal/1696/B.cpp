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
int n;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		int ans=0;bool used=0;
		for(int i=1;i<=n;i++)
		{
			int v=read();
			if(v==0)used=0;
			else if(!used)used=1,ans++;
		}
		ans=min(ans,2);
		printf("%d\n",ans);
	}
	return 0;
}