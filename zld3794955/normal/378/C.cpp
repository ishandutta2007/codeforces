#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
int n,m,k,x[300000]={},y[300000]={},head=0,tail=0;
char ch[550][550]={};
bool b[550][550]={};
void init()
{
	scanf("%d %d %d\n",&n,&m,&k);
	for(int i=1;i<=n;++i)
		gets(ch[i]+1);
}
void bfs()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(ch[i][j]=='.')
			{
				x[++tail]=i;
				y[tail]=j;
				b[i][j]=true;
				goto out;
			}
	out:
	const int x_[5]={0,1,0,-1,0};
	const int y_[5]={0,0,1,0,-1};
	while(head!=tail)
	{
		++head;
		for(int i=1;i<=4;++i)
		{
			int _x=x[head]+x_[i],_y=y[head]+y_[i];
			if(ch[_x][_y]=='.' && b[_x][_y]==false)
			{
				++tail;
				//cout<<_x<<' '<<_y<<endl;
				x[tail]=_x;
				y[tail]=_y;
				b[_x][_y]=true;
			}
		}
	}
	for(int i=tail;i>=tail-k+1;--i)
		ch[x[i]][y[i]]='X';
	for(int i=1;i<=n;++i)
		puts(ch[i]+1);
}
int main()
{	
	init();
	bfs();
	return 0;
}