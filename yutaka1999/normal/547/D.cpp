#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 200005

using namespace std;
typedef pair <int,int> P;
typedef pair <P,int> PP;

set <PP> dx,dy;
set <PP>::iterator it;
int col[SIZE];
int px[SIZE],py[SIZE];

void dfs(int x,int y,int id,int w,int c)
{
	dx.erase(PP(P(x,y),id));
	dy.erase(PP(P(y,x),id));
	col[id]=c;
	if(w==0)
	{
		it=dx.lower_bound(PP(P(x,-1),-1));
		if(it!=dx.end())
		{
			PP p=*it;
			if(p.first.first==x)
			{
				dfs(p.first.first,p.first.second,p.second,w^1,c^1);
			}
		}
	}
	else
	{
		it=dy.lower_bound(PP(P(y,-1),-1));
		if(it!=dx.end())
		{
			PP p=*it;
			if(p.first.first==y)
			{
				dfs(p.first.second,p.first.first,p.second,w^1,c^1);
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		dx.insert(PP(P(x,y),i));
		dy.insert(PP(P(y,x),i));
		px[i]=x;
		py[i]=y;
	}
	memset(col,-1,sizeof(col));
	for(int i=0;i<n;i++)
	{
		if(col[i]==-1)
		{
			dfs(px[i],py[i],i,0,0);
			dfs(px[i],py[i],i,1,0);
		}
	}
	for(int i=0;i<n;i++)
	{
		if(col[i]==0) printf("b");
		else printf("r");
	}puts("");
	return 0;
}