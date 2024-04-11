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
const int N=200020;
int n,a[N]={};
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	int d1=*max_element(a+1,a+n+1),d2=*min_element(a+1,a+n+1);
	if(d1==d2)
		cout<<0<<' '<<(long long)n*(n-1)/2<<endl;
	else
	{
		long long ans=(long long)count(a+1,a+n+1,d1)*count(a+1,a+n+1,d2);
		cout<<d1-d2<<' '<<ans<<endl;
	}
	return 0;
}