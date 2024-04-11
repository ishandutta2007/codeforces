#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,a[N];

int chk(int l,int r)
{
	for(int i=l;i<=r;i++)
		for(int j=i+1;j<=r;j++)
			for(int k=j+1;k<=r;k++)
				if((a[i]<=a[j]&&a[j]<=a[k])||(a[i]>=a[j]&&a[j]>=a[k]))
					return 0;
	return 1;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
		scanf("%d",&n);
        for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i;j<=min(i+4,n);j++)
			{
				if(chk(i,j))
					ans++;
			}
		printf("%d\n",ans);
    }
}