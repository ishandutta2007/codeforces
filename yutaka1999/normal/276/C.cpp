#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 200005

using namespace std;
typedef long long int ll;

int imos[SIZE];
int in[SIZE];

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	sort(in,in+n);
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		imos[a]++;
		imos[b+1]--;
	}
	for(int i=1;i<n;i++) imos[i]+=imos[i-1];
	sort(imos,imos+n);
	ll ret=0;
	for(int i=0;i<n;i++) ret+=(ll) imos[i]*(ll) in[i];
	printf("%I64d\n",ret);
	return 0;
}