#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define PI 3.14159265358979

using namespace std;
typedef long double ld;

ld ABS(ld d)
{
	return max(d,-d);
}
int main()
{
	int n,R,v;
	scanf("%d %d %d",&n,&R,&v);
	for(int i=0;i<n;i++)
	{
		int s,t;
		scanf("%d %d",&s,&t);
		int dist=t-s;
		ld l=0.0,r=dist+1e3;
		for(int j=0;j<80;j++)
		{
			ld m=(l+r)/2;
			if(m+2.0*(ld) R*ABS(sin(m/(2.0*(ld) R)))>(ld) dist) r=m;
			else l=m;
		}
		printf("%.10f\n",(double) l/(double) v);
	}
	return 0;
}