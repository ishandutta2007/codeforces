#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <deque>
#include <cmath>
#include <string>
#include <cassert>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char str[10];
int n;

bool ask(int a,int b,int c,int d)
{
	assert(c-a+d-b>=n-1);
	printf("? %d %d %d %d\n",a+1,b+1,c+1,d+1);
	fflush(stdout);
	scanf("%s",&str);
	return str[0]=='Y';
}
int main()
{
	scanf("%d",&n);
	string A="",B="";
	int x=n-1,y=n-1;
	for(int i=0;i<n-1;i++)
	{
		if(ask(0,0,x-1,y))
		{
			x--;
			B+="D";
		}
		else
		{
			y--;
			B+="R";
		}
	}
	x=0,y=0;
	for(int i=0;i<n-1;i++)
	{
		if(ask(x,y+1,n-1,n-1))
		{
			y++;
			A+="R";
		}
		else
		{
			x++;
			A+="D";
		}
	}
	reverse(B.begin(),B.end());
	printf("! %s%s\n",A.c_str(),B.c_str());
	fflush(stdout);
	return 0;
}