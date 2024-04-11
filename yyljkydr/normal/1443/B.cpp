#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,a,b;

char s[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		scanf("%s",s+1);
		n=strlen(s+1);
		int ans=0;
		int tot=0;
		s[0]=s[n+1]='0';
		int hav=0;
		for(int i=0,j;i<=n;i=j+1)
		{
			j=i;
			if(s[i]=='1')
			{
				hav=1;
				continue;
			}
			while(j+1<=n+1&&s[j+1]=='0')
				j++;
			if(i==0||j==n+1)
				continue;
			if((j-i+1)*b>=a)
				ans+=a;
			else
				ans+=(j-i+1)*b;
			tot++;
		}
		ans+=a*hav;
		printf("%d\n",ans);
	}
}