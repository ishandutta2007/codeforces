#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define MOD 1000000007
#define SIZE 1000005

using namespace std;
typedef long long int ll;

struct BIT
{
	ll bit[SIZE];
	
	BIT()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k,ll x)
	{
		x%=MOD;
		while(k<SIZE)
		{
			bit[k]+=x;
			if(bit[k]>=MOD) bit[k]-=MOD;
			k+=k&-k;
		}
	}
	ll sum(int k)
	{
		ll ret=0;
		while(k>0)
		{
			ret+=bit[k];
			if(ret>=MOD) ret-=MOD;
			k-=k&-k;
		}
		return ret;
	}
	ll val(int k)
	{
		return sum(k)-sum(k-1);
	}
};
BIT bit;

int main()
{
	int n;
	scanf("%d",&n);
	bit.add(1,1);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		ll pl=bit.sum(a)*a-bit.val(a)+(a==1);
		pl+=MOD;pl%=MOD;
		bit.add(a,pl);
	}
	printf("%I64d\n",bit.sum(SIZE-1)-1);
	return 0;
}