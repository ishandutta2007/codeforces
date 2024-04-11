#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e4+5;
int T;
string s,t;
map<char,int>cnt;
int main()
{
	T=read();
	while(T--)
	{
		cin>>s>>t;
		reverse(s.begin(),s.end());
		string tmp;
		cnt.clear();
		for(char &c:t)cnt[c]++;
		for(char &c:s)
		{
			if(cnt[c])
			{
				cnt[c]--;
				tmp.push_back(c);
			}
		}
		reverse(tmp.begin(),tmp.end());
		puts(tmp==t?"YES":"NO");
	}
	return 0;
}