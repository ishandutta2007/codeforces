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
int getint()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	int x=ch-'0';
	while(isdigit(ch=getchar())) x=x*10+ch-'0';
	return x;
}
int getbit()
{
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	return ch-'0';
}
const int N=1010,M=1010;
int n,m,a[N][M]={},c[N][M]={},b[4]={1,2,3,4};
void init()
{
	n=getint(),m=getint();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=getbit();
}
inline bool check_line(int k)
{
	for(int i=1;i<=n;++i)
		if(a[i][k] && c[i][k]!=a[i][k])
			return false;
	return true;
}
bool fill_line()
{
	c[1][1]=b[0],c[1][2]=b[1],c[2][1]=b[2],c[2][2]=b[3];
	for(int i=3;i<=n;++i)
		c[i][1]=c[i-2][1],c[i][2]=c[i-2][2];
	if(!check_line(1) || !check_line(2))
		return false;
	for(int j=3;j<=m;++j)
	{
		for(int i=1;i<=n;++i)
			c[i][j]=c[i][j-2];
		if(!check_line(j))
		{
			int c1=c[1][j-2],c2=c[2][j-2];
			for(int i=1;i<=n;++i)
				c[i][j]=c[i][j]==c1 ? c2 : c1;
			if(!check_line(j))
				return false;	
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			printf("%d",c[i][j]);
		printf("\n");
	}
	return true;	
}
inline bool check_row(int k)
{
	for(int i=1;i<=m;++i)
		if(a[k][i] && c[k][i]!=a[k][i])
			return false;
	return true;
}
bool fill_row()
{
	c[1][1]=b[0],c[1][2]=b[1],c[2][1]=b[2],c[2][2]=b[3];
	for(int i=3;i<=m;++i)
		c[1][i]=c[1][i-2],c[2][i]=c[2][i-2];
	if(!check_row(1) || !check_row(2))
		return false;
	for(int i=3;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			c[i][j]=c[i-2][j];
		if(!check_row(i))
		{
			int c1=c[i-2][1],c2=c[i-2][2];
			for(int j=1;j<=m;++j)
				c[i][j]=c[i][j]==c1 ? c2 : c1;
			if(!check_row(i))
				return false;	
		}
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			printf("%d",c[i][j]);
		printf("\n");
	}
	return true;	
}
void work()
{
	do
	{
		if(fill_line() || fill_row())
			return;
	}
	while(next_permutation(b,b+4));
	printf("0\n");
}
int main()
{	
	init();
	work();
	return 0;
}