#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,m;

char s[N],t[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		m=min(n,m);
		scanf("%s",s+1);
		while(m--)
		{
			for(int i=1;i<=n;i++)
				if(s[i]=='0')
				{
					if((s[i-1]=='1')^(s[i+1]=='1'))
						t[i]='1';
					else
						t[i]='0';
				}
				else
					t[i]='1';
			for(int i=1;i<=n;i++)
				s[i]=t[i];
		}
		puts(s+1);
	}
}