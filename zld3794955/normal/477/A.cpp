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
const long long mod=1000000007;
long long a,b;
int main()
{	
	cin>>a>>b;
	long long ans1=b*(b-1)/2%mod;
	long long ans2=a*(1+b+1+a*b%mod)%mod*500000004%mod;
	cout<<ans1*ans2%mod<<endl;
	return 0;
}