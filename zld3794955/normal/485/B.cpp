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
int n,lx=1<<30,ly=1<<30,rx=-1<<30,ry=-1<<30;
int main()
{	
	cin>>n;
	for(int i=1,x=0,y=0;i<=n;++i)
	{
		cin>>x>>y;
		lx=min(lx,x);
		ly=min(ly,y);
		rx=max(rx,x);
		ry=max(ry,y);
	}
	cout<<(long long)max(rx-lx,ry-ly)*max(rx-lx,ry-ly)<<endl;
	return 0;
}