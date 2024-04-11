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
const int N=5050,K=5050;
long long n,m,k,f[2][N]={},s[N]={};
int main()
{	
	cin>>n>>m>>k;
	for(int i=1,x=0;i<=n;++i)
	{
		cin>>x;
		s[i]=s[i-1]+x;
	}
	for(int d=1;d<=k;++d)
	{
		int now=d&1,pre=now^1;
		for(int i=0;i<=n;++i)
			f[now][i]=0;
		for(int i=m;i<=n;++i)
			f[now][i]=max(f[pre][i-m]+s[i]-s[i-m] , f[now][i-1]);
	}
	cout<<f[k&1][n]<<endl;
	return 0;
}