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
long long n,a;
int main()
{	
	cin>>n;
	a=n%3*2%3;
	if(a==0)
		a=3;
	long long l=0,r=n;
	while(l!=r)
	{
		long long mid=(l+r+1)>>1;
		long long h=mid*3+a;
		long long k=(n-h-h)/3;
		if(h>=0x7fffffffll || h*(h-1)/2>k)
			r=mid-1;
		else
			l=mid;
	}
	long long h=l*3+a;
	long long k=(n-h-h)/3;
	if(h>=0x7fffffffll || h*(h-1)/2>k)
		--l;
	cout<<l+1<<endl;
	return 0;
}