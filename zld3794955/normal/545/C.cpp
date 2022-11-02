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
const int N=100010;
int n,x[N]={},h[N]={},ans=0;
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>x[i]>>h[i];
	x[n+1]=0x7fffffff;
	int l=-(1<<30);
	for(int i=1;i<=n;++i)
		if(x[i]-h[i]>l)
			++ans,l=x[i];
		else
			if(x[i]+h[i]<x[i+1])
				++ans,l=x[i]+h[i];
			else
				l=x[i];
	cout<<ans<<endl;
	return 0;
}