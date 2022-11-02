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
int n,k;
int main()
{	
	cin>>n>>k;
	if(k%2)
	{
		int t1=1,t2=n;
		while(k>=2)
		{
			printf("%d %d ",t1,t2);
			++t1;
			--t2;
			k-=2;
		}
		for(int i=t1;i<=t2;++i)
			printf("%d ",i);
		printf("\n");
	}
	else
	{
		int t1=1,t2=n;
		while(k)
		{
			printf("%d %d ",t2,t1);
			++t1;
			--t2;
			k-=2;
		}
		for(int i=t1;i<=t2;++i)
			printf("%d ",i);
		printf("\n");
	}
	return 0;
}