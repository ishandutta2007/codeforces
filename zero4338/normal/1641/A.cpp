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
int n,x,a[maxn];
int main()
{
	T=read();
	while(T--)
	{
		n=read();x=read();
		generate_n(a+1,n,read);
		sort(a+1,a+n+1);
		map<int,int>cnt;
		for(int i=1;i<=n;i++)
		{
			if(a[i]%x==0&&cnt.count(a[i]/x))
			{
				cnt[a[i]/x]--;
				if(!cnt[a[i]/x])cnt.erase(a[i]/x);
			}
			else cnt[a[i]]++;
		}
		int ans=0;
		for(auto &i:cnt)ans+=i.second;
		printf("%d\n",ans);
	}
	return 0;
}