#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005

using namespace std;

int P[SIZE];

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	if(k%2==0)
	{
		int l=n-k/2,r=n-k/2;
		int sz=0;
		P[sz++]=l;
		int fl=0;
		for(int i=0;i<k;i++)
		{
			if(fl==0)
			{
				r++;
				P[sz++]=r;
			}
			else
			{
				l--;
				P[sz++]=l;
			}
			fl=1-fl;
		}
		while(sz<n)
		{
			l--;
			P[sz++]=l;
		}
	}
	else
	{
		int l=(k+1)/2,r=(k+1)/2;
		int sz=0;
		P[sz++]=l;
		int fl=0;
		for(int i=0;i<k;i++)
		{
			if(fl==0)
			{
				r++;
				P[sz++]=r;
			}
			else
			{
				l--;
				P[sz++]=l;
			}
			fl=1-fl;
		}
		while(sz<n)
		{
			r++;
			P[sz++]=r;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",P[i]);
	}puts("");
	return 0;
}