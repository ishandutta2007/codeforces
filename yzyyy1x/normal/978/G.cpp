#include<bits/stdc++.h>
using namespace std;
#define GG {printf("-1");return 0;}
struct gg{
	int s,t,c,id;
}node[110];
bool cmp(gg mo,gg ha)
{return mo.t<ha.t;}
int ans[110],n,m;
int main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>node[i].s>>node[i].t>>node[i].c,node[i].id=i;
	sort(node+1,node+m+1,cmp);	
	for(int i=1;i<=n;i++)
	{
		bool flag=0;
		for(int j=1;j<=m;j++)
		{
			if(node[j].t==i)
			{
				if(!flag)
				{
					if(node[j].c)GG;
					flag=1;
				}
				else GG;
			}
		}
		if(flag){ans[i]=m+1;continue;}
		for(int j=1;j<=m;j++)
		{
			if(node[j].c==0)continue;
			if(i>=node[j].s){node[j].c--,ans[i]=node[j].id;break;}
		}
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}