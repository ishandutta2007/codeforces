#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<fstream>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
#include<stdexcept>
#include<iomanip>
#include<functional>
using namespace std;
int t,n,p,a[25][25]={},tot=0;
int main()
{	
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&p);
		int tot=n+n+p;
		for(int i=1;i<=n && tot;++i)
			for(int j=i+1;j<=n && tot;++j)
			{	
				printf("%d %d\n",i,j);
				--tot;
			}
	}
	return 0;
}