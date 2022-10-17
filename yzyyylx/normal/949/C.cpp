#include<bits/stdc++.h>
#define N 200100
using namespace std;

int n,m,h,tt,ql,top,bb,an,ans=N,num[N],dfn[N],low[N],sta[N],A[N],B[N],cnt[N],sy[N];
bool used[N],gg[N];
vector<int>to[N];

void dfs(int now)
{
    int i,t;
    dfn[now]=low[now]=++tt;
    sta[++top]=now;
    used[now]=1;
    for(i=0;i<to[now].size();i++)
    {
	t=to[now][i];
	if(!dfn[t])
	{
	    dfs(t);
	    low[now]=min(low[now],low[t]);
	}
	else if(used[t]) low[now]=min(low[now],dfn[t]);
    }
//    cout<<" "<<now<<" "<<dfn[now]<<" "<<low[now]<<endl;
    if(low[now]==dfn[now])
    {
	ql++;
	for(;sta[top+1]!=now;top--)
	{
	    cnt[ql]++;
	    sy[sta[top]]=ql;
	    used[sta[top]]=0;
	}
//	cout<<" "<<cnt[tt]<<endl;
    }
}

int main()
{
    int i,j,p,q;
    cin>>n>>m>>h;
    for(i=1;i<=n;i++) scanf("%d",&num[i]);
    for(i=1;i<=m;i++)
    {
	scanf("%d%d",&p,&q);
	if((num[p]+1)%h==num[q]) to[p].push_back(q),A[++bb]=p,B[bb]=q;
	if((num[q]+1)%h==num[p]) to[q].push_back(p),A[++bb]=q,B[bb]=p;
    }
    for(i=1;i<=n;i++)
    {
	if(!dfn[i])
	{
	    dfs(i);
	}
    }
//    for(i=1;i<=n;i++) cout<<sy[i]<<" ";puts("");
//    cout<<ql<<":";for(i=1;i<=ql;i++) cout<<cnt[i]<<" ";puts("");
    for(i=1;i<=bb;i++)
    {
//	cout<<A[i]<<"  "<<B[i]<<endl;
	if(sy[A[i]]==sy[B[i]]) continue;
	gg[sy[A[i]]]=1;
    }
    for(i=1;i<=ql;i++)
    {
	if(gg[i]) continue;
	if(cnt[i]<ans)
	{
	    ans=cnt[i];
	    an=i;
	}
    }
    cout<<ans<<endl;
    for(i=1;i<=n;i++) if(sy[i]==an) printf("%d ",i);
}