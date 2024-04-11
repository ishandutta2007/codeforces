#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 2505

using namespace std;
typedef pair <int,int> P;
typedef pair <int,P> PP;

int A[SIZE][SIZE];
PP pos[SIZE*SIZE];

struct UF
{
	int par[SIZE];
	vector <int> nd[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			nd[i].push_back(i);
		}
	}
	int find(int x)
	{
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	bool unite(int x,int y)
	{
		int c=A[x][y];
		x=find(x);
		y=find(y);
		if(x==y) return true;
		if(nd[x].size()<nd[y].size()) swap(x,y);
		for(int i=0;i<nd[x].size();i++)
		{
			for(int j=0;j<nd[y].size();j++)
			{
				int l=nd[x][i],r=nd[y][j];
				if(A[l][r]>c||A[r][l]>c) return false;
			}
		}
		for(int j=0;j<nd[y].size();j++) nd[x].push_back(nd[y][j]);
		par[y]=x;
		return true;
	}
};
UF uf;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&A[i][j]);
			if(i==j&&A[i][j]!=0)
			{
				puts("NOT MAGIC");
				return 0;
			}
			pos[i*n+j]=PP(A[i][j],P(i,j));
		}
	}
	uf.init(n+2);
	sort(pos,pos+n*n);
	for(int i=0;i<n*n;i++)
	{
		P p=pos[i].second;
		int l=p.first,r=p.second;
		if(!uf.unite(l,r))
		{
			puts("NOT MAGIC");
			return 0;
		}
	}
	puts("MAGIC");
	return 0;
}