#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
	int t=0;scanf("%d",&t);
	while(t--)
	{
		int a1=0,b1=0,a2=0,b2=0;scanf("%d%d%d%d",&a1,&b1,&a2,&b2);
		if(a1>b1)swap(a1,b1);if(a2>b2)swap(a2,b2);
		if(b1==b2&&a1+a2==b1){puts("YES");continue;}
		puts("NO");
	}
}