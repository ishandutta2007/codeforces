#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 1000005

using namespace std;

char str[SIZE];

int main()
{
	scanf("%s",&str);
	int ret=0,pl=0,cnt=0;
	int sz=strlen(str);
	for(int i=sz-1;i>=0;i--)
	{
		int d=sz-i-1-cnt;
		if(str[i]=='F')
		{
			pl--;
			if(pl<0) pl=0;
		}
		else
		{
			ret=max(ret,d+pl);
			if(d!=0) pl++;
			cnt++;
		}
	}
	printf("%d\n",ret);
	return 0;
}