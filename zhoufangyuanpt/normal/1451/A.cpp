#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		if(n==1)puts("0");
		else if(n==2)puts("1");
		else if(n==3)puts("2");
		else if(n%2==0)puts("2");
		else puts("3");
	}
	return 0;
}