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
int T;
const int maxn=2e5+5;
int n,q,a[maxn];
bool isnprime[maxn];
void sieve()
{
	static int p[maxn],cnt;
	int n=2e5;
	for(int i=2;i<=n;i++)
	{
		if(!isnprime[i])p[++cnt]=i;
		for(int j=1;j<=cnt&&p[j]*i<=n;j++)
		{
			isnprime[i*p[j]]=true;
			if(i%p[j]==0)break;
		}
	}
}
int main()
{
	sieve();
	T=read();
	while(T--)
	{
		n=read();q=read();
		generate_n(a,n,read);
		vector<int>div;vector<vector<ll>>divsum;
		for(int i=1;i<n;i++)
			if(n%i==0&&!isnprime[n/i])
			{
				div.push_back(i);
				divsum.push_back(vector<ll>(i));
			}
		for(int i=0;i<n;i++)
			for(int j=0;j<div.size();j++)
				divsum[j][i%div[j]]+=(ll)a[i]*div[j];
		multiset<ll>s;
		for(int i=0;i<div.size();i++)
			s.insert(divsum[i].begin(),divsum[i].end());
		printf("%lld\n",*s.rbegin());
		while(q--)
		{
			int p=read()-1,v=read();
			for(int i=0;i<div.size();i++)
			{
				s.erase(s.find(divsum[i][p%div[i]]));
				divsum[i][p%div[i]]+=(ll)(v-a[p])*div[i];
				s.insert(divsum[i][p%div[i]]);
			}
			a[p]=v;
			printf("%lld\n",*s.rbegin());
		}
	}
}