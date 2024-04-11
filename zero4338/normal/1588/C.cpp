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
const int maxn=3e5+5;
int n,a[maxn];
ll ans;
struct Data
{
	map<ll,int>val;ll delta;bool turned;
	void clear(){val.clear();delta=0;turned=0;}
	void insert(int x)
	{
		if(!turned)val[x-delta]++;
		else val[-x-delta]++;
	}
	void add(int x)
	{
		if(!turned)delta+=x;
		else delta-=x;
	}
	void turn(){turned^=1;}
	void remove()
	{
		if(!turned)
		{
			while(!val.empty()&&(*val.begin()).first+delta<0)val.erase(val.begin());
		}
		else
		{
			while(!val.empty()&&-(*(--val.end())).first-delta<0)val.erase(--val.end());	
		}
	}
	int ctz()
	{
		return val[-delta];
	}
}q;
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		q.clear();
		ans=0;
		for(int i=1;i<=n;i++)
		{
			q.turn();
			q.add(a[i]);q.insert(a[i]);
			q.remove();ans+=q.ctz();
		}
		printf("%lld\n",ans);
	}
	return 0;
}