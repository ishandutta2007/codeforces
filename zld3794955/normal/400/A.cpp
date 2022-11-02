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
char ch[20]={};
void init()
{
	scanf("%s\n",ch+1);
}
bool check(int d)
{
	for(int i=1;i<=d;++i)
	{
		bool b=true;
		for(int j=i;j<=12;j+=d)
			if(ch[j]=='O')
			{
				b=false;
				break;
			}
		if(b)
			return true;
	}
	return false;
}
void work()
{
	int ans=0;
	bool b[20]={};
	b[1]=check(1);
	b[2]=check(2);
	b[3]=check(3);
	b[4]=check(4);
	b[6]=check(6);
	b[12]=check(12);
	ans=b[1]+b[2]+b[3]+b[4]+b[6]+b[12];
	printf("%d",ans);
	if(b[12])
		printf(" 1x12");
	if(b[6])
		printf(" 2x6");
	if(b[4])
		printf(" 3x4");
	if(b[3])
		printf(" 4x3");
	if(b[2])
		printf(" 6x2");
	if(b[1])
		printf(" 12x1");
	printf("\n");
}
int main()
{	
	int t;
	scanf("%d\n",&t);
	for(int i=1;i<=t;++i)
	{
		init();
		work();
	}
	return 0;
}