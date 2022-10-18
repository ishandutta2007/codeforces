#include <bits/stdc++.h>
using namespace std;
int n, cnt[27], idx[27];
char s[100001], tmp[100001], top;
bool cmp(int a, int b) { return cnt[a]>cnt[b]; }
int main()
{
	scanf("%d%s", &n, s);
	for(int i=0; i<n; ++i) ++cnt[s[i]-'a'];
	for(int i=0; i<26; ++i) idx[i]=i;
	sort(idx, idx+26, cmp);
	for(int i=0; i<26&&cnt[idx[i]]; ++i)
	{
		if(cnt[idx[i]]==cnt[idx[i+1]]+1)
		{
			for(int j=1; j<=cnt[idx[i+1]]; ++j) putchar('a'+idx[i]), putchar('a'+idx[i+1]);
			putchar('a'+idx[i]);
			++i;
		}
		else for(int j=1; j<=cnt[idx[i]]; ++j) putchar('a'+idx[i]);
	}
	return 0;
}