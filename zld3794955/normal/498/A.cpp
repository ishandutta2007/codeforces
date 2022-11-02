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
const int N=303;
long long n,sx,sy,ex,ey,a[N]={},b[N]={},c[N]={};
int main()
{	
	cin>>sx>>sy>>ex>>ey>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i]>>b[i]>>c[i];
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		long long t1=a[i]*sx+b[i]*sy+c[i],t2=a[i]*ex+b[i]*ey+c[i];
		ans+=(t1>0 && t2<0) || (t1<0 && t2>0);
	}
	cout<<ans<<endl;
	return 0;
}