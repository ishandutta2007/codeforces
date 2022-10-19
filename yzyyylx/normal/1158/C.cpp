#include<bits/stdc++.h>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define N 500100
using namespace std;

int T,n,tt,top,num[N],ans[N],sta[N];
vector<int>son[N];

void dfs(int now)
{
    int i;
    for(i=son[now].size()-1;i>=0;i--)
    {
	dfs(son[now][i]);
    }
    ans[now]=++tt;
}

int main()
{
    int i,j;
    cin>>T;
    while(T--)
    {
	scanf("%d",&n);
	for(i=1;i<=n+1;i++) son[i].clear();
	for(i=1;i<=n;i++)
	{
	    scanf("%d",&num[i]);
	    if(num[i]==-1) num[i]=i+1;
	    son[num[i]].push_back(i);
	}
	tt=top=0;
	dfs(n+1);
	sta[++top]=n+1;
//	printf(" ");for(i=1;i<=n;i++) cout<<ans[i]<<" ";puts("");
	for(i=n;i>=1;i--)
	{
	    for(;ans[i]>ans[sta[top]];top--);
	    if(sta[top]!=num[i]) break;
	    sta[++top]=i;
	}
	if(i) puts("-1");
	else
	{
	    for(i=1;i<=n;i++) printf("%d ",ans[i]);
	    puts("");
	}
    }
}