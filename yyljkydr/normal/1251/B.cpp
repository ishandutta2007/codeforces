#include<bits/stdc++.h>
using namespace std;

const int N=1e2+7;

char s[N][N];

int cnt[2];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		cnt[0]=cnt[1]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=strlen(s[i]+1);j++)
				cnt[s[i][j]-'0']++;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int len=strlen(s[i]+1);
			if(len&1)
			{
				ans++;
				continue;
			}
			if(cnt[0]>0)
			{
				int tmp=cnt[0];
				if(cnt[0]&1)
					tmp--;
				tmp=min(tmp,len);
				len-=tmp;
				cnt[0]-=tmp;
			}
			if(len)
			{
				int tmp=cnt[1];
				if(cnt[1]&1)
					tmp--;
				tmp=min(len,tmp);
				len-=tmp;
				cnt[1]-=tmp;
			}
			if(!len)
				ans++;
		}
		printf("%d\n",ans);
	}
}