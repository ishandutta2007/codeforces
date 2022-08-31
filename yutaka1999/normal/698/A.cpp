#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int A=0,B=0,C=0;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		int mn=min(A,min(B,C));
		int na=mn+1,nb=mn+1,nc=mn+1;
		if(x>>0&1) nb=min(nb,min(A,C));
		if(x>>1&1) nc=min(nc,min(A,B));
		A=na,B=nb,C=nc;
	}
	printf("%d\n",min(A,min(B,C)));
	return 0;
}