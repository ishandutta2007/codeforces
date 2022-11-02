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
const int N=2020;
int n,a[N][N]={};
long long s1[N+N+N+N]={},u[N+N+N+N]={},*s2=&u[N+N];
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
}
void work()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			s1[i+j]+=a[i][j];
			s2[i-j]+=a[i][j];
		}
	int x1=-1,y1=-1,x2=-1,y2=-1;
	long long ans1=-1,ans2=-1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			if((i+j)&1)
			{
				if(s1[i+j]+s2[i-j]-a[i][j]>ans1)
				{
					ans1=s1[i+j]+s2[i-j]-a[i][j];
					x1=i;
					y1=j;
				}
			}
			else
			{
				if(s1[i+j]+s2[i-j]-a[i][j]>ans2)
				{
					ans2=s1[i+j]+s2[i-j]-a[i][j];
					x2=i;
					y2=j;
				}
			}
	cout<<ans1+ans2<<endl;
	cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}