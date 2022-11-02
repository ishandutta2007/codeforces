#include<bits/stdc++.h>
#define maxn 500050
using namespace std;

int n,m;
char s[maxn],t[maxn];

int nxt[maxn];
int cnt[2];

int main()	{
	scanf("%s%s",s,t);
	n=strlen(s),m=strlen(t);
	if (n<m)
		return puts(s),0;
	
	int i=0,j=-1;
	nxt[i]=j;
	while (i<m)	{
		if (!~j||t[i]==t[j])
			nxt[++i]=++j;
		else
			j=nxt[j];
	}
	
//	for (int i=0;i<=m;++i)	cout<<nxt[i]<<" "; cout<<endl;
	for (int i=0;i<n;++i)	++cnt[s[i]-'0'];
	for (int i=0;i<m;++i)	{
		char c=cnt[t[i]-'0']?t[i]:t[i]^1;
		putchar(c),--cnt[c-'0'];
	}
	
	for (int i=nxt[m],l=m;l<n;++i,++l)	{
		if (i==m)
			i=nxt[m];
		char c=cnt[t[i]-'0']?t[i]:t[i]^1;
		putchar(c),--cnt[c-'0'];
	}
	return 0;
}