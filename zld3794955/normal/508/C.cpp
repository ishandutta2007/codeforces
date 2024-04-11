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
const int M=330;
int m,t,r,a[M]={},d[M]={};
int main()
{	
	cin>>m>>t>>r;
	if(t<r)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=m;++i)
		cin>>a[i];
	sort(a+1,a+m+1);
	for(int i=1;i<=m;++i)
		d[i]=r;
	int sum=0;
	for(int i=1;i<=m;++i)
	{
		int tmp=d[i];
		for(int j=a[i]-1;j>=a[i]-tmp;--j)
		{
			++sum;
			for(int k=i;k<=m;++k)
				if(a[k]>j && a[k]<=j+t)
					--d[k];
		}
	}
	cout<<sum<<endl;
	return 0;
}