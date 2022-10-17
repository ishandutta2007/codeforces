#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

int n,a[N],s,x;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		s=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s+=a[i];
		bool equal=1,eqx=0;
		for(int i=1;i<=n;i++)
			equal&=(a[i]==s/n),eqx|=a[i]==x;
		if(equal)
		{
			if(eqx)
				puts("0");
			else
			{
				puts("2");
			}
		}
		else
		{
			if(eqx)
				puts("1");
			else
			{
				if(s%n==0)
				{
					if(s/n==x)
						puts("1");
					else
						puts("2");
				}
				else
					puts("2");
			}
		}
	}
}