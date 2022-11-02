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
int n,m,ans=0;
inline int abs(int x)
{
	return x>=0 ? x : -x;
}
int main()
{	
	cin>>n>>m;
	int x=0,y=0,a=0,b=0;
	cin>>x>>y;
	ans=x+y-1;
	for(int i=2;i<=m;++i)
	{
		cin>>a>>b;
		int d=(a-x)-abs(b-y);
		if(d<0)
		{
			puts("IMPOSSIBLE");
			return 0;
		}
		ans=max(ans,max(b+d/2,y+d/2));
		x=a,y=b;
	}
	ans=max(ans,y+n-x);
	cout<<ans<<endl;
	return 0;
}