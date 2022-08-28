#include <cstdio>
#include <algorithm>
#include <vector>
#define SIZE 255

using namespace std;

int A[SIZE];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n=250;
		int mx=0;
		double mn=0.0;
		for(int i=0;i<n;i++)
		{
			int d;
			scanf("%d",&d);
			A[i]=d;
			mn+=(double) d/(double) n;
		}
		double sum=0.0;
		for(int i=0;i<n;i++) sum+=(double) (mn-A[i])*(double) (mn-A[i]);
		//U -> |A\
		sum/=(double) n;
		double prop=sum/(mn*(mn+1.0))*3.0;
		//printf("%f %f : %f\n",(double) mn,(double) sum,(double) prop);
		if(prop>0.5) puts("uniform");
		else puts("poisson");
	}
	return 0;
}