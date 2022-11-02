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
const int N=55;
long long n,m,a[N]={};
int main()
{	
	cin>>n>>m;
	for(int i=1,l=0,r=n+1;i<=n;++i)
	{
		if(m<=(1ll<<(n-i))/2)
			a[++l]=i;
		else
			a[--r]=i,m-=(1ll<<(n-i))/2;
	}
	for(int i=1;i<=n;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}