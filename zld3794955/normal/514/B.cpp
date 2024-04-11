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
const int N=1010;
int n,x,y;
set<pair<int,int> >s;
inline int gcd(int a,int b)
{
	return b ? gcd(b,a%b) : a;
}
int main()
{	
	cin>>n>>x>>y;
	for(int i=1,tx,ty;i<=n;++i)
	{
		cin>>tx>>ty;
		tx-=x,ty-=y;
		int g=gcd(tx,ty);
//"It is guaranteed that no stormtrooper stands at the same point with the gun."
		tx/=g,ty/=g;
		if(tx<0)
			tx=-tx,ty=-ty;
		s.insert({tx,ty});
	}
	cout<<s.size()<<endl;
	return 0;
}