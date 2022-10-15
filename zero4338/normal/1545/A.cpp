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
		vector<int>a,b;
		for(int i=1;i<=n;i++)((i&1)?a:b).push_back(read());
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		bool flag=1;
		for(int i=0;i<b.size();i++)if(b[i]<a[i])flag=0;
		for(int i=1;i<a.size();i++)if(a[i]<b[i-1])flag=0;
		puts(flag?"YES":"NO");
	}
	return 0;
}