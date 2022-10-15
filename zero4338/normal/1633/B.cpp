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
		string s;cin>>s;
		int num0=count(s.begin(),s.end(),'0'),num1=s.size()-num0;
		if(num0!=num1)printf("%d\n",min(num0,num1));
		else printf("%d\n",num0-1);
	}
	return 0;
}