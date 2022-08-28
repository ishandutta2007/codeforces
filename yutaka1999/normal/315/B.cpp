#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005

using namespace std;

int in[SIZE];
int sum=0;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	for(int i=0;i<m;i++)
	{
		int t=1;
		scanf("%d",&t);
		if(t==1)
		{
			int a,b;
			scanf("%d %d",&a,&b);a--;
			in[a]=b-sum;
		}
		else if(t==2)
		{
			int a;
			scanf("%d",&a);
			sum+=a;
		}
		else
		{
			int a;
			scanf("%d",&a);a--;
			printf("%d\n",in[a]+sum);
		}
	}
	return 0;
}