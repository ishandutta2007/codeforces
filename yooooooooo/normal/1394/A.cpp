#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,d,m,x,sum,ans,tot0,tot1,a[100005],b[100005];
bool cmp(ll a, ll b){return a>b;}
int main()
{
	ans=0;
	scanf("%lld%lld%lld",&n,&d,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		if(x>m)a[++tot0]=x;
		else b[++tot1]=x;
	}
	sort(a+1,a+tot0+1,cmp);
	sort(b+1,b+tot1+1,cmp);
	for(int i=1;i<=tot0;i++)a[i]+=a[i-1];
	for(int i=1;i<=tot1;i++)b[i]+=b[i-1];
	for(int i=0;i<=n;i++)
	{
		sum=b[min(1ll*i,tot1)]+a[min(tot0,(n-i+d)/(d+1))];
		ans=max(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}