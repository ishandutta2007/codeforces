#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
ll a[100010];
pil ans;
void dfs(ll m,int step,ll s)
{
	if(!m)
	{
		ans=max(ans,pil(step,s));
		return;
	}
	ll x=upper_bound(a+1,a+100002,m)-a-1;
	dfs(m-a[x],step+1,s+a[x]);
	if(x-1>=1)
		dfs(a[x]-1-a[x-1],step+1,s+a[x-1]);
}
int main()
{
	ll m;
	scanf("%I64d",&m);
	int i;
	for(i=1;i<=100001;i++)
		a[i]=ll(i)*i*i;
	dfs(m,0,0);
	printf("%d %I64d\n",ans.first,ans.second);
	return 0;
}