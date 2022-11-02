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
const int N=10100;
int n,k,m=-1,a[N][4]={};
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		a[i][0]=(m+=2);
		a[i][1]=m+1;
		a[i][2]=(m+=2);
		a[i][3]=(m+=2);
	}
	printf("%d\n",m*k);
	for(int i=1;i<=n;++i)
		printf("%d %d %d %d\n",a[i][0]*k,a[i][1]*k,a[i][2]*k,a[i][3]*k);
	return 0;
}