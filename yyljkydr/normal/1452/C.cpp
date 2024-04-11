#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,x,y;

char s[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans=0;
		x=y=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='(')
				x++;
			else if(s[i]=='[')
				y++;
			else if(s[i]==')')
			{
				if(x)
					x--,ans++;
			}
			else
			{
				if(y)
					y--,ans++;
			}
		}
		printf("%d\n",ans);
	}
}