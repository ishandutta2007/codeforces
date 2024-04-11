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
#include<numeric>
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
const int N=55;
int n,x[N*N*4]={},y[N*N*4]={},tot=0;
char ch[N][N]={};
bool b[N][N]={};
set<pair<int,int> >s;
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>(ch[i]+1);
	for(int i=-n+1;i<=n-1;++i)
		for(int j=-n+1;j<=n-1;++j)
			s.insert({i,j});
	for(int x1=1;x1<=n;++x1)
		for(int y1=1;y1<=n;++y1)
			for(int x2=1;x2<=n;++x2)
				for(int y2=1;y2<=n;++y2)
					if(ch[x1][y1]=='.' && ch[x2][y2]=='o')
						s.erase({x1-x2,y1-y2});
	for(auto p:s)
		++tot,x[tot]=p.first,y[tot]=p.second;
	for(int x1=1;x1<=n;++x1)
		for(int y1=1;y1<=n;++y1)
			for(int i=1;i<=tot;++i)
			{
				int nx=x1+x[i],ny=y1+y[i];
				if(ch[x1][y1]=='o' && nx>=1 && ny>=1 && nx<=n && ny<=n)
				{
					if(ch[nx][ny]=='.')
					{
						puts("NO");
						return 0;
					}
					else
						b[nx][ny]=true;
				}
			}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if(ch[i][j]=='x' && !b[i][j])
			{
				puts("NO");
				return 0;
			}
	puts("YES");
	int p=1;
	for(int i=-n+1;i<=n-1;++i)
	{
		for(int j=-n+1;j<=n-1;++j)
		{
			if(i==0 && j==0)
				putchar('o'),++p;
			else if(x[p]==i && y[p]==j)
				putchar('x'),++p;
			else
				putchar('.');
		}
		putchar('\n');
	}
	return 0;
}