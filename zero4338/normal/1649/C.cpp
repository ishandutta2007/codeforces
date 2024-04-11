#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int n,m;
map<int,vector<int>>a,b;
ll ans;
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int c=read();
			a[c].push_back(i);
			b[c].push_back(j);
		}
	}
	for(auto &i:a)
	{
		sort(i.second.begin(),i.second.end());
		ll sum=0;
		for(int j=0;j<i.second.size();j++)
		{
			ans+=(ll)j*i.second[j]-sum;
			sum+=i.second[j];
		}
	}
	for(auto &i:b)
	{
		sort(i.second.begin(),i.second.end());
		ll sum=0;
		for(int j=0;j<i.second.size();j++)
		{
			ans+=(ll)j*i.second[j]-sum;
			sum+=i.second[j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}