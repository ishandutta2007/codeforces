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
const int maxn=2e5+5;
int n,a[maxn],b[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();generate_n(a+1,n,read);generate_n(b+1,n,read);b[n+1]=0;
		int ls=0;map<int,int>need;
		int p=n;bool flag=1;
		for(int i=n;i>=1;i--)
		{
			if(b[i+1]==b[i]){need[b[i]]++;continue;}
			if(a[p]==b[i]){p--;continue;}
			if(need[a[p]]){need[a[p]]--;p--;i++;continue;}
			flag=0;break;
		}
		while(p--)
		{
			if(need[a[p+1]])need[a[p+1]]--;
			else flag=0;
		}
		for(auto &i:need)if(i.second)flag=0;
		puts(flag?"YES":"NO");
	}
	return 0;
}