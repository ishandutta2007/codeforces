#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n;scanf("%d",&n);
		int p=sqrt(n*2-1);
		if(p<3)printf("0\n");
		else printf("%d\n",(p-1)/2);
	}
	return 0;
}