#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,k;

char s[N];

int cnt[2][26];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			cnt[0][s[i]-'a']++;
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			cnt[1][s[i]-'a']++;
		int s1=0,s2=0;
		int ans=1;
		for(int i=0;i<26;i++)
		{
			s1+=cnt[0][i]/k*k;
			s2+=cnt[1][i]/k*k;
			if(cnt[0][i]%k!=cnt[1][i]%k)
				ans=0;
			if(s1<s2)
				ans=0;
		}
		puts(ans?"YES":"NO");
	}
}