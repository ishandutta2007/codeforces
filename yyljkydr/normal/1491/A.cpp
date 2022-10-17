#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,q,a[N],cnt[N];

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	while(q--)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int x;
			scanf("%d",&x);
			cnt[a[x]]--;
			a[x]^=1;
			cnt[a[x]]++;
		}
		else
		{
			int k;
			scanf("%d",&k);
			if(cnt[1]>=k)
				printf("%d\n",1);
			else
				printf("%d\n",0);
		}
	}
}