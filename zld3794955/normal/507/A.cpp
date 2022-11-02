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
const int N=110;
int n,k;
pair<int,int> a[N];
int main()
{	
	cin>>n>>k;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].first;
		a[i].second=i;
	}
	++n;
	a[n]={1<<20,n+1};
	sort(a+1,a+n+1);
	int s=0;
	for(int i=1;i<=n;++i)
	{
		s+=a[i].first;
		if(s>k)
		{
			cout<<i-1<<endl;
			for(int j=1;j<i;++j)
				cout<<a[j].second<<' ';
			cout<<endl;
			return 0;
		}
	}
	return 0;
}