#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n,m;

char s[N],t[N];

int f[N],g[N];

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	scanf("%s",t+1);
	for(int i=1,j=1;i<=n;i++)
	{
		if(s[i]!=t[j])
			continue;
		f[j]=i;
		j++;
		if(j>m)
			break;
	}
	for(int i=n,j=m;i>=1;i--)
	{
		if(s[i]!=t[j])
			continue;
		g[j]=i;
		j--;
		if(j<1)
			break;
	}
	int ans=0;
	for(int i=1;i<m;i++)
		ans=max(ans,g[i+1]-f[i]);
	printf("%d\n",ans);
}