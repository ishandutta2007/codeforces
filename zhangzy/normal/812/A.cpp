#include<cstdio>
using namespace std;
int a[5],p[5],die[5];
int main()
{
	for (int i=1;i<=4;i++)
	{
		scanf("%d%d%d%d",&a[1],&a[2],&a[3],&p[i]);
		if (a[1]) die[i]=die[(i+2)%4+1]=1;
		if (a[2]) die[i]=die[(i+1)%4+1]=1;
		if (a[3]) die[i]=die[(i)%4+1]=1;
	}
	for (int i=1;i<=4;i++)
		if (die[i]&&p[i])
		{
			printf("YES");
			return 0;
		}
	printf("NO");
}