#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#define SIZE 100005

using namespace std;

vector <int> vec[SIZE];
bool d1[SIZE],d2[SIZE];

void dfs(int v=0,int p=-1)
{
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
		}
	}
	int cnt=vec[v].size();
	if(p!=-1) cnt--;
	if(cnt==0) d1[v]=d2[v]=true;
	else if(cnt==1)
	{
		int to=vec[v][0];
		if(to==p) to=vec[v][1];
		if(d1[to]) d1[v]=d2[v]=true;
	}
	else if(cnt==2)
	{
		int t1=vec[v][0],t2=vec[v][1];
		if(t1==p) t1=vec[v][2];
		if(t2==p) t2=vec[v][2];
		if(d1[t1]&&d1[t2]) d2[v]=true;
	}
}
bool oneside(int v,int p)
{
	int nxt=-1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p&&!d2[to])
		{
			if(nxt!=-1) return false;
			nxt=to;
		}
	}
	return nxt==-1||oneside(nxt,v);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	memset(d1,false,sizeof(d1));
	memset(d2,false,sizeof(d2));
	dfs();
	int now=0,par=-1;
	int cnt=0;
	bool back=false;
	while(1)
	{
		int l=-1,r=-1;
		int cnt=par==-1?0:1;
		int ok=0;
		for(int i=0;i<vec[now].size();i++)
		{
			int to=vec[now][i];
			if(to!=par)
			{
				if(!d1[to]) ok++;
				else cnt++;
				if(!d2[to])
				{
					if(l==-1) l=to;
					else if(r==-1) r=to;
					else
					{
						puts("No");
						return 0;
					}
				}
			}
		}
		if(back||ok>=2||r!=-1||cnt>=3)
		{
			if((l==-1||oneside(l,now))&&(r==-1||oneside(r,now)))
			{
				puts("Yes");
			}
			else
			{
				puts("No");
			}
			break;
		}
		if(l==-1)
		{
			puts("Yes");
			break;
		}
		back=cnt==2;
		par=now;
		now=l;
	}
	return 0;
}