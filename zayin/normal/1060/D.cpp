#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int n;
int a[maxn],b[maxn];

void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%d%d",&a[i],&b[i]);
}

void solve()
{
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	
	LL ans=n;
	for (int i=1;i<=n;++i)
		ans+=max(a[i],b[i]);
	cout<<ans<<endl;
}

int main()
{
	init();
	solve();
	return 0;
}