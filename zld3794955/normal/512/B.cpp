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
const int N=303;
map<int,int> f[N];
int n,l[N]={},c[N]={};
int gcd(int a,int b)
{
	return b ? gcd(b,a%b) : a;
}
void init()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>l[i];
	for(int i=1;i<=n;++i)
		cin>>c[i];
}
void work()
{
	f[0][0]=0;
	for(int i=1;i<=n;++i)
	{
		f[i]=f[i-1];
		for(auto it:f[i-1])
		{
			int tmp=gcd(it.first,l[i]);
			if(!f[i].count(tmp))
				f[i][tmp]=it.second+c[i];
			else
				f[i][tmp]=min(f[i][tmp],it.second+c[i]);
		}
	}
	if(!f[n].count(1))
		puts("-1");
	else
		cout<<f[n][1]<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}