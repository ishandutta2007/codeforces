#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005

using namespace std;
typedef long long int ll;

int st[SIZE];
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	st[0]=1;
	for(int i=0;i<n;i++)
	{
		int c,t;
		scanf("%d %d",&c,&t);
		st[i+1]=st[i]+c*t;
	}
	for(int i=0;i<m;i++)
	{
		int v;
		scanf("%d",&v);
		int a=upper_bound(st,st+n,v)-st-1;
		printf("%d\n",a+1);
	}
	return 0;
}