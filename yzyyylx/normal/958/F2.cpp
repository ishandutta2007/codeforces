#include<iostream>
#include<cstdio>
#define N 200100
using namespace std;

int n,m,num[N],cnt[N],need[N],ans,sum;

int main()
{
	int i,j,t;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	t=m;
	for(i=1;i<=m;i++) scanf("%d",&need[i]),sum+=need[i],t-=(!need[i]);
	for(i=1;i<=n;i++)
	{
		cnt[num[i]]++;
		if(cnt[num[i]]==need[num[i]]) t--;
		if(!t) break;
	}
	if(i>n)
	{
		puts("-1");
		return 0;
	}
	ans=i-sum;
	j=i;
	for(i=2;;i++)
	{
		cnt[num[i-1]]--;
		if(cnt[num[i-1]]<need[num[i-1]])
		{
			for(j++;j<=n;j++)
			{
				cnt[num[j]]++;
				if(num[j]==num[i-1]) break;
			}
		}
		if(j<=n) ans=min(ans,j-i+1-sum);
		else break;
	}
	cout<<ans;
}