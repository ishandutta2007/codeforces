#include<bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int ans=1e9;
		for(int i=1;i<=min(n,100000);i++)
		{
			int ths=(i-1)+(n+i-1)/i-1;
			if(ths<ans)
				ans=ths;
		}
		printf("%d\n",ans);
	}
}