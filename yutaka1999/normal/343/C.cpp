#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define SIZE 100005
#define INF 10000000000000

using namespace std;
typedef long long int ll;

ll pos[SIZE];//
ll go[SIZE];//~
int n,m;

bool ok(ll x)
{
	ll now=0;
	for(int i=0;i<n;i++)
	{
		ll zan=llabs(pos[i]-go[now]);
		if(zan>x) continue;
		ll one=upper_bound(go,go+m,x-zan+go[now])-go;
		ll sec=upper_bound(go,go+m,(x-zan)/2+pos[i])-go;
		now=max(one,sec);
	}
	return now>=m;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%I64d",&pos[i]);
	for(int i=0;i<m;i++) scanf("%I64d",&go[i]);
	go[m]=INF;
	ll s=-1,e=INF;
	while(e-s>1)
	{
		ll med=(s+e)/2;
		if(ok(med)) e=med;
		else s=med;
	}
	printf("%I64d\n",e);
	return 0;
}