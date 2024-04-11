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
const int maxn=2.5e5+5;
int n,a[maxn];
int Ls[maxn],Lb[maxn],f[maxn];
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		f[1]=0;
		stack<int>sta;
		for(int i=1;i<=n;i++)
		{
			while(!sta.empty()&&a[sta.top()]>=a[i])sta.pop();
			if(sta.empty())Ls[i]=0;
			else Ls[i]=sta.top();
			sta.push(i);
		}
		while(!sta.empty())sta.pop();
		for(int i=1;i<=n;i++)
		{
			while(!sta.empty()&&a[sta.top()]<=a[i])sta.pop();
			if(sta.empty())Lb[i]=0;
			else Lb[i]=sta.top();
			sta.push(i);
		}
		set<int>up,down;
		up.insert(1);down.insert(1);
		f[1]=0;
		for(int i=2;i<=n;i++)
		{
			f[i]=1e9;
			while(!up.empty()&&a[*up.rbegin()]>a[i])up.erase(--up.end());
			auto it=up.upper_bound(Lb[i]);
			if(it!=up.end())f[i]=min(f[i],f[*it]+1);
			while(!down.empty()&&a[*down.rbegin()]<a[i])down.erase(--down.end());
			it=down.upper_bound(Ls[i]);
			if(it!=down.end())f[i]=min(f[i],f[*it]+1);
			up.insert(i);
			down.insert(i);
		}
		printf("%d\n",f[n]);
	}
	return 0;
}