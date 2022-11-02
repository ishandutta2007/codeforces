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
const int N=3030;
int n,a[N]={},k=0,x[N]={},y[N]={};
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
	{
		int pos=min_element(a+i,a+n+1)-a;
		if(a[pos]!=a[i])
		{
			swap(a[pos],a[i]);
			++k;
			x[k]=pos;
			y[k]=i;
		}
	}
	cout<<k<<endl;
	for(int i=1;i<=k;++i)
		cout<<x[i]-1<<' '<<y[i]-1<<endl;
	return 0;
}