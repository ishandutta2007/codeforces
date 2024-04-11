#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 505
#define EPS 1e-10

using namespace std;
typedef long double ld;

int val[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&val[i]);
	ld ret=0.0;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);a--;b--;
		ld d=(ld) (val[a]+val[b])/(ld) c;
		if(ret+EPS<d)
		{
			ret=d;
		}
	}
	printf("%.10f\n",(double) ret);
	return 0;
}