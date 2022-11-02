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
const int N=100100,mod=1000000007;
int n,a[4]={};
char ch[N]={};
long long power(long long x,int y)
{
	long long t=1;
	for(int i=1;i<=y;++i)
		t=(t*x)%mod;
	return t;
}
int main()
{	
	cin>>n>>(ch+1);
	for(int i=1;i<=n;++i)
	{
		if(ch[i]=='A')
			++a[0];
		if(ch[i]=='C')
			++a[1];
		if(ch[i]=='G')
			++a[2];
		if(ch[i]=='T')
			++a[3];
	}
	int v=*max_element(a,a+4);
	int t=count(a,a+4,v);
	cout<<power(t,n)<<endl;
	return 0;
}