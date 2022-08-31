#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <functional>
#define SIZE 100005

using namespace std;
typedef long long int ll;

int in[SIZE],bk[SIZE];
int n,m,a;
ll cost;

bool ok(int x)
{
	ll sum=0,sum2=0;
	for(int l=0,r=x-1;l<x&&r>=0;l++,r--)
	{
		sum+=max(bk[r]-in[l],0);
		sum2+=min(bk[r],in[l]);
	}
	if(sum<=(ll) a)
	{
		cost=max(0LL,sum2+sum-a);
		return true;
	}
	return false;
}
int main()
{
	scanf("%d %d %d",&n,&m,&a);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	for(int i=0;i<m;i++) scanf("%d",&bk[i]);
	sort(in,in+n,greater <int>());
	sort(bk,bk+m);
	int s=-1,e=min(n,m)+1;
	while(e-s>1)
	{
		int med=(s+e)/2;
		if(ok(med)) s=med;
		else e=med;
	}
	printf("%d %I64d\n",s,cost);
	return 0;
}