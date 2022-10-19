#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7,P=1e9+7;

int T,n,m;

char s[N][N];

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		int tot=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				tot+=s[i][j]=='#';
		int ans=1;
		for(int i=1;i<=tot;i++)
			ans=ans*2%P;
		if(tot==n*m)
			ans=(ans-1+P)%P;
		printf("%d\n",ans);
	}
}