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
const int N=110,K=1010;
int n,k,a[N]={},x[K]={},y[K]={},tot=0;
int main()
{	
	cin>>n>>k;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<=k;++i)
	{
		int pos1=max_element(a+1,a+n+1)-a;
		int pos2=min_element(a+1,a+n+1)-a;
		if(a[pos1]!=a[pos2])
		{
			++tot;
			x[tot]=pos1;
			y[tot]=pos2;
			--a[pos1];
			++a[pos2];
		}
		else
			break;
	}
	printf("%d %d\n",*max_element(a+1,a+n+1)-*min_element(a+1,a+n+1),tot);
	for(int i=1;i<=tot;++i)
		printf("%d %d\n",x[i],y[i]);
	return 0;
}