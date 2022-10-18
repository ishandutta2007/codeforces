#include <cstdio>
#include <algorithm>
#define N 200005
int T, n, ce;
char s[N], a[N], b[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%s", &n, s+1);
		ce=0;
		a[n+1]=b[n+1]=0;
		for(int i=1; i<=n; ++i) ce+=s[i]=='0';
		if((n&1)||(ce&1)||s[1]=='0') { out:; puts("NO"); continue; }
		int i=1;
		for(int t=(n-ce)/2; t; ++i) if(s[i]=='1') a[i]=b[i]='(', --t;
		for(; i<=n; ++i) if(s[i]=='1') a[i]=b[i]=')';
		for(int i=1, c=0; i<=n; ++i) if(s[i]=='0')
		{
			if(c&1) a[i]='(', b[i]=')';
			else a[i]=')', b[i]='(';
			--c;
		}
		for(int i=1, c=0; i<=n; ++i)
		{
			a[i]=='('?++c:--c;
			if(c<0) goto out;
		}
		puts("YES");
		puts(a+1);
		puts(b+1);
	}
	return 0;
}