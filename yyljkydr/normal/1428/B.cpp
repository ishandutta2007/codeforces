#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

char s[N];

int T,n;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		scanf("%s",s);
		bool l=0,r=0;
		for(int i=0;i<n;i++)
			l|=s[i]=='<',r|=s[i]=='>';
		if(!l||!r)
			printf("%d\n",n);
		else
		{
			int ans=0;
			for(int i=0;i<n;i++)
				if(s[i]=='-'||s[(i+1)%n]=='-')
					ans++;
			printf("%d\n",ans);
		}
	}
}