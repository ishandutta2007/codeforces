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
inline int calc(int x)
{
	x=(x&0x55555555)+((x>>1)&0x55555555);
	x=(x&0x33333333)+((x>>2)&0x33333333);
	x=(x&0x0f0f0f0f)+((x>>4)&0x0f0f0f0f);
	x=(x&0x00ff00ff)+((x>>8)&0x00ff00ff);
	x=(x&0x0000ffff)+((x>>16)&0x0000ffff);
	return x;
}
const int M=1010;
int n,m,k,a[M]={},ans=0;
int main()
{	
	cin>>n>>m>>k;
	for(int i=1;i<=m+1;++i)
		cin>>a[i];
	for(int i=1;i<=m;++i)
		ans+=calc(a[i]^a[m+1])<=k;
	cout<<ans<<endl;
	return 0;
}