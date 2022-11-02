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
int n,d,c[100100]={};
int main()
{	
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	sort(c+1,c+n+1);
	long long t=d,sum=0;
	for(int i=1;i<=n;++i)
	{
		sum+=(long long)c[i]*t;
		t=max(t-1,1ll);
	}
	cout<<sum<<endl;
	return 0;
}