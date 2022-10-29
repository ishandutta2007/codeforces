//luogu
#include<cstdio>
#include<cstring>
using namespace std;
char s[210],sg[210];
int g[210],gs[210];
int main()
{
	int n;scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++)sg[i]=s[i];
	int gg=0,ss=0;
	for(int i=1;i<n;i++)
	{
		if(s[i]=='B')
		{
			g[++gg]=i;
			s[i]='W';
			if(s[i+1]=='W')s[i+1]='B';
			else s[i+1]='W';
		}
	}
	if(s[n]=='B')gg=0x3f3f3f3f;
	for(int i=1;i<n;i++)
	{
		if(sg[i]=='W')
		{
			gs[++ss]=i;
			sg[i]='B';
			if(sg[i+1]=='W')sg[i+1]='B';
			else sg[i+1]='W';
		}
	}
	if(sg[n]=='W')ss=0x3f3f3f3f;
	if(gg==0x3f3f3f3f&&ss==0x3f3f3f3f)puts("-1");
	else if(ss<gg)
	{
		printf("%d\n",ss);
		for(int i=1;i<ss;i++)printf("%d ",gs[i]);
		if(ss>0)printf("%d\n",gs[ss]);
	}
	else
	{
		printf("%d\n",gg);
		for(int i=1;i<gg;i++)printf("%d ",g[i]);
		if(gg>0)printf("%d\n",g[gg]);
	}
	return 0;
}