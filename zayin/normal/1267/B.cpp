#include<bits/stdc++.h>
#define maxn 300050
using namespace std;

int n,m;
char s[maxn],t[maxn];

int cnt[maxn];

int main()	{
	scanf("%s",s+1),n=strlen(s+1);
	for (int i=1,j=1;i<=n;i=j)	{
		while (j<=n&&s[i]==s[j]) ++j;
		t[++m]=s[i];
		cnt[m]=j-i;
	}
	
	bool flag=(m&1);
	for (int i=1;i<=m;++i)
		flag&=t[i]==t[m-i+1];
	for (int i=1;i<=m/2;++i)
		flag&=(cnt[i]+cnt[m-i+1]>=3);
	flag&=cnt[m/2+1]>=2;
	if (flag)
		printf("%d\n",cnt[m/2+1]+1); 
	else
		puts("0"); 
	return 0;
}