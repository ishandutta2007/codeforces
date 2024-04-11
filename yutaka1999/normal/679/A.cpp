#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

char str[20];
int table[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

bool check(int x)
{
	printf("%d\n",x);
	fflush(stdout);
	scanf("%s",&str);
	return str[0]=='y';
}
int main()
{
	int cnt=0;
	for(int i=0;i<15;i++)
	{
		int p=table[i];
		if(check(p))
		{
			cnt++;
			if(p*p<=100)
			{
				if(check(p*p))
				{
					puts("composite");
					return 0;
				}
			}
		}
	}
	if(cnt>=2) puts("composite");
	else puts("prime");
	return 0;
}