#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n;

char s[N];

vector<int>v[N];

int d[N];

int c[N];

void add(int x,int v)
{
	while(x<=n)
	{
		c[x]+=v;
		x+=x&-x;
	}
}

int query(int x)
{
	int ret=0;
	while(x)
	{
		ret+=c[x];
		x-=x&-x;
	}
	return ret;
}

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		v[s[i]-'a'].push_back(i);
	reverse(s+1,s+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		int p=v[s[i]-'a'][d[s[i]-'a']++];
		ans+=p-query(p);
		add(p,1);
	}
	printf("%lld\n",ans-n);
}