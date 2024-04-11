#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T;

int n,b[N],vis[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		fill(vis+1,vis+n*2+1,0);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]),vis[b[i]]=1; 
		int R=0,L=n;
		for(int i=1,j=0;i<=2*n;i++)
		{
			if(!vis[i])
				j++;
			else
			{
				if(j)
					j--,R++;
			}
		}
		for(int i=n*2,j=0;i>=1;i--)
		{
			if(!vis[i])
				j++;
			else
			{
				if(j)
					j--,L--;
			}
		}
		printf("%d\n",R-L+1);
	}
}