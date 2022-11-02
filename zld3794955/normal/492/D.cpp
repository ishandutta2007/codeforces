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
int n,x,y;
inline long long calc(long long hp)
{
	long long l=0,r=1ll<<60;
	while(l!=r)
	{
		long long mid=(l+r)>>1;
		if(mid/x + mid/y <hp)
			l=mid+1;
		else
			r=mid;
	}
	return l;
}
int main()
{	
	scanf("%d%d%d",&n,&x,&y);
	swap(x,y);
	for(int i=1,t=0;i<=n;++i)
	{
		scanf("%d",&t);
		long long ans=calc(t);
		if(ans%x==0 && ans%y==0)
			puts("Both");
		else
			if(ans%x==0)
				puts("Vanya");
			else
				puts("Vova");
	}
	return 0;
}