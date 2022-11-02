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
const int N=5050;
int n,a[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
}
int work(int l,int r,int sv)
{
	if(l>r)
		return 0;
	int s1=r-l+1,s2=0,low=*min_element(a+l,a+r+1);
	int last=l;
	s2+=low-sv;
	for(int i=l;i<=r;++i)
		if(a[i]==low)
		{
			s2+=work(last,i-1,low);
			last=i+1;
		}
	s2+=work(last,r,low);
	return min(s1,s2);
}
int main()
{	
	init();
	cout<<work(1,n,0)<<endl;
	return 0;
}