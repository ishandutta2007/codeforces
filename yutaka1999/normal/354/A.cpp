#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005
#define INF 1000000000000LL

using namespace std;
typedef long long int ll;

ll in[SIZE];
ll sum(int a,int b)
{
	if(a>b) return 0;
	if(a==0) return in[b];
	return in[b]-in[a-1];
}

int main()
{
	int n,l,r,a,b;
	scanf("%d %d %d %d %d",&n,&l,&r,&a,&b);
	for(int i=0;i<n;i++)
	{
		scanf("%I64d",&in[i]);
		if(i>0) in[i]+=in[i-1];
	}
	ll ret=INF;
	for(int i=0;i<=n;i++)
	{
		ll L=sum(0,i-1)*(ll) l,R=sum(i,n-1)*(ll) r;
		int dl=i,dr=n-i;
		if(dl<dr) ret=min(ret,L+R+(ll) max(dr-dl-1,0)*b);
		else ret=min(ret,L+R+(ll) max(dl-dr-1,0)*a);
	}
	printf("%I64d\n",ret);
	return 0;
}