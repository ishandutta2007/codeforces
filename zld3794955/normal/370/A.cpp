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
int r1,c1,r2,c2;
int main()
{	
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	printf("%d ",!!(r1-r2)+!!(c1-c2));
	if( ((r1+c1)&1)^((r2+c2)&1) )
		printf("0 ");
	else
		printf("%d ",2-(abs(r1-r2)==abs(c1-c2)));
	printf("%d\n",max(abs(c1-c2),abs(r1-r2)));
	return 0;
}