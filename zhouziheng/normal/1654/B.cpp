#include<cstdio>
#include<cstring>

using namespace std;

char S[400000];

bool vis[26];

int main()
{
	int T=0;scanf("%d",&T);
	while(T--)
	{
		scanf("%s",S);int n=strlen(S);
		int ans=n-1;
		for(int i=n-1;i>=0;i--)
		{
			if(!vis[S[i]-'a']){ans=i;vis[S[i]-'a']=1;}
		}
		puts(S+ans);
		
		for(int i=0;i<26;i++)vis[i]=0;
	}
}