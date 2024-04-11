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
string s;
int main()
{
	T=read();
	while(T--)
	{
		cin>>s;
		if(s.front()!=s.back())s.back()=s.front();
		cout<<s;printf("\n");
	}
	return 0;
}