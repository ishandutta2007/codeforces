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
long long n,a[20][20]={};
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		a[i][1]=a[1][i]=1;
	for(int i=2;i<=n;++i)
		for(int j=2;j<=n;++j)
			a[i][j]=a[i-1][j]+a[i][j-1];
	cout<<a[n][n]<<endl;
	return 0;
}