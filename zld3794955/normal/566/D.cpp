#include<bits/stdc++.h>
using namespace std;
const int N=200020;
struct DSU
{
	int root[N],n;
	void init(int size)
	{
		n=size;
		for(int i=0;i<=n;++i)
			root[i]=i;
	}
	int get_root(int r)
	{
		if(r!=root[r])
			root[r]=get_root(root[r]);
		return root[r];
	}
	void merge(int u,int v)
	{
		root[get_root(u)]=get_root(v);
	}
	bool connect(int u,int v)
	{
		return get_root(u)==get_root(v);
	}
}T1,T2;
int n,q;
int main()
{	
	scanf("%d%d",&n,&q);
	T1.init(n);
	T2.init(n+1);
	for(int i=1,type,x,y;i<=q;++i)
	{
		scanf("%d%d%d",&type,&x,&y);
		if(type==1)
			T1.merge(x,y);
		if(type==2)
		{
			for(int j=T2.get_root(x); j<y; j=T2.get_root(j))
			{
				T1.merge(j,y);
				T2.merge(j,j+1);
			}
		}
		if(type==3)
			puts(T1.connect(x,y) ? "YES" : "NO");
	}
	return 0;
}