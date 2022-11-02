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
const int N=100010;
int a[N]={},n,m;
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	scanf("%d",&m);
	for(int i=1,x=0;i<=m;++i)
	{
		scanf("%d",&x);
		printf("%d\n",lower_bound(a+1,a+n+1,x)-a);
	}
	return 0;
}