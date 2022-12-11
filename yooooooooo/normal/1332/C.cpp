#include<cstdio>
#include<algorithm>
using namespace std;
int ch[26][200005];
char s[200005];
int n,k,T,mx,ans=0;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++)for(int j=0;j<26;j++)ch[j][i]=0;
		scanf("%s",s+1);
		for(int i=0;i<n/k;i++)
		{
			for(int j=1;j<=k;j++)
			{
				ch[s[i*k+j]-'a'][j]++;
			}
		}
		for(int i=1;i<=k/2;i++)
		{
			mx=0;
			for(int j=0;j<26;j++)mx=max(mx,ch[j][i]+ch[j][k-i+1]);
			ans+=2*n/k-mx;
		}
		mx=0;
		if(k%2)
		{
			for(int j=0;j<26;j++)mx=max(mx,ch[j][k/2+1]);
			ans+=n/k-mx;
		}
		printf("%d\n",ans);
	}
	return 0;
}