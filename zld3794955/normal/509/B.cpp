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
const int N=110,K=110;
int n,k,a[N]={};
vector<int> v[N];
int main()
{	
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	int t1=*min_element(a+1,a+n+1);
	for(int i=1;i<=n;++i)
	{
		int t=t1+(a[i]>t1);
		a[i]-=t;
		for(int j=1;j<=t;++j)
			v[i].push_back(1);
	}
	for(int t=2;t<=k;++t)
		for(int i=1;i<=n;++i)
			if(a[i])
			{
				v[i].push_back(t);
				--a[i];
			}
	for(int i=1;i<=n;++i)
		if(a[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	for(int i=1;i<=n;++i)
	{
		for(auto j:v[i])
			cout<<j<<' ';
		cout<<endl;
	}
	return 0;
}