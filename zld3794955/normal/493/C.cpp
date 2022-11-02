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
const int N=200020,M=200020,Inf=0x7fffffff;
int n,m,a[N]={},b[M]={},v[N+M]={};
void init()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;++i)
		cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	merge(a+1,a+n+1,b+1,b+m+1,v+1);
	v[n+m+1]=Inf;
}
void work()
{
	int sa=n*3,sb=m*3;
	for(int i=1;i<=n+m+1;++i)
	{
		int p1=lower_bound(a+1,a+n+1,v[i])-a-1,s1=2*p1+3*(n-p1);
		int p2=lower_bound(b+1,b+m+1,v[i])-b-1,s2=2*p2+3*(m-p2);
		if(s1-s2 > sa-sb || (s1-s2==sa-sb && s1>sa))
		{
			sa=s1;
			sb=s2;
		}
	}
	cout<<sa<<':'<<sb<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}