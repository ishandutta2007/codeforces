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
const int maxn=1e6+5;
int n;
string s;
int sum[3][maxn];
bool check(int l,int r)
{
	if(l==0)return sum[0][r]>sum[1][r]&&sum[0][r]>sum[2][r];
	return sum[0][r]-sum[0][l-1]>sum[1][r]-sum[1][l-1]&&sum[0][r]-sum[0][l-1]>sum[2][r]-sum[2][l-1];
}
int main()
{
	T=read();
	while(T--)
	{
		n=read();cin>>s;
		sum[0][0]=sum[1][0]=sum[2][0]=0;
		for(int i=0;i<s.length();i++)
		{
			if(i)sum[0][i]=sum[0][i-1],sum[1][i]=sum[1][i-1],sum[2][i]=sum[2][i-1];
			sum[s[i]-'a'][i]++;
		}
		int ans=-1;
		for(int i=0;i+1<s.length();i++)if(check(i,i+1))ans=2;
		if(~ans){puts("2");continue;}
		for(int i=0;i+2<s.length();i++)if(check(i,i+2))ans=2;
		if(~ans){puts("3");continue;}
		for(int i=0;i+3<s.length();i++)if(check(i,i+3))ans=2;
		if(~ans){puts("4");continue;}
		for(int i=0;i+6<s.length();i++)if(check(i,i+6))ans=2;
		if(~ans){puts("7");continue;}
		puts("-1");
	}
	return 0;
}//