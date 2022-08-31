#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 300005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

int A[SIZE];
ll rt[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	rt[0]=1;
	for(int i=1;i<SIZE;i++) rt[i]=rt[i-1]*2LL%MOD;
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		//2^0+2^1+...+2^(n-i-2)=2^(n-i-1)-1
		ret-=(ll) A[i]*(ll) ((rt[n-i-1]-1+MOD)%MOD) %MOD;
		if(ret<0) ret+=MOD;
		//2^0+2^1+...+2^(i-1)=2^i-1
		ret+=(ll) A[i]*(ll) ((rt[i]-1+MOD)%MOD) %MOD;
		if(ret>=MOD) ret-=MOD;
	}
	printf("%lld\n",ret);
	return 0;
}