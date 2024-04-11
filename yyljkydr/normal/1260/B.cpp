#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e5+1e3+7;

int n,c[N],s[N];

ll ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&s[i]);
		if((s[i]+c[i])%3)
		{
			puts("NO");
			continue;
		}
		long long ss=(s[i]+c[i])/3;
		if(ss>c[i]||ss>s[i])
		{
			puts("NO");
			continue;
		}
		puts("YES");
	}
}