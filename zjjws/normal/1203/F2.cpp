#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <queue>
#define LL long long
using namespace std;
const int MAX=1e2+3;
const int MAR=6e4+3;
struct milk
{
	int x,y;
	bool operator <(const milk b)const
	{
		return y<b.y;
	}
};
int f[MAX][MAR];
bool vit[MAX][MAR];
milk a[MAX];
int add[MAX];
int nam;
int ans=0;
priority_queue<milk,vector<milk>,less<milk> >q;
inline int dfs(int x,int y)
{
    if(vit[x][y]==true)return f[x][y];
	vit[x][y]=true;
	if(y==0)return 0;
	//if(add[nam]-add[x-1]<=y){f[x][y]=nam-x+1;return f[x][y];}
	if(x==nam)
	{
		if(a[x].x<=y&&y+a[x].y>=0)f[x][y]=1;
		else f[x][y]=0;
//		printf("f[%d][%d]:%d\n",x,y,f[x][y]);
		return f[x][y];
	}
	if(y>=a[x].x&&y+a[x].y>=0)f[x][y]=max(dfs(x+1,y+a[x].y)+1,dfs(x+1,y));
	else f[x][y]=dfs(x+1,y);
//	printf("f[%d][%d]:%d\n",x,y,f[x][y]);
	return f[x][y];
}
inline bool myru(milk x,milk y){return x.x<y.x;}
inline bool myru_2(milk x,milk y){return x.x+x.y>y.x+y.y;}
LL rin()
{
	LL s=0;
	bool bj=0;
	char c=getchar();
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')bj=1,c=getchar();
	while(c>='0'&&c<='9')s=(s<<1)+(s<<3)+(c^'0'),c=getchar();
	if(bj)return -s;
	return s;
}
int main()
{
	int i,j;
	int n,r;
	n=rin();r=rin();
	for(i=1;i<=n;i++)a[i].x=rin(),a[i].y=rin();
	sort(a+1,a+n+1,myru);
	for(j=1;j<=n&&a[j].x<=r;j++)q.push(a[j]);
	for(;!q.empty()&&q.top().y>=0;)
	{
		if(!q.empty())r+=q.top().y,q.pop(),ans++;
		for(;j<=n&&a[j].x<=r;j++)q.push(a[j]);
	}
	nam=0;
	for(;!q.empty();q.pop())a[++nam]=q.top();
	if(nam>0)
	{
     	sort(a+1,a+nam+1,myru_2);
     	add[0]=0;
		for(i=1;i<=nam;i++)add[i]=add[i-1]-a[i].y;
//		for(i=1;i<=nam;i++)printf("(%d,%d)",a[i].x,a[i].y);printf("\n");
    	ans+=dfs(1,r);
	}
	printf("%d",ans);
	return 0;
}