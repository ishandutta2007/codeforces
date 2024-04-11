#include<cstdio>
#include<cstring>

using namespace std;

char S[200],T[200];
int cnt[26];

int main()
{
	int TT=0;scanf("%d",&TT);
	while(TT--)
	{
		scanf("%s%s",S+1,T+1);int n=strlen(S+1);for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cnt[S[i]-'a']++;
		if(T[1]=='a'&&T[2]=='b'&&T[3]=='c'&&cnt[0]>0)
		{
			for(int i=0;i<cnt[0];i++)putchar('a');
			for(int i=0;i<cnt[2];i++)putchar('c');
			for(int i=0;i<cnt[1];i++)putchar('b');
		}
		else
		{
			for(int i=0;i<cnt[0];i++)putchar('a');
			for(int i=0;i<cnt[1];i++)putchar('b');
			for(int i=0;i<cnt[2];i++)putchar('c');
		}
		for(int j=3;j<26;j++)for(int k=0;k<cnt[j];k++)putchar('a'+j);
		puts("");
	}
}