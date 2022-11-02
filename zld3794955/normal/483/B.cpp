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
long long c1,c2,x,y;
bool check(long long mid)
{
	long long t1=mid - mid/x - mid/y + mid/(x*y);
	long long t2=mid/x - mid/(x*y) , t3=mid/y - mid/(x*y);
	return max(c1-t3,0ll)+max(c2-t2,0ll)<=t1;
}
int main()
{	
	cin>>c1>>c2>>x>>y;
	long long l=c1+c2,r=1ll<<32;
	while(l!=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	cout<<l<<endl;
	return 0;
}