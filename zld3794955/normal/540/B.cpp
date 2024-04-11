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
const int N=1010;
int n,k,p,x,y,a[N]={};
int main()
{	
	cin>>n>>k>>p>>x>>y;
	for(int i=1;i<=k;++i)
		cin>>a[i],x-=a[i];
	for(int i=k+1;i<=n;++i)
		a[i]=1,--x;
	if(x<0)
	{
		puts("-1");
		return 0;
	}
	for(int i=k+1;i<=n;++i)
	{
		int d=min(x,y-1);
		x-=d;
		a[i]+=d;
	}
	int s=0;
	for(int i=1;i<=n;++i)
		s+=a[i]>=y;
	if(s>=n/2+1)
	{
		for(int i=k+1;i<=n;++i)
			cout<<a[i]<<' ';
		cout<<endl;
	}
	else
		puts("-1");
	return 0;
}