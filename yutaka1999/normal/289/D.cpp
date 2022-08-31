#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define MOD 1000000007

using namespace std;
typedef long long int ll;

ll pow(int x,int y)
{
	ll ret=1;
	for(int i=0;i<y;i++)
	{
		ret*=x;
		ret%=MOD;
	}
	return ret;
}
bool use[10];
bool alr[10];
int go[10];
int n,k;
bool ok(int v)
{
	if(v==0) return true;
	if(alr[v]) return false;
	use[v]=true;
	alr[v]=true;
	return ok(go[v]);
}
ll all(int pos)
{
	if(pos==k)
	{
		memset(use,false,sizeof(use));
		for(int i=1;i<k;i++)
		{
			if(!use[i])
			{
				memset(alr,false,sizeof(alr));
				if(!ok(i)) return 0;
			}
		}return 1;
	}
	ll ret=0;
	for(int i=0;i<k;i++)
	{
		if(i==pos) continue;
		go[pos]=i;
		ret+=all(pos+1);
	}
	return ret;
}

int main()
{
	scanf("%d %d",&n,&k);
	printf("%I64d\n",((k*all(1))%MOD)*pow(n-k,n-k)%MOD);
	return 0;
}