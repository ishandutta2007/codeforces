#include<iostream>
#include<cstdio>
using namespace std;

int n,k,cnt[200];
char mx=0,mn=127;
string str;

inline char nxt(int u)
{
	for(u++;!cnt[u];u++);
	return u;
}

int main()
{
	int i,j;
	cin>>k>>n>>str;
	for(i=0;i<str.size();i++)
	{
		mx=max(mx,str[i]);
		mn=min(mn,str[i]);
		cnt[str[i]]++;
	}
	if(n<=str.size())
	{
		for(i=n-1;str[i]==mx;i--);
		for(j=i+1;j<=n;j++) str[j]=mn;
		str[i]=nxt(str[i]);
		for(i=0;i<n;i++)
		{
			printf("%c",str[i]);
		}
	}
	if(n>str.size())
	{
		cout<<str;
		for(i=str.size();i<n;i++)
		{
			printf("%c",mn);
		}
		return 0;
	}
}