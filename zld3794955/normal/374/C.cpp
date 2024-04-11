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
const int x_[5]={0,0,1,0,-1};
const int y_[5]={0,1,0,-1,0};
char ch[1010][1010]={};
int n,m,t[1010][1010]={},ans=0;
bool v[1010][1010]={},b[1010][1010]={};
void init()
{
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=n;++i)
		gets(ch[i]+1);
}
inline char next(char c)
{
	if(c=='D')	return 'I';
	if(c=='I')  return 'M';
	if(c=='M')  return 'A';
	if(c=='A')  return 'D';
}
int find(int x,int y,char c)
{
	if(b[x][y])
	{
		ans=0x7fffffff;
		return 0;
	}
	if(v[x][y])
		return t[x][y]+(c=='A');
	b[x][y]=true;
	v[x][y]=true;
	for(int i=1;i<=4;++i)
		if(ch[x+x_[i]][y+y_[i]]==next(c))
		{	
			t[x][y]=max(find(x+x_[i],y+y_[i],next(c)),t[x][y]);
			ans=max(t[x][y],ans);
		}
	b[x][y]=false;
	return t[x][y]+(c=='A');
}
void work()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(ch[i][j]=='D')
			{
				find(i,j,'D');
				if(ans==0x7fffffff)
				{
					puts("Poor Inna!");
					return;
				}
			}
	if(ans==0)
		puts("Poor Dima!");
	else
		printf("%d\n",ans);
}
int main()
{	
	init();
	work();
	return 0;
}