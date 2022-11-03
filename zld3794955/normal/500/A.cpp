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
const int N=30300;
int n,x,a[N]={};
int main()
{	
	scanf("%d%d",&n,&x);
	for(int i=1;i<n;++i)
		scanf("%d",&a[i]);
	int pos=1;
	while(pos!=n && pos!=x)
		pos=a[pos]+pos;
	puts(pos==x ? "YES" : "NO");
	return 0;
}