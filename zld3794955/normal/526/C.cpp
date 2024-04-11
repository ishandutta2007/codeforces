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
long long c,h1,h2,w1,w2;
long long gcd(long long a,long long b)
{
	return b ? gcd(b,a%b) : a;
}
int main()
{	
	cin>>c>>h1>>h2>>w1>>w2;
	if(w1<w2) swap(w1,w2),swap(h1,h2);
	long long t=w1*w2,d=c/t-2,ans1=0,ans2=0;
	if(d>0)
	{
		c-=d*t;
		ans1+=d*max(t/w1*h1,t/w2*h2);
	}
	for(long long i=0;w1*i<=c;++i)
		ans2=max(ans2,i*h1+(c-i*w1)/w2*h2);
	cout<<ans1+ans2<<endl;
	return 0;
}