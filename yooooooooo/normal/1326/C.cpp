#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll pos[200005],n,k,ans0,x,ans1;
const ll mod=998244353;
int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		pos[x]=i;
	}
	for(int i=n-k+1;i<=n;i++)ans0+=i;
	ans1=1;
	sort(pos+n-k+1,pos+n+1);
	for(int i=n-k+1;i<n;i++)ans1=ans1*(pos[i+1]-pos[i])%mod;
	printf("%lld %lld\n",ans0,ans1);
	return 0;
}