#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005

using namespace std;
typedef long long int ll;

ll solve(int n,int k)
{
	if(n<=1||k==0) return 0;
	return solve(n-2,k-1)+2*(n-1)-1;
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	printf("%lld\n",solve(n,k));
	return 0;
}