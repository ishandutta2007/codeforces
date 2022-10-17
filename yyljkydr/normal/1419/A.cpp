#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n;

char s[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s+1);
		if(n&1)
		{
			int ans=2;
			for(int i=1;i<=n;i+=2)
				if((s[i]-'0')%2==1)
					ans=1;
			printf("%d\n",ans);
		}
		else
		{
			int ans=1;
			for(int i=2;i<=n;i+=2)
				if((s[i]-'0')%2==0)
					ans=2;
			printf("%d\n",ans);
		}
	}
}