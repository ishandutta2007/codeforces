#include<iostream>
#include<cstdio>
#include<algorithm>
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
using namespace std;
int a,b,m,n,l;
int main()
{	
	scanf("%d%d",&a,&b);
	for(int i=1;i<=6;++i)
	{	
		if(abs(i-a)<abs(i-b))
			++m;
		if(abs(i-a)==abs(i-b))
			++n;
		if(abs(i-a)>abs(i-b))
			++l;
	}
	printf("%d %d %d\n",m,n,l);
	return 0;
}