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
int main()
{	
	int T;
	cin>>T;
	while(T--)
	{
		long long l,r,ans=0;
		cin>>l>>r;
		++r;
		for(int i=62;i>=0;--i)
			if((l&(1ll<<i))==(r&(1ll<<i)))
				ans+=(l&(1ll<<i));
			else
			{
				ans+=(1ll<<i)-1;
				break;
			}
		//if(ans%2==0 && ans<r)
		//	++ans;
		cout<<ans<<endl;
	}
	return 0;
}