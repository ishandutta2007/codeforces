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
int n,m,s[2020][2020]={},sx,sy,ex,ey,total=0;
char ch[2020][2020]={};
void init()
{
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s\n",ch[i]+1);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(ch[i][j]=='w');
	total=s[n][m];
}
inline int get_s(int lx,int ly,int rx,int ry)
{
	return s[rx][ry]-s[rx][ly-1]-s[lx-1][ry]+s[lx-1][ly-1];
}
bool check(int mid)
{
	for(int i=mid;i<=n;++i)
		for(int j=mid;j<=m;++j)
			if(get_s(i-mid+1,j-mid+1,i,j)-get_s(i-mid+2,j-mid+2,i-1,j-1)==total)
			{
				sx=i-mid+1 , sy=j-mid+1;
				ex=i , ey=j;
				return true;
			}
	return false;
}
int get_len()
{
	int lx=0,rx=0,ly=0,ry=0;
	for(int i=1;i<=n && !lx;++i)
		for(int j=1;j<=m && !lx;++j)
			if(ch[i][j]=='w')
				lx=i;
	for(int i=n;i>=1 && !rx;--i)
		for(int j=1;j<=m && !rx;++j)
			if(ch[i][j]=='w')
				rx=i;
	for(int j=1;j<=m && !ly;++j)
		for(int i=1;i<=n && !ly;++i)
			if(ch[i][j]=='w')
				ly=j;
	for(int j=m;j>=1 && !ry;--j)
		for(int i=1;i<=n && !ry;++i)
			if(ch[i][j]=='w')
				ry=j;
	return max(rx-lx,ry-ly)+1;
}
void work()
{
	if(total==1)
	{
		for(int i=1;i<=n;++i)
			puts(ch[i]+1);
		return;
	}
	if(!check(get_len()))
		puts("-1");
	else
	{
		for(int i=sx;i<=ex;++i)
		{
			if(ch[i][sy]=='.')
				ch[i][sy]='+';
			if(ch[i][ey]=='.')
				ch[i][ey]='+';
		}
		for(int j=sy;j<=ey;++j)
		{
			if(ch[sx][j]=='.')
				ch[sx][j]='+';
			if(ch[ex][j]=='.')
				ch[ex][j]='+';
		}
		for(int i=1;i<=n;++i)
			puts(ch[i]+1);
	}
}
int main()
{	
	init();
	work();
	return 0;
}