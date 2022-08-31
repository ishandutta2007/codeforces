#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 1000005

using namespace std;
typedef long long int ll;

int deg[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		deg[a]++;deg[b]++;
	}
	ll ret=(ll) n*(ll) (n-1)*(ll) (n-2)/6,mn=0;
	for(int i=0;i<n;i++) mn+=(ll) deg[i]*(ll) (n-deg[i]-1);
	printf("%llld\n",ret-mn/2);
	return 0;
}