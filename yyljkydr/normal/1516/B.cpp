#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int T,n,a[N],s[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s[i]=s[i-1]^a[i];
		if(s[n]==0)
			puts("Yes");
		else
		{
			bool ok=0,hav=0;
			for(int i=1;i<n;i++)
				if(s[i]==0)
					ok|=hav;
				else
					hav|=s[i]==s[n];
			puts(ok?"Yes":"No");
		}
	}
}