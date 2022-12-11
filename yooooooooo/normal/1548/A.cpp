#include<bits/stdc++.h>
using namespace std;
int n,m,q,x,y;
int cnt[200005],num=0;
void add(int x,int y)
{
	if(x>y)swap(x,y);
	cnt[x]++;
	if(cnt[x]==1)num++;
}
void del(int x,int y)
{
	if(x>y)swap(x,y);
	cnt[x]--;
	if(!cnt[x])num--;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int ty;
		scanf("%d",&ty);
		if(ty<3)
		{
			scanf("%d%d",&x,&y);
			if(ty==1)add(x,y);
			else del(x,y);
		}
		else printf("%d\n",n-num);
	}
	return 0;
}