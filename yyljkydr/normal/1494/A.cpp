#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

char s[N],t[N];

char op[2];

int main()
{
	op[0]='(';
	op[1]=')';
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans=0;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++)
				for(int k=0;k<2;k++)
				{
					for(int x=1;x<=n;x++)
					{
						if(s[x]=='A')
							t[x]=op[i];
						if(s[x]=='B')
							t[x]=op[j];
						if(s[x]=='C')
							t[x]=op[k];
					}
					int c=0;
					bool ok=1;
					for(int x=1;x<=n;x++)
					{
						if(t[x]=='(')
							c++;
						else
							c--;
						ok&=(c>=0);
					}
					ok&=(c==0);
					ans|=ok;
				}
		puts(ans?"YES":"NO");
	}
}