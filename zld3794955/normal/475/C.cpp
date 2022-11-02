#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=1010,M=1010,Inf=1<<30;
int n,m,s[N][M]={},sx=0,sy=0,totX=0;
char ch[N][M]={};
void init()
{
	scanf("%d %d\n",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s\n",ch[i]+1);
	for(int i=1;i<=n+2;++i)
		for(int j=1;j<=m+2;++j)
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(ch[i][j]!='X');
	totX=n*m-s[n][m];
}
bool check(int sx,int sy,int ex,int ey)
{
	return s[ex][ey]+s[sx-1][sy-1]==s[sx-1][ey]+s[ex][sy-1];
}
bool check(int x,int y)
{
	//cout<<"x="<<x<<" y="<<y<<endl;
	int lx=sx,ly=sy,rx=sx+x-1,ry=sy+y-1,s=x*y;
	if(!check(lx,ly,rx,ry))
		return false;
	bool down=check(lx+1,ly,rx+1,ry),right=check(lx,ly+1,rx,ry+1);
	while(down^right)
	{
		//cout<<"lx="<<lx<<" ly="<<ly<<" rx="<<rx<<" ry="<<ry<<endl;
		if(down)
		{
			s+=y;
			++lx,++rx;
		}
		else
		{
			s+=x;
			++ly,++ry;
		}
		down=check(lx+1,ly,rx+1,ry);
		right=check(lx,ly+1,rx,ry+1);
	}
	return s==totX;
}
void work()
{
	for(int i=n;i>=1;--i)
		for(int j=m;j>=1;--j)
			if(ch[i][j]=='X')
				sx=i,sy=j;
	int ans=Inf,x=1,y=1;
	while(ch[sx+x][sy]=='X')
		++x;
	for(int my=1;ch[sx][sy+my-1]=='X';++my)
		if(check(x,my))
		{
			ans=min(ans,x*my);
			break;
		}
	while(ch[sx][sy+y]=='X')
		++y;
	for(int mx=1;ch[sx+mx-1][sy]=='X';++mx)
		if(check(mx,y))
		{
			ans=min(ans,mx*y);
			break;
		}
	if(ans==Inf)
		puts("-1");
	else
		printf("%d\n",ans); 
}
int main()
{	
	init();
	work(); 
	return 0;
}