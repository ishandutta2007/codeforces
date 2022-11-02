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
const int N=110;
long long a,b,c,v[N]={},r=0;
int tot=0;
bool check(long long x)
{
	long long s=1;
	for(int i=1;i<=a;++i)
		s*=x;
	s*=b;
	s+=c;
	if(s<=0 || s>=1000000000ll)
		return false;
	r=s;
	long long y=0;
	while(s)
	{
		y+=s%10;
		s/=10;
	}
	return y==x;
}
int main()
{	
	cin>>a>>b>>c;
	for(int i=1;i<=100;++i)
		if(check(i))
			v[++tot]=r;
	sort(v+1,v+tot+1);
	cout<<tot<<endl;
	for(int i=1;i<=tot;++i)
		cout<<v[i]<<' ';
	cout<<endl;
	return 0;
}