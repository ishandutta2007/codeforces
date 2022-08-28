#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 1005
#define INF 1000000000

using namespace std;

int in[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	sort(in,in+n);
	int mn=INF,pos=-1,st=-1;
	for(int i=0;i<100000;i++)
	{
		int p1=-INF,p2=-INF;
		for(int j=0;j<n;j++)
		{
			p1=max(p1,in[j]-j*i);
			p2=max(p2,j*i-in[j]);
		}
		int med=(p1+p2+1)/2;
		if(mn>med)
		{
			mn=med;
			pos=i;
			st=p1-med;
		}
	}
	printf("%d\n",mn);
	printf("%d %d\n",st,pos);
	return 0;
}