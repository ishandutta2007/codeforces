#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

char s[N];

int cnt[101]; 

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=0;i<26;i++)
			cnt[i]=-1;
		for(int i=1;i<=n;i++)
			if(s[i]!=s[i+1])
				cnt[s[i]-'a']=1;
			else
				i++;
		int ans=0;
		for(int i=0;i<26;i++)
			if(cnt[i]==1)
				printf("%c",i+'a');
		puts("");
	}
}