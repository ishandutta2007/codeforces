#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,a[N],s[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
	if(n>=29*2+1)
	{
		puts("1");
		return 0;
	}
	int ans=1e9;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			for(int k=j+1;k<=n;k++)
			{
				int x=s[j]^s[i-1];
				int y=s[k]^s[j];
				if(x>y)
					ans=min(ans,k-i+1-2);
			}
	printf("%d\n",ans==1e9?-1:ans);
}