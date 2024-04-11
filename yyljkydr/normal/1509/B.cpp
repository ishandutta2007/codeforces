#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

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
		int st=0,sm=0;
		bool ok=1;
		for(int i=1;i<=n;i++)		
		{
			st+=s[i]=='T';
			sm+=s[i]=='M';
			ok&=st>=sm;
		}
		st=0,sm=0;
		for(int i=n;i>=1;i--)		
		{
			st+=s[i]=='T';
			sm+=s[i]=='M';
			ok&=st>=sm;
		}
		ok&=st==sm*2;
		puts(ok?"YES":"NO");
	}
}