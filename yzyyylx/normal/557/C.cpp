#include<bits/stdc++.h>
#define N 100005
using namespace std;

int n,cnt[N],back[N],pp,cost[205];

struct Tui
{
	int len,dj;
}tui[N];

bool cmp(Tui u,Tui v)
{
	return u.len<v.len||u.len==v.len&&u.dj<v.dj;
}

int main()
{
	int i,j,k,m,an,ans;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>tui[i].len;
		cnt[tui[i].len]++;
	}
	for(i=1;i<=n;i++)
	{
		cin>>tui[i].dj;
	}
	
	sort(tui+1,tui+n+1,cmp);
	/*
	for(i=1;i<=n;i++)
	{
		cout<<tui[i].len;
	}
	return 0;
	*/
	tui[n+1].len=tui[0].len=-1;
	int sum=0;
	for(i=n;i>=1;i--)
	{
		sum+=tui[i].dj;
		if(tui[i].len!=tui[i-1].len)
		{
			back[tui[i-1].len]=sum;
		}
	}
	
	ans=back[tui[1].len];
//	cout<<ans;
	cost[tui[1].dj]++;
//	cout<<back[4];
//	for(i=1;i<=3;i++)
//	cout<<back[i]<<" ";
	for(i=2;i<=n;i++)
	{
		if(tui[i].len!=tui[i-1].len)
		{
			an=i-cnt[tui[i].len];
//			cout<<an<<endl;
			sum=back[tui[i].len];
			if(an>0)
			{
				for(j=1;j<=200;j++)
				{
					if(cost[j])
					{
						if(cost[j]>=an)
						{
							sum+=(an*j);
							an=0;
							break;
						}
						else
						{
							sum+=(cost[j]*j);
							an-=cost[j];
						}
					}
				}
			}
			ans=min(ans,sum);
		}
		cost[tui[i].dj]++;
	}
	cout<<ans;
}