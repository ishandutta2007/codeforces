#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N],m,mx[N];

struct Hero{
	int p,s;
}b[N];

bool operator <(Hero a,Hero b)
{
	return a.p<b.p;
}

bool can(int x,int y)
{
	Hero tmp;
	tmp.p=x;
	return mx[lower_bound(b+1,b+m+1,tmp)-b]>=y;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=m;i++)
			mx[i]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);	
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&b[i].p,&b[i].s);
		sort(b+1,b+m+1);
		for(int i=m;i>=1;i--)
			mx[i]=max(mx[i+1],b[i].s);
		int ne,ans=0;
		bool flag=true;
		for(int i=1;i<=n;i=ne)
		{
			ne=i;
			int w=a[i];
			while(ne<=n&&can(w,ne-i+1))
				ne++,w=max(w,a[ne]);
			if(ne==i)
			{
				flag=false;
				break;
			}
			ans++;
		}
		if(!flag)
			puts("-1");
		else
			printf("%d\n",ans);
	}
}