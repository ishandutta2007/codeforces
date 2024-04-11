#include<bits/stdc++.h>
#define maxc 26
#define maxn 100050
using namespace std;
typedef long long LL;

int n;
char s[maxn];

int cnt[maxc];

int main()
{
	scanf("%d%s",&n,s);
	for (int i=0;i<n;++i)
		++cnt[s[i]-'a'];
	for (int c=0;c<maxc;++c)
		while (cnt[c]--)
			putchar(c+'a');
	return 0;
}