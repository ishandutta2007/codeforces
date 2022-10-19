#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;

char s[1001];

int c[2];

int main()
{
	cin>>T;
	while(T--)
	{
		scanf("%s",s+1);
		c[0]=c[1]=0;
		for(int i=1;i<=strlen(s+1);i++)
			c[s[i]-'0']++;
		int tot=min(c[0],c[1]);
		puts(tot&1?"DA":"NET");
	}	
}