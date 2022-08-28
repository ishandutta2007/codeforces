#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#define SIZE 1005

using namespace std;
typedef pair <int,int> P;

int left[SIZE][SIZE];
int right[SIZE][SIZE];
int up[SIZE][SIZE];
int down[SIZE][SIZE];
int mp[SIZE][SIZE];
int n,m;

void calcX(int y)
{
	int now=0;
	for(int i=0;i<n;i++)
	{
		if(mp[i][y]==1) now++;
		else now=0;
		up[i][y]=now;
	}
	now=0;
	for(int i=n-1;i>=0;i--)
	{
		if(mp[i][y]==1) now++;
		else now=0;
		down[i][y]=now;
	}
}
void calcY(int x)
{
	int now=0;
	for(int i=0;i<m;i++)
	{
		if(mp[x][i]==1) now++;
		else now=0;
		left[x][i]=now;
	}
	now=0;
	for(int i=m-1;i>=0;i--)
	{
		if(mp[x][i]==1) now++;
		else now=0;
		right[x][i]=now;
	}
}
int Xv(int x,int y)
{
	stack <P> sl,sr;
	int ret=0;
	for(int i=0;i<n;i++)
	{
		int ls=i;
		while(!sl.empty()&&sl.top().first>left[i][y])
		{
			P p=sl.top();sl.pop();
			int pos=p.second;
			ls=pos;
			if(pos<=x&&x<=i-1) ret=max(ret,p.first*(i-pos));
		}
		sl.push(P(left[i][y],ls));
		int rs=i;
		while(!sr.empty()&&sr.top().first>right[i][y])
		{
			P p=sr.top();sr.pop();
			int pos=p.second;
			rs=pos;
			if(pos<=x&&x<=i-1) ret=max(ret,p.first*(i-pos));
		}
		sr.push(P(right[i][y],rs));
	}
	while(!sl.empty())
	{
		P p=sl.top();sl.pop();
		int pos=p.second;
		if(pos<=x) ret=max(ret,p.first*(n-pos));
	}
	while(!sr.empty())
	{
		P p=sr.top();sr.pop();
		int pos=p.second;
		if(pos<=x) ret=max(ret,p.first*(n-pos));
	}
	return ret;
}
int Yv(int x,int y)
{
	stack <P> sl,sr;
	int ret=0;
	for(int i=0;i<m;i++)
	{
		int ls=i;
		while(!sl.empty()&&sl.top().first>down[x][i])
		{
			P p=sl.top();sl.pop();
			int pos=p.second;
			ls=pos;
			if(pos<=y&&y<=i-1) ret=max(ret,p.first*(i-pos));
		}
		sl.push(P(down[x][i],ls));
		int rs=i;
		while(!sr.empty()&&sr.top().first>up[x][i])
		{
			P p=sr.top();sr.pop();
			int pos=p.second;
			rs=pos;
			if(pos<=y&&y<=i-1) ret=max(ret,p.first*(i-pos));
		}
		sr.push(P(up[x][i],rs));
	}
	while(!sl.empty())
	{
		P p=sl.top();sl.pop();
		int pos=p.second;
		if(pos<=y) ret=max(ret,p.first*(m-pos));
	}
	while(!sr.empty())
	{
		P p=sr.top();sr.pop();
		int pos=p.second;
		if(pos<=y) ret=max(ret,p.first*(m-pos));
	}
	return ret;
}
int main()
{
	int q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			scanf("%d",&mp[i][j]);
		}
	}
	for(int i=0;i<n;i++) calcY(i);
	for(int i=0;i<m;i++) calcX(i);/*
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d ",up[i][j]);
		}puts("");
	}*/
	for(int i=0;i<q;i++)
	{
		int t,x,y;
		scanf("%d %d %d",&t,&x,&y);x--;y--;
		if(t==1)
		{
			mp[x][y]^=1;
			calcY(x);
			calcX(y);
		}
		else
		{
			//printf("%d %d\n",Xv(x,y),Yv(x,y));
			printf("%d\n",max(Xv(x,y),Yv(x,y)));
		}
	}
	return 0;
}