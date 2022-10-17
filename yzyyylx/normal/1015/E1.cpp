#include<map>
#include<set>
#include<stack>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define mp make_pair
#define pii pair<int,int>
using namespace std;

int n,m,vis[1010][1010],tag[1010][1010]; 
char c[1010][1010];
vector<pair<int,pii> > ans;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",c[i]+1);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j]=='*'&&c[i-1][j]=='*'&&c[i+1][j]=='*'&&c[i][j+1]=='*'&&c[i][j-1]=='*')
			{
				tag[i][j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(tag[i][j])
			{
				vis[i][j]=1;
				int tmp1=0,tmp2=0,tmp3=0,tmp4=0; 
				for(int k=i;c[k][j]=='*';k++)
				{
					tmp1++;
				}
				for(int k=i;c[k][j]=='*';k--)
				{
					tmp2++;
				}
				for(int k=j;c[i][k]=='*';k--)
				{
					tmp4++;
				}
				for(int k=j;c[i][k]=='*';k++)
				{
					tmp3++;
				}
				int cnt=0;
				int tot=min(min(tmp1,tmp2),min(tmp3,tmp4));
				ans.push_back(mp(i,mp(j,tot-1)));
				for(int k=j;cnt<tot;cnt++)
				{
					vis[i][k++]=1;
				}
				cnt=0;
				for(int k=j;cnt<tot;cnt++)
				{
					vis[i][k--]=1;
				}
				cnt=0;
				for(int k=i;cnt<tot;cnt++)
				{
					vis[k][j]=1;
					k++;
				}
				cnt=0;
				for(int k=i;cnt<tot;cnt++)
				{
					vis[k][j]=1;
					k--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(c[i][j]=='*'&&vis[i][j]==0)
			{
				puts("-1");
				return 0;
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		printf("%d %d %d\n",ans[i].first,ans[i].second.first,ans[i].second.second);
	}
}