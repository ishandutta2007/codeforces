#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 200005

using namespace std;

char str[SIZE];

int ctoi(char c)
{
	if(c=='R') return 0;
	if(c=='U') return 1;
	if(c=='L') return 2;
	return 3;
}
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",&str);
	int ret=1;
	int t=0,a=-1,b=-1;
	for(int i=0;i<n;i++)
	{
		int c=ctoi(str[i]);
		if(c%2==0)
		{
			if(a!=-1&&a!=c)
			{
				ret++;
				b=-1;
			}
			a=c;
		}
		else
		{
			if(b!=-1&&b!=c)
			{
				ret++;
				a=-1;
			}
			b=c;
		}
	}
	printf("%d\n",ret);
	return 0;
}