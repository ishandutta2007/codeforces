#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T,n,p,k,x,y,s[N];

char a[N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&p,&k);
		scanf("%s",a+1);
		for(int i=1;i<=n+k;i++)
			s[i]=0;
		for(int i=n;i>=1;i--)
			s[i]=s[i+k]+(a[i]=='1');
		scanf("%d%d",&x,&y);
		int ans=1e9;
		for(int i=1;i<=n-p+1;i++)
		{
			int res=y*(i-1);
			int st=i+p-1;
			int tot=(n-st+1+k-1)/k-s[st];
			res+=tot*x;
			ans=min(ans,res);
		}
		printf("%d\n",ans);
	}
}