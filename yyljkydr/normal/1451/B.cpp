#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,q;

char s[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s",s+1);
		while(q--)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			int ans=0;
			for(int i=1;i<l;i++)
				ans|=s[i]==s[l];
			for(int i=r+1;i<=n;i++)
				ans|=s[i]==s[r];
			puts(ans?"YES":"NO");
		}
	}
}