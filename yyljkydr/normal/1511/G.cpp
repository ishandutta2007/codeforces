#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n;

int a[N];

int m,q;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i-1]);
	sort(a,a+n);
	scanf("%d",&q);
	int i,l,r,x,y,ans;
	while(q--)
	{
		scanf("%d%d",&l,&r);
		x=upper_bound(a,a+n,l)-a;
		y=upper_bound(a,a+n,r)-a;
		ans=0;
		for(i=x;i<y;i++)
			ans^=a[i]-l;
		putchar("BA"[bool(ans)]);
	}
}