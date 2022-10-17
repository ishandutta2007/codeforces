#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;

int n;

char s[N];

int f[N],g[N],h[N],w[N];

int main()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	w[0]=1;
	for(int i=1;i<=n;i++)
	{
		w[i]=w[i-1]*(s[i]=='?'?3ll:1)%P;
		if(s[i]=='a')
		{
			f[i]=(f[i-1]+w[i-1])%P;
			g[i]=g[i-1];
			h[i]=h[i-1];
		}
		if(s[i]=='b')
		{
			f[i]=f[i-1];
			g[i]=(g[i-1]+f[i-1])%P;
			h[i]=h[i-1];
		}
		if(s[i]=='c')
		{
			f[i]=f[i-1];
			g[i]=g[i-1];
			h[i]=(h[i-1]+g[i-1])%P;
		}
		if(s[i]=='?')
		{
			f[i]=(f[i-1]*3ll%P+w[i-1])%P;
			g[i]=(g[i-1]*3ll%P+f[i-1])%P;
			h[i]=(h[i-1]*3ll%P+g[i-1])%P;
		}
	}
	printf("%d\n",h[n]);
}