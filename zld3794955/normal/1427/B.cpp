#include<bits/stdc++.h>
using namespace std;
const int N=202000;
int T,n,k,a[N]={};
char ch[N]={};
int main()
{
	gets(ch);
	sscanf(ch,"%d",&T);
	while(T--)
	{
		gets(ch);
		sscanf(ch,"%d%d",&n,&k);
		gets(ch+1);
		n=strlen(ch+1);
		int l=0,r=0;
		for(int i=1;i<=n;++i)
		{
			if(!l && ch[i]=='W')
				l=i;
			if(ch[i]=='W')
				r=i;
		}
		if(l==0)
		{
			printf("%d\n",k<=1 ? k : (k-1)*2+1);
			continue;
		}
		int p=l,t=0;
		for(int i=l+1;i<=r;++i)
		{
			if(ch[i]=='W')
			{
				a[++t]=i-p-1;
				p=i;
			}
		}
		int ans=t+1,c;
		sort(a+1,a+t+1);
		for(int i=1;i<=t;++i)
		{
			c=min(k,a[i]);
			if(c==a[i])
				ans+=c*2+1;
			else
				ans+=c*2;
			k-=c;
		}
		c=min(l-1+n-r,k);
		ans+=c*2;
		printf("%d\n",ans);
	}
}