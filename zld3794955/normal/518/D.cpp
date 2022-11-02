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
const int N=2020,T=2020;
int n,t;
double p,f[T][N]={},ans=0;
int main()
{	
	cin>>n>>p>>t;
	f[0][0]=1;
	for(int i=1;i<=t;++i)
	{
		f[i][0]=f[i-1][0]*(1-p);
		for(int j=1;j<=n;++j)
			f[i][j]=p*f[i-1][j-1]+(1-p)*f[i-1][j];
		f[i][n]+=p*f[i-1][n];
	}
	for(int i=1;i<=n;++i)
		ans+=f[t][i]*i;
	printf("%.10f\n",ans);//cout<<ans<<endl;
	return 0;
}