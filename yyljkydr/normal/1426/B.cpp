#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;

char s[N];

int T,n,m;

int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		int ok=0;
		set<pair<int,int> >s;
		for(int i=1;i<=n;i++)
		{
			int a,b,c,d;
			cin>>a>>b>>c>>d;
			if(b==c)
				ok=1;
		}
		if(m&1)
		{
			puts("NO");
			continue;
		}
		puts(ok?"YES":"NO");
	}
}