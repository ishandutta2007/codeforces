#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;

struct UF
{
	int par[SIZE*2],rank[SIZE*2];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x)
	{
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y])
		{
			par[x]=y;
		}
		else
		{
			par[y]=x;
			if(rank[x]==rank[y]) rank[x]++;
		}
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};
UF uf;
int id[SIZE*2];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	uf.init(2*n+2);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		uf.unite(a,b+n);
		uf.unite(a+n,b);
	}
	for(int i=0;i<n;i++)
	{
		if(uf.same(i,i+n))
		{
			puts("-1");
			return 0;
		}
	}
	memset(id,-1,sizeof(id));
	vector <int> A,B;
	for(int i=0;i<n;i++)
	{
		int p=uf.find(i);
		if(id[p]==-1)
		{
			int q=uf.find(i+n);
			id[p]=0;
			id[q]=1;
		}
		if(id[p]==0) A.push_back(i);
		else B.push_back(i);
	}
	printf("%d\n",A.size());
	for(int i=0;i<A.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",A[i]+1);
	}puts("");
	printf("%d\n",B.size());
	for(int i=0;i<B.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",B[i]+1);
	}puts("");
	return 0;
}