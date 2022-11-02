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
long long n,m,k;
bool check(long long mid)
{
	long long s=0;
	for(int i=1;i<=n;++i)
		s+=min(m,mid/i);
	//cout<<"mid="<<mid<<" s="<<s<<endl;
	return s>=k;
}
long long work()
{
	long long l=1,r=n*m;
	while(l!=r)
	{
		long long mid=(l+r)>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}
	return l;
}
int main()
{	
	cin>>n>>m>>k;
	cout<<work()<<endl;
	return 0;
}