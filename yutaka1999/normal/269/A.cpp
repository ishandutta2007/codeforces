#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005
#define INF 2000000000

using namespace std;
typedef long long int ll;

int sz[SIZE],num[SIZE];
int log[SIZE];//
ll two[25];
int n;

int ans()
{
	int ret=0;
	two[0]=4;
	for(int i=1;i<25;i++) two[i]=two[i-1]*4;
	for(int i=0;i<n;i++) ret=max(ret,sz[i]+(lower_bound(two,two+25,num[i])-two+1));
	return ret;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d %d",&sz[i],&num[i]);
	printf("%d\n",ans());
	return 0;
}