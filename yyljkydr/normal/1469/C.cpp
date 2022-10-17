#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n,k,h[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&h[i]);
		int l=h[1],r=h[1];
		for(int i=2;i<=n;i++)
		{
			int nr=min(r+k-1,h[i]+k-1);
			int nl=max(l-k+1,h[i]);
			l=nl,r=nr;	
			if(nl>nr)
				break;
		}
		if(l>r)
			puts("NO");
		else
		{
			if(l<=h[n]&&h[n]<=r)
				puts("YES");
			else
				puts("NO");
		}
	}
}