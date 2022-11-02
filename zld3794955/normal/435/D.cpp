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
const int x_[8]={0,-1,0,1,1,1,-1,-1},N=410;
const int y_[8]={1,0,-1,0,1,-1,-1,1},M=410;
int n,m,f[8][N][M]={},s[8][N][M]={};
char ch[N][M]={};
void init()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%s\n",ch[i]+1);
}
inline void add(int k,int i,int j)
{
	s[k][i][j]=s[k][i-x_[k]][j-y_[k]]+(ch[i][j]=='1');
}
void pre()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			add(0,i,j),add(3,i,j),add(4,i,j);
	for(int i=n;i>=1;--i)
		for(int j=m;j>=1;--j)
			add(1,i,j),add(2,i,j),add(7,i,j);
	for(int i=1;i<=n;++i)
		for(int j=m;j>=1;--j)
			add(5,i,j);
	for(int i=n;i>=1;--i)
		for(int j=1;j<=m;++j)
			add(6,i,j);
}
long long calc(int x,int y,int d1,int d2,int d3)
{
	if(ch[x][y]=='1')
		return 0;
	//cout<<"x="<<x<<" y="<<y<<" d1="<<d1<<" d2="<<d2<<" d3="<<d3<<endl;
	long long sum=0;
	int x1=x,y1=y,x2=x,y2=y;
	while(ch[x1+=x_[d1]][y1+=y_[d1]]=='0' && ch[x2+=x_[d2]][y2+=y_[d2]]=='0')
	{
		//cout<<"x1="<<x1<<" y1="<<y1<<" x2="<<x2<<" y2="<<y2<<endl;
		sum+=(s[d3][x1][y1]-s[d3][x2-x_[d3]][y2-y_[d3]]==0);
	}
	//cout<<"sum="<<sum<<endl<<endl;
	return sum;
}
void work()
{
	long long ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			ans+=calc(i,j,0,1,4);
			ans+=calc(i,j,1,2,7);
			ans+=calc(i,j,2,3,6);
			ans+=calc(i,j,3,0,5);
			ans+=calc(i,j,4,5,0);
			ans+=calc(i,j,5,6,3);
			ans+=calc(i,j,6,7,2);
			ans+=calc(i,j,7,4,1);
		}
	cout<<ans<<endl;
}
int main()
{	
	init();
	pre();
	work();
	return 0;
}