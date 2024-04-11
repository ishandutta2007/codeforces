#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

char str[10];
int X;

bool ask(int x,int y)
{
	//return (x%X)>=(y%X);
	
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",&str);
	return str[0]=='x';
}
int main()
{
	while(1)
	{
		scanf("%s",&str);
		if(str[0]=='e') break;
		//scanf("%d",&X);
		int t=1;
		while(1)
		{
			if(ask(t,t*2)) break;
			t*=2;
		}
		int l=t,r=t*2;//boudaries are included
		while(l<r)
		{
			int m=(l+r)/2;
			if(ask(r,m)) r=m;
			else l=m+1;
		}
		printf("! %d\n",l);
		fflush(stdout);
	}
	return 0;
}