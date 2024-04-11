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
long long h,n,ans=0;
int main()
{	
	cin>>h>>n;
	--n;
	bool flag=false;
	for(int i=h-1;i>=0;--i)
	{
		if((bool(n&(1ll<<i))) ^ flag)
			ans+=(1ll<<(i+1));
		else
			++ans,flag=!flag;
	}
	cout<<ans<<endl;
	return 0;
}