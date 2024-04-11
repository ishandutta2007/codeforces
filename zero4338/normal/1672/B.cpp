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
int sum;
int main()
{
	T=read();
	while(T--)
	{
		cin>>s;
		bool flag=1;sum=0;
		if(s.back()=='A')flag=0;
		for(char &c:s)
		{
			if(c=='A')sum++;
			else sum--;
			if(sum<0)flag=0;
		}
		puts(flag?"YES":"NO");
	}
	return 0;
}