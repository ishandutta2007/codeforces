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
		int p=s.length()-1;
		for(int i=1;i<s.length();i++)if(s[i]==s[i-1]&&s[i]=='1'){p=i;break;}
		bool flag=1;
		for(int i=p+1;i<s.length();i++)if(s[i]==s[i-1]&&s[i]=='0')flag=0;
		puts(flag?"YES":"NO");
	}
	return 0;
}