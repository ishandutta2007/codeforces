#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),k=read();
		string s;cin>>s;
		bool flag=1;
		for(int i=0;i<n;i++)if(s[i]!=s[n-i-1])flag=0;
		if(!k||flag)puts("1");
		else puts("2");
	}
	return 0;
}