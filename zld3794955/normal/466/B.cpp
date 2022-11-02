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
long long n,a,b;
int main()
{	
	cin>>n>>a>>b;
	long long mina=0,minb=0,ans=1ll<<60;
	for(long long i=a;i<=a+200000;++i)
	{
		long long nb=max(b,(n*6+i-1)/i);
		if(nb*i<ans)
		{
			ans=nb*i;
			mina=i;
			minb=nb;
		}
	}
	for(long long i=b;i<=b+200000;++i)
	{
		long long na=max(a,(n*6+i-1)/i);
		if(na*i<ans)
		{
			ans=na*i;
			mina=na;
			minb=i;
		}
	}
	cout<<ans<<endl<<mina<<' '<<minb<<endl;
	return 0;
}