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
long long l,r;
long long gcd(long long a,long long b)
{
	return b ? gcd(b,a%b) : a;
}
int main()
{	
	cin>>l>>r;
	for(long long i=l;i<=r;++i)
		for(long long j=i+1;j<=r;++j)
			for(long long k=j+1;k<=r;++k)
				if(gcd(i,j)==1 && gcd(j,k)==1 && gcd(i,k)!=1)
				{
					cout<<i<<' '<<j<<' '<<k<<endl;
					return 0;
				}
	cout<<-1<<endl;
	return 0;
}