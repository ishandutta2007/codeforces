#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,a,b,c;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		int ans=0;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=0;i<=a;i++)
			for(int j=0;j<=b;j++)
			{
				if(i*2+j<=b&&j*2<=c)
					ans=max(ans,i*3+j*3);
			}
		printf("%d\n",ans);
	}	
}