#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

char s[N];

long long tot[26],num[26][26];

int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
			num[j][s[i]-'a']+=tot[j];
		tot[s[i]-'a']++;
	}
	long long ans=0;
	for(int i=0;i<26;i++)
		ans=max(ans,tot[i]);
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			ans=max(ans,num[i][j]);
	printf("%lld\n",ans);
}