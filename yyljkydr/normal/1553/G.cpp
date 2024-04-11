#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7,M=1e6+10;

int n,q,a[N],fa[N];

vector<int>p[N];

set<int>ok[N];

int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<=M;i++)
	{
		if(!p[i].size())
		{
			for(int j=i;j<=M;j+=i)
				p[j].push_back(i);
		}
	}
	for(int i=1;i<=M;i++)
		fa[i]=i;
	for(int i=1;i<=n;i++)
		for(auto x:p[a[i]])
		{
			int fx=find(x),fy=find(a[i]);
			fa[fx]=fy;
		}
	for(int i=1;i<=n;i++)
	{
		set<int>can;
		for(auto x:p[a[i]])
			can.insert(find(x));
		for(auto x:p[a[i]+1])
			can.insert(find(x));
		for(auto x:can)
			for(auto y:can)
				if(x!=y)
					ok[x].insert(y),ok[y].insert(x);
	}
	while(q--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int fx=find(a[x]),fy=find(a[y]);
		if(fx==fy)
			puts("0");
		else if(ok[fx].count(fy))
			puts("1");
		else
			puts("2");
	}
}