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
int a,b,c,d;
int main()
{	
	cin>>a>>b>>c>>d;
	bool flagline=true,flagrow=true;
	if(a>c)
	{
		swap(a,c);
		flagline=false;
	}
	if(b>d)
	{
		swap(b,d);
		flagrow=false;
	}
	if(a-c && b-d && a-c!=b-d)
		printf("-1\n");
	else
	{
		if(a!=c && b!=d)
		{
			if(flagline^flagrow)
				printf("%d %d %d %d\n",a,b,c,d);
			else
				printf("%d %d %d %d\n",a,d,c,b);
		}
		if(a!=c && b==d)
		{
			int len=a-c;
			printf("%d %d %d %d\n",a,b+len,c,d+len);
		}
		if(a==c && b!=d)
		{
			int len=b-d;
			printf("%d %d %d %d\n",a+len,b,c+len,d);
		}
	}
	return 0;
}