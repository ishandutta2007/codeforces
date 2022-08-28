#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define MOD 1000000007
#define SIZE 1000005

using namespace std;
typedef long long int ll;

ll inv[SIZE];
void make()
{
	inv[1]=1;
	for(int i=2;i<SIZE;i++) inv[i]=MOD-(MOD/i)*inv[MOD%i]%MOD;
}
bool ok(int a,int b,int x)
{
	while(x>0)
	{
		int k=x%10;
		if(k!=a&&k!=b) return false;
		x/=10;
	}
	return true;
}
int main()
{
	make();
	int a,b,n;
	scanf("%d %d %d",&a,&b,&n);
	ll ret=0,now=1;
	for(int i=0;i<=n;i++)
	{
		if(ok(a,b,a*i+b*(n-i)))
		{
			ret+=now;
			if(ret>=MOD) ret-=MOD;
		}
		now*=n-i;now%=MOD;
		now*=inv[i+1];now%=MOD;
	}
	printf("%I64d\n",ret);
	return 0;
}