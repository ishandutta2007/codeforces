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
int n;
bool check(int v)
{
	for(int i=2;i*i<=v;++i)
	{
		if(v%i==0)
			return true;
	}
	return false;
}
int main()
{	
	cin>>n;
	for(int i=4;i<=n;++i)
	{
		if(check(i) && check(n-i))
		{
			cout<<i<<' '<<n-i<<endl;
			return 0;
		}
	}
	return 0;
}