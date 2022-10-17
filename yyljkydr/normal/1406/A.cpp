#include<bits/stdc++.h>
using namespace std;

const int N=1e2+1e1+7;

int T,n,a[N],cnt[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=100;i++)
			cnt[i]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),cnt[a[i]]++;
		int f1=0,f2=0;
		for(int i=0;i<=100;i++)
			if(cnt[i]<2)
			{
				f1=i;
				break;
			}
		for(int i=0;i<=100;i++)
			if(cnt[i]<1)
			{
				f2=i;
				break;
			}
		printf("%d\n",f1+f2);
	}
}