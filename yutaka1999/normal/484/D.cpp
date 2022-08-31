#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#define SIZE 1000005

using namespace std;
typedef long long int ll;

int in[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	ll mn=0,mx=0,ret=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		if(i==0)
		{
			mn=in[i];
			mx=-in[i];
		}
		else
		{
			ll vl=max(mn-in[i-1],mx+in[i-1]);
			ret=max(ret,vl);
			mn=max(mn,vl+in[i]);
			mx=max(mx,vl-in[i]);
		}
	}
	ret=max(ret,max(mn-in[n-1],mx+in[n-1]));
	printf("%I64d\n",ret);
	return 0;
}