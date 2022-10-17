#include<bits/stdc++.h>
using namespace std;

int T,n,u,r,d,l;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d",&n,&u,&r,&d,&l);
		int ans=0;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
					for(int t=0;t<2;t++)
					{
						int u0=i+j,r0=j+k,d0=k+t,l0=t+i;
						if(u-(n-2)>u0||r-(n-2)>r0||d-(n-2)>d0||l-(n-2)>l0)
							continue;
						if(u0<=u&&r0<=r&&d0<=d&&l0<=l)
							ans=1;
					}
		puts(ans?"YES":"NO");
	}
}