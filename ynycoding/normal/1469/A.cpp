#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1005
int T, n, a, b, cnt;
char s[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", s+1);
		n=strlen(s+1);
		if(n&1) { puts("NO"); continue; }
		a=b=0;
		for(int i=1; i<=n; ++i) a+=s[i]=='(', b+=s[i]==')';
		if(a>n/2||b>n/2) { puts("NO"); continue; }
		cnt=n/2-a;
		for(int i=1, cur=0; i<=n; ++i)
		{
			if(s[i]=='?')
			{
				if(cnt) ++cur, --cnt;
				else --cur;
			}
			if(s[i]=='(') ++cur;
			if(s[i]==')') --cur;
			if(cur<0) { puts("NO"); goto out; }
		}
		puts("YES");
		out:;
	}
	return 0;
}