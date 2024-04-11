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
int n,m,l,r,a[110]={},t1=1,t2=1;
int main()
{	
	cin>>n>>m>>l>>r;
	bool fail=false;
	for(int i=1;i<=m;++i)
	{
		cin>>a[i];
		if(a[i]==l)
			t1=0;
		if(a[i]==r)
			t2=0;
		if(a[i]<l)
			fail=true;
		if(a[i]>r)
			fail=true;
	}
	if(fail || m+t1+t2>n)
		puts("Incorrect");
	else
		puts("Correct");
	return 0;
}