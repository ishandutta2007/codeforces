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
const int N=202;
int n;
double p[N]={};
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>p[i];
	sort(p+1,p+n+1);
	double ans=p[n],tmp=1-p[n];
	for(int i=n-1;i>=1;--i)
	{
		if((tmp-ans)*p[i]>0)
		{
			ans=ans+(tmp-ans)*p[i];
			tmp*=(1-p[i]);
		}
		else
			break;
	}
	printf("%.12f\n",ans);
	return 0;
}