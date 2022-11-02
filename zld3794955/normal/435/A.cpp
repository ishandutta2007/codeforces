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
int n,m,s=0,ans=0;
int main()
{	
	scanf("%d%d",&n,&m);
	for(int i=1,x=0;i<=n;++i)
	{
		scanf("%d",&x);
		s+=x;
		if(s>m)
			s=x,++ans;
	}
	printf("%d\n",ans+1);
	return 0;
}