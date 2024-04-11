#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

char s[N],t[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",s+1,t+1);
		int n=strlen(s+1),m=strlen(t+1);
		int g=__gcd(n,m);
		int ok=1;
		for(int i=1;i<=n-g;i++)
			ok&=s[i]==s[i+g];
		for(int i=1;i<=m-g;i++)
			ok&=t[i]==t[i+g];
		for(int i=1;i<=g;i++)
			ok&=s[i]==t[i];
		if(!ok)
			puts("-1");
		else
		{
			for(int i=1;i<=n*m/g/g;i++)
				for(int j=1;j<=g;j++)
					putchar(s[j]);
			puts("");
		}
	}
}