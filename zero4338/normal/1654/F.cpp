#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int n;
string s;
int main()
{
	n=read();cin>>s;
	vector<int>sa(max(26,1<<n)),x(max(26,1<<n)),y(max(26,1<<n)),cnt(max(26,1<<n));
	int m=26;
	for(int i=0;i<(1<<n);i++)x[i]=s[i]-'a';
	for(int i=0;i<(1<<n);i++)cnt[x[i]]++;
	for(int i=1;i<m;i++)cnt[i]+=cnt[i-1];
	for(int i=0;i<(1<<n);i++)sa[--cnt[x[i]]]=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(1<<n);j++)y[j]=sa[j]^(1<<(i-1));
		for(int j=0;j<m;j++)cnt[j]=0;
		for(int j=0;j<(1<<n);j++)cnt[x[j]]++;
		for(int j=1;j<m;j++)cnt[j]+=cnt[j-1];
		for(int j=(1<<n)-1;j>=0;j--)sa[--cnt[x[y[j]]]]=y[j],y[j]=0;
		swap(x,y);
		x[sa[0]]=0;
		int num=0;
		for(int j=1;j<(1<<n);j++)x[sa[j]]=(y[sa[j]]==y[sa[j-1]]&&y[sa[j]^(1<<(i-1))]==y[sa[j-1]^(1<<(i-1))])?num:++num;
		if(num==(1<<n)-1)break;
		m=num+1;		
	}
	for(int i=0;i<(1<<n);i++)putchar(s[i^sa[0]]);
	return 0;
}