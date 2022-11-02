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
int n,k,a[N]={},l[N*N]={},r[N*N]={},tot=0;
long long ans=0;
int calc()
{
	int t=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			t+=(a[i]>a[j]);
	return t;
}
void tryy(int t)
{
	if(t>k)
	{
		ans+=calc();
		return;
	}
	for(int i=1;i<=tot;++i)
	{
		reverse(a+l[i],a+r[i]+1);
		tryy(t+1);
		reverse(a+l[i],a+r[i]+1);
	}
}
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			++tot,l[tot]=i,r[tot]=j;
	tryy(1);
	double a=ans;
	for(int i=1;i<=k;++i)
		a/=tot;
	printf("%.15f\n",a);
	return 0;
}