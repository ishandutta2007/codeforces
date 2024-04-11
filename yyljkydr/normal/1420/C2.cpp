#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T,n,q;

int a[N];

long long ans;

int val(int x)
{
	// if(x>n||x<1)
	// 	return 0;
	return max(a[x]-a[x+1],0);
}

void ins(int x)
{
	ans+=val(x);
}

void del(int x)
{
	ans-=val(x);
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[n+1]=0;
		ans=0;
		for(int i=1;i<=n;i++)
			ins(i);
		printf("%lld\n",ans);
		while(q--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			if(l!=r)
			{
				if(r==l+1)
					del(l-1),del(l),del(r);
				else
					del(l-1),del(l),del(r-1),del(r);
			}
			swap(a[l],a[r]);
			if(l!=r)
			{
				if(r==l+1)
					ins(l-1),ins(l),ins(r);
				else
					ins(l-1),ins(l),ins(r-1),ins(r);
			}
			printf("%lld\n",ans);
		}
	}
}