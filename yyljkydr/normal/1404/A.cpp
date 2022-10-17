#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T,n,k;

char a[N];

int cnt[N][3];

int t(char ch)
{
	if(isdigit(ch))
		return ch-'0';
	return 2;
}

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<k;i++)
			for(int j=0;j<3;j++)
				cnt[i][j]=0;
		scanf("%s",a);
		for(int i=0;i<n;i++)
			cnt[i%k][t(a[i])]++;
		int sum=0,que=0,ok=1;
		for(int i=0;i<k;i++)
		{
			if(cnt[i][0]&&cnt[i][1])
			{
				ok=0;
				break;
			}
			if(cnt[i][0]||cnt[i][1])
				sum+=cnt[i][1]?1:0;
			else
				que++;
		}
		if(!ok)
			puts("NO");
		else
		{
			if(sum<=k/2&&sum+que>=k/2)
				puts("YES");
			else
				puts("NO");
		}
	}
}