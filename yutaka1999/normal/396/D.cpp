#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 1000005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

struct BIT
{
	int bit[SIZE];
	int n;
	
	void add(int k,int x)
	{
		while(k<=n)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int sum(int k)
	{
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
};
BIT bit;
ll fac[SIZE];
ll pl[SIZE];
int in[SIZE];

void make()
{
	fac[0]=1;
	for(int i=1;i<SIZE;i++)
	{
		fac[i]=fac[i-1]*(ll) i;
		fac[i]%=MOD;
	}
}
ll get(int x)//x!*x/2
{
	ll ret=fac[x]*((ll) x*(ll) (x-1)/2%MOD)%MOD;
	if(ret%2==1) ret+=MOD;
	return ret/2;
}
int main()
{
	make();
	int n;
	scanf("%d",&n);
	bit.n=n+2;
	for(int i=1;i<=n;i++) bit.add(i,1);
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		int sum=bit.sum(a)-1;
		ret+=get(n-i-1)*(ll) sum%MOD;
		ret+=fac[n-i-1]*((ll) sum*(ll) (sum-1)/2%MOD)%MOD;
		ret%=MOD;
		bit.add(a,-1);
		in[i]=sum;
		pl[i]=fac[n-i-1]*(ll) sum%MOD;
	}
	pl[n]=1;
	for(int i=n-1;i>=0;i--)
	{
		pl[i]+=pl[i+1];
		pl[i]%=MOD;
		ret+=pl[i+1]*(ll) in[i]%MOD;
		ret%=MOD;
	}
	printf("%I64d\n",ret);
	return 0;
}