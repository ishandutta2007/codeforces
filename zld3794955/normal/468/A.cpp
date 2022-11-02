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
int n;
int main()
{	
	cin>>n;
	if(n<=3)
		puts("NO");
	else
	{
		puts("YES");
		int t=0;
		while(n>=8)
		{
			int s=n+n-3;
			printf("%d + %d = %d\n",n,n-3,s);
			printf("%d + %d = %d\n",n-1,n-2,s);
			printf("%d - %d = %d\n",s,s,0);
			++t;
			n-=4;
		}
		if(n==4)
		{
			printf("1 * 2 = 2\n");
			printf("2 * 3 = 6\n");
			printf("6 * 4 = 24\n");
		}
		if(n==5)
		{
			printf("5 - 1 = 4\n");
			printf("4 - 2 = 2\n");
			printf("2 * 3 = 6\n");
			printf("6 * 4 = 24\n");
		}
		if(n==6)
		{
			printf("5 - 1 = 4\n");
			printf("6 - 4 = 2\n");
			printf("2 + 2 = 4\n");
			printf("4 + 4 = 8\n");
			printf("8 * 3 = 24\n");
		}
		if(n==7)
		{
			printf("7 - 1 = 6\n");
			printf("6 - 5 = 1\n");
			printf("2 * 6 = 12\n");
			printf("3 * 4 = 12\n");
			printf("12 + 12 = 24\n");
			printf("24 * 1 = 24\n");
		}
		for(int i=1;i<=t;++i)
			printf("24 + 0 = 24\n");
	}
	return 0;
}