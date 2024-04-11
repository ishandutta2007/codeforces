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
const int N=1000010,M=100010;
int n,m,dx,dy,d[N]={},t[N]={};
int main()
{	
	cin>>n>>m>>dx>>dy;
	int x=0,y=0;
	for(int i=1;i<=n;++i)
	{
		(x+=dx)%=n;
		(y+=dy)%=n;
		d[x]=y;
	}
	for(int i=1;i<=m;++i)
	{
		cin>>x>>y;
		++t[(y-d[x]+n)%n];
	}
	cout<<0<<' '<<max_element(t,t+n)-t<<endl;
	return 0;
}