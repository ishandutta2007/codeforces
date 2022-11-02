#include<cstdio>
#include<cstring>
#include<algorithm> 
#define maxn 1050
using namespace std;

int n,a[maxn];

void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d",&a[i]); 
}

void solve()
{
	sort(a+1,a+n+1);
	
	int ans=0;
	for (int i=2;i<=n;++i)
		ans+=(a[i]-a[i-1]-1);
	printf("%d\n",ans);
}

int main()
{
//	freopen("c.in","r",stdin):
	init();
	solve(); 
	return 0;
}