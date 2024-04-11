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
string s;
int cnt;
vector<int>p;
int main()
{
	T=read();
	while(T--)
	{
		n=read();cin>>s;
		cnt=0;
		for(char &i:s)if(i=='1')cnt++;
		p.clear();
		for(int i=0;i<(int)s.length()-cnt;i++)if(s[i]=='1')p.push_back(i+1);
		int to=p.size();
		for(int i=(int)s.length()-1;i>=(int)s.length()-cnt;i--)if(s[i]=='0'&&to)p.push_back(i+1),to--;
		sort(p.begin(),p.end());
		if(p.empty())puts("0");
		else
		{
			puts("1");printf("%lu ",p.size());
			for(int &i:p)printf("%d ",i);putchar('\n');
		}
	}//
	return 0;
}