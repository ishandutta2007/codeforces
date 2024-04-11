#include <cstdio>
#include <algorithm>
const int N=100005;
int n, a[N];
inline int ask(int x)
{
	if(a[x]) return a[x];
	int p=x;
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", &x);
	return a[p]=x;
}
int main()
{
	scanf("%d", &n);
	std::fill(a+1, a+n+1, 0);
	a[0]=a[n+1]=0x3f3f3f3f;
	int l=0, r=n+1, mid=(l+r)>>1;
	while(l+3<r)
	{
		int x=(l+mid)>>1, y=(mid+r)>>1;
		if(ask(x)<std::min(ask(l), ask(mid))) r=mid, mid=x;
		else if(ask(y)<std::min(ask(l), ask(mid))) l=mid, mid=y;
		else l=x, r=y;
	}
	for(int i=std::max(1, l); i<=std::min(r, n); ++i)
	{
		if(ask(i-1)>ask(i)&&ask(i)<ask(i+1))
		{
			printf("! %d\n", i);
			fflush(stdout);
			break;
		}
	}
	return 0;
}