#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,x;scanf("%d%d",&n,&x);
		for(int i=2;i<n;i++)scanf("%*d");
		scanf("%d",&n);
		puts(x<n?"YES":"NO");
	}
	return 0;
}