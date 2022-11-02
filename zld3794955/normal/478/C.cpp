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
long long R,G,B;
bool check(long long mid)
{
	return max(0ll,mid-R)+max(0ll,mid-G)+max(0ll,mid-B)<=mid;	
}
void work()
{
	long long l=0,r=(R+G+B)/3;
	while(l!=r)
	{
		long long mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;
}
int main()
{	
	cin>>R>>G>>B;
	work();
	return 0;
}