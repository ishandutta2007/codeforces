#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <functional>

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	if((n-1)%k==0) printf("%d\n",(n-1)/k*2);
	else if((n-1)%k==1) printf("%d\n",(n-1)/k*2+1);
	else printf("%d\n",(n-1)/k*2+2);
	int ct=k+1;
	int sz=k+2;
	for(int i=0;i<(n-1)%k;i++)
	{
		int L=(n-1)/k+1;
		int now=i+1;
		while(L>1)
		{
			printf("%d %d\n",now,sz);
			now=sz;
			sz++;
			L--;
		}
		printf("%d %d\n",now,ct);
	}
	for(int i=(n-1)%k;i<k;i++)
	{
		int L=(n-1)/k;
		int now=i+1;
		while(L>1)
		{
			printf("%d %d\n",now,sz);
			now=sz;
			sz++;
			L--;
		}
		printf("%d %d\n",now,ct);
	}
	return 0;
}