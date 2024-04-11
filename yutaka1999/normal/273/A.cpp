#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005
#define BT 1024*128*2

using namespace std;
typedef long long int ll;

ll mx[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%llld",&mx[i]);
		if(i>0) mx[i]=max(mx[i],mx[i-1]);
	}
	ll now=0;
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int w,h;
		scanf("%d %d",&w,&h);w--;
		printf("%llld\n",(now=max(now,mx[w])+h)-h);
	}
	return 0;
}