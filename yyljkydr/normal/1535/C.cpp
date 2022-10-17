#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

long long ans=0;

int T;

char s[N];

int n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int sz=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			if(((s[i]=='1')^(i&1))||s[i]=='?')
				sz++;
			else
			{
				ans+=1ll*sz*(sz+1)/2;
				sz=0;
			}
		}
		ans+=1ll*sz*(sz+1)/2;
		sz=0;
		for(int i=1;i<=n;i++)
		{
			if(((s[i]=='1')==(i&1))||s[i]=='?')
				sz++;
			else
			{
				ans+=1ll*sz*(sz+1)/2;
				sz=0;
			}
		}
		ans+=1ll*sz*(sz+1)/2;
		sz=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='?')
				sz++;
			else
			{
				ans-=1ll*sz*(sz+1)/2;
				sz=0;
			}
		}
		ans-=1ll*sz*(sz+1)/2;
		printf("%lld\n",ans);
	}
}