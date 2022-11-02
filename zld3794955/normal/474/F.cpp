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
const int N=100010,D=20;
int n,t,g[N][D]={},dt[N]={};
pair<int,int> p[N];
inline int gcd(int a,int b)
{
	while(int r=a%b)
	{
		a=b;
		b=r;
	}
	return b;
}
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&g[i][0]);
	for(int d=1,s=2;s<=n;++d,s<<=1)
		for(int i=1;i<=n-s+1;++i)
			g[i][d]=gcd(g[i][d-1],g[i+(1<<(d-1))][d-1]);
	for(int i=1;i<=n;++i)
	{
		if((1<<(dt[i-1]+1))<=i)
			dt[i]=dt[i-1]+1;
		else
			dt[i]=dt[i-1];
	}
	for(int i=1;i<=n;++i)
		p[i]=make_pair(g[i][0],i);
	sort(p+1,p+n+1);
}
inline int seg_gcd(int l,int r)
{
	int d=dt[r-l];
	return gcd(g[l][d],g[r-(1<<d)+1][d]);
}
void work()
{
	scanf("%d",&t);
	for(int i=1,l=0,r=0;i<=t;++i)
	{
		scanf("%d%d",&l,&r);
		int g=seg_gcd(l,r);
		int lp=lower_bound(p+1,p+n+1,make_pair(g,l))-p-1;
		int rp=upper_bound(p+1,p+n+1,make_pair(g,r))-p-1;
		//cout<<"lp="<<lp<<" rp="<<rp<<endl;
		printf("%d\n",r-l+1-rp+lp);
	}
}
int main()
{	
	init();
	work();
	return 0;
}