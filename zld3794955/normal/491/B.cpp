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
const int C=100010,H=100010,Inf=0x7fffffff;
int n,m,c,h,l1=Inf,r1=-Inf,l2=Inf,r2=-Inf;
int main()
{	
	cin>>n>>m>>c;
	for(int i=1,x=0,y=0;i<=c;++i)
	{
		cin>>x>>y;
		l1=min(l1,x+y);
		r1=max(r1,x+y);
		l2=min(l2,y-x);
		r2=max(r2,y-x);
	}
	cin>>h;
	long long ans=Inf*10ll;
	int pos=0;
	for(int i=1,x=0,y=0;i<=h;++i)
	{
		cin>>x>>y;
		long long tmp=max(max(x+y-l1,r1-x-y),max(y-x-l2,r2-y+x));
		if(tmp<ans)
			ans=tmp,pos=i;
	}
	cout<<ans<<endl<<pos<<endl;
	return 0;
}