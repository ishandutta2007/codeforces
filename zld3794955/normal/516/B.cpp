#include<bits/stdc++.h>
using namespace std;
const int N=2020,M=2020;
const int x_[4]={0,1,0,-1},y_[4]={1,0,-1,0};
int n,m,d[N][M]={};
char ch[N][M]={};
void init()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s\n",ch[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(ch[i][j]=='.')
				for(int k=0;k<4;++k)
					d[i][j]+=(ch[i+x_[k]][j+y_[k]]=='.');
}
void work()
{
	queue<pair<int,int> > q;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(ch[i][j]=='.')
			{
				if(d[i][j]==0)
				{
					puts("Not unique");
					return;
				}
				if(d[i][j]==1)
					q.push({i,j});
			}
	while(!q.empty())
	{
		auto it=q.front();
		int x1=it.first,y1=it.second, x2=0,y2=0;
		q.pop();
		if(ch[x1][y1]!='.')
			continue;
		for(int k=0;k<4;++k)
			if(ch[x1+x_[k]][y1+y_[k]]=='.')
			{
				x2=x1+x_[k];
				y2=y1+y_[k];
				break;
			}
		if(x1==x2-1)
			ch[x1][y1]='^',ch[x2][y2]='v';
		if(x1==x2+1)
			ch[x1][y1]='v',ch[x2][y2]='^';
		if(y1==y2+1)
			ch[x1][y1]='>',ch[x2][y2]='<';
		if(y1==y2-1)
			ch[x1][y1]='<',ch[x2][y2]='>';
		for(int k=0;k<4;++k)
		{
			int x3=x2+x_[k],y3=y2+y_[k];
			if(ch[x3][y3]=='.')
			{
				--d[x3][y3];
				if(d[x3][y3]==1)
					q.push({x3,y3});
				if(d[x3][y3]==0)
				{
					puts("Not unique");
					return;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(ch[i][j]=='.')
			{
				puts("Not unique");
				return;
			}
	for(int i=1;i<=n;++i)
		printf("%s\n",ch[i]+1);
}
int main()
{	
	init();
	work();
	return 0;
}