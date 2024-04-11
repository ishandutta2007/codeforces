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
const int D=70;
long long a1,b1,S1,a2,b2,S2;
bool check(long long x,long long y)
{
	while(x%2==0)
		x/=2;
	while(x%3==0)
		x/=3;
	while(y%2==0)
		y/=2;
	while(y%3==0)
		y/=3;
	return x==y;
}
void work()
{
	int x1=0,y1=0,x2=0,y2=0,ans=0;
	while(S1%3==0)
		++x1,S1/=3;
	while(S1%2==0)
		++y1,S1/=2;
	while(S2%3==0)
		++x2,S2/=3;
	while(S2%2==0)
		++y2,S2/=2;
	if(x1>x2)
		while(x1!=x2)
		{
			(((a1%3==0) ? a1 : b1)*=2)/=3;
			++y1,--x1,++ans;
		}
	else
		while(x2!=x1)
		{
			(((a2%3==0) ? a2 : b2)*=2)/=3;
			++y2,--x2,++ans;
		}
	if(y1>y2)
		while(y1!=y2)
		{
			((a1%2==0) ? a1 : b1)/=2;
			--y1,++ans;
		}
	else
		while(y2!=y1)
		{
			((a2%2==0) ? a2 : b2)/=2;
			--y2,++ans;
		}
	cout<<ans<<endl;
	cout<<a1<<' '<<b1<<endl<<a2<<' '<<b2<<endl;
}
int main()
{	
	cin>>a1>>b1>>a2>>b2;
	S1=a1*b1;
	S2=a2*b2;
	if(check(S1,S2))
		work();
	else
		puts("-1");
	return 0;
}