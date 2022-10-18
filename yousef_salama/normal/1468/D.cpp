#include <bits/stdc++.h>

using namespace std;

const int N=2e5+5;

int n,m,a,b;
int arr[N];
int tot;

int ok(int x)
{
	for(int i=x-1;i>=0;i--)
	{
		if(arr[i]+(x-i-1)>tot) return 0;
	}
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d %d",&n,&m,&a,&b);
		for(int i=0;i<m;i++)
			scanf("%d",&arr[i]);
		sort(arr,arr+m);
		int can=min(m,abs(b-a)-1);
		if(a<b) tot=b-1;
		else tot=n-b;
		tot--;
		int st=0,en=can,ans=0;
		while(st<=en)
		{
			int mid=(st+en)>>1;
			if(ok(mid))
			{
				ans=mid; st=mid+1;
			}
			else en=mid-1;
		}
		printf("%d\n",ans);
	}
}