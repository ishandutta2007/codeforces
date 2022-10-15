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
int n,z;
int main()
{
	T=read();
	while(T--)
	{
		n=read(),z=read();
		vector<int>a(n);
		generate(a.begin(),a.end(),read);
		int ret=0;
		for(int &i:a)ret=max(ret,i|z);
		printf("%d\n",ret);
	}
	return 0;
}