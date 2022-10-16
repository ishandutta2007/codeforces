#include<cstdio>
#include<map>
#include<algorithm>

using namespace std;

bool fl[400000];long long a[400000];
map<long long,int> cnt;

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		int n=0;long long x=0;scanf("%d%lld",&n,&x);for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)cnt[a[i]]++;int ans=n;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i-1])continue;
			{
				int t=min(cnt[a[i]],cnt[a[i]*x]);
				ans-=2*t;cnt[a[i]*x]-=t;
			}
		}
		printf("%d\n",ans);
		cnt.clear();
	}
}