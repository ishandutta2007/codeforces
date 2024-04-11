#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <stack>
#define SIZE 2005

using namespace std;
typedef pair <int,int> P;
typedef pair <P,int> PP;

struct getmin
{
	int que[SIZE];
	int s,e;
	
	void init()
	{
		s=e=0;
	}
	void add(int k)
	{
		while(s<e&&que[e-1]>k) e--;
		que[e++]=k;
	}
	void rem(int k)
	{
		if(s<e&&que[s]==k)
		{
			s++;
		}
	}
	int get()
	{
		return s==e?-1:que[s];
	}
};
getmin U,D;
char mp[SIZE][SIZE];
int up[SIZE][SIZE],down[SIZE][SIZE];
int ans[SIZE];
int n,m,k;

void dfs(int l,int r,vector <PP> query)//[l,r]
{
	if(l>r||query.empty()) return;
	int d=(l+r)/2;
	//printf("%d\n",d);
	for(int i=0;i<m;i++)
	{
		up[d][i]=min(up[d][i],d-l+1);
		down[d][i]=min(down[d][i],r-d);
		//printf("%d %d\n",up[d][i],down[d][i]);
	}
	int now=r-l+1;
	while(now>0)
	{
		bool ok=false;
		U.init();
		D.init();
		for(int j=0;j<m;j++)
		{
			U.add(up[d][j]);
			D.add(down[d][j]);
			if(j-now+1>=0)
			{
				if(U.get()+D.get()>=now)
				{
					ok=true;
					break;
				}
				U.rem(up[d][j-now+1]);
				D.rem(down[d][j-now+1]);
			}
		}
		if(!ok) now--;
		else break;
	}
	for(int i=0;i<query.size();i++)
	{
		PP p=query[i];
		int x=p.first.first,y=p.first.second;
		if(x<=d) up[d][y]=min(up[d][y],d-x);
		else down[d][y]=min(down[d][y],x-d-1);
		if(p.second>0) ans[p.second-1]=max(ans[p.second-1],now);
		while(now>0)
		{
			bool ok=false;
			U.init();
			D.init();
			for(int j=0;j<m;j++)
			{
				U.add(up[d][j]);
				D.add(down[d][j]);
				if(j-now+1>=0)
				{
					if(U.get()+D.get()>=now)
					{
						ok=true;
						break;
					}
					U.rem(up[d][j-now+1]);
					D.rem(down[d][j-now+1]);
				}
			}
			if(!ok) now--;
			else break;
		}
	}
	ans[k-1]=max(ans[k-1],now);
	vector <PP> left,right;
	for(int i=0;i<query.size();i++)
	{
		PP p=query[i];
		int x=p.first.first,y=p.first.second;
		if(x<d) left.push_back(p);
		else if(x>d+1) right.push_back(p);
	}
	dfs(l,d-1,left);
	dfs(d+2,r,right);
}
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%s",&mp[i]);
	for(int i=0;i<m;i++)
	{
		int cnt=0;
		for(int j=0;j<n;j++)
		{
			if(mp[j][i]=='X') cnt=0;
			else cnt++;
			up[j][i]=cnt;
		}
		cnt=0;
		for(int j=n-1;j>=0;j--)
		{
			down[j][i]=cnt;
			if(mp[j][i]=='X') cnt=0;
			else cnt++;
		}
	}
	vector <PP> query;
	for(int i=0;i<k;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		query.push_back(PP(P(a,b),i));
	}
	dfs(0,n-1,query);
	for(int i=k-2;i>=0;i--) ans[i]=max(ans[i],ans[i+1]);
	for(int i=0;i<k;i++) printf("%d\n",ans[i]);
	return 0;
}