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
const int G=10,P=4,SP=10,Inf=1<<30;
int n;
int x[G][4]={},y[G][4]={},a[4]={},b[4]={};
inline long long sqr(long long x)
{
	return x*x;
}
inline bool check(int k1,int k2,int k3,int k4)
{
	int x_[G]={},y_[G]={};
	x_[1]=x[1][k1];
	y_[1]=y[1][k1];
	x_[2]=x[2][k2];
	y_[2]=y[2][k2];
	x_[3]=x[3][k3];
	y_[3]=y[3][k3];
	x_[4]=x[4][k4];
	y_[4]=y[4][k4];
	for(int i=1;i<=P;++i)
	{
		long long a[SP]={},mindis=1ll<<60;
		for(int j=1;j<=P;++j)
			a[j]=sqr(x_[i]-x_[j])+sqr(y_[i]-y_[j]);
		for(int j=1;j<=P;++j)
			if(a[j])
				mindis=min(mindis,a[j]);
		int t[5]={};
		for(int j=1;j<=P;++j)
		{
			if(a[j]%mindis || a[j]/mindis>2)
				return false;
			++t[a[j]/mindis];
		}
		if(t[0]!=1 || t[1]!=2 || t[2]!=1)
			return false;
	}
	return true;
}
int main()
{	
	scanf("%d",&n);
	while(n--)
	{
		for(int i=1;i<=4;++i)
		{
			scanf("%d%d%d%d",&x[i][0],&y[i][0],&a[i],&b[i]);
			for(int j=1;j<=3;++j)
			{
				x[i][j]=a[i]-y[i][j-1]+b[i];
				y[i][j]=b[i]+x[i][j-1]-a[i];
			}
		}
		int ans=Inf;
		for(int k1=0;k1<=3;++k1)
			for(int k2=0;k2<=3;++k2)
				for(int k3=0;k3<=3;++k3)
					for(int k4=0;k4<=3;++k4)
						if(check(k1,k2,k3,k4))
							ans=min(k1+k2+k3+k4,ans);
		if(ans==Inf)
			puts("-1");
		else
			printf("%d\n",ans);
	}
	return 0;
}