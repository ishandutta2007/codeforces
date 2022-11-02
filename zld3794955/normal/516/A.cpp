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
const int D=15;
int n,a[D]={},tot=0;
void init()
{
	cin>>n;
	long long v;
	cin>>v;
	while(v)
	{
		++a[v%10];
		v/=10;
	}
}
void work()
{
	a[7]+=a[8]+a[9];
	a[2]+=a[9]+3*a[8];
	a[3]+=a[9]+a[9];
	a[8]=a[9]=0;
	
	a[5]+=a[6];
	a[3]+=a[6];
	a[6]=0;
	
	a[2]+=a[4]*2;
	a[3]+=a[4];
	a[4]=0;
	for(int i=9;i>=2;--i)
	{
		while(a[i])
		{
			cout<<i;
			--a[i];
		}
	}
	cout<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}