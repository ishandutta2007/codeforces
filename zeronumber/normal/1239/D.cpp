#include <bits/stdc++.h>
using namespace std;
int read()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9')
	{
	    if(ch=='-')
		    f=-1; ch=getchar();
	}
    while(ch>='0'&&ch<='9')
	{
	    x=(x<<1)+(x<<3)+(ch^48); ch=getchar();
	}
    return x*f;
}
int T,n,m;
int fir[1000001],from[1000001],to[1000001],cntt;
void add(int a,int b)
{
    from[++cntt]=fir[a];
	fir[a]=cntt; to[cntt]=b;
}
int dfn[1000001],low[1000001],bel[1000001],dc,cnt;
int st[1000001],Top;
void Tarjan(int x)
{
    st[++Top]=x; dfn[x]=low[x]=++dc;
    for(int i=fir[x];i;i=from[i])
    {
        int &v=to[i];
        if(!dfn[v]) Tarjan(v),low[x]=min(low[x],low[v]);
        else if(!bel[v]) low[x]=min(low[x],dfn[v]);
    }
    if(low[x]!=dfn[x]) return;
    cnt++;
    while(st[Top]!=x)
        bel[st[Top--]]=cnt;
    bel[st[Top--]]=cnt;
}
int main()
{
    T=read();
    while(T--)
    {
        for(int i=1;i<=n;i++) fir[i]=dfn[i]=bel[i]=0;
        cntt=cnt=dc=0;
        n=read(),m=read(); int a,b;
        for(int i=1;i<=m;i++)
        {
            a=read(),b=read(); if(a==b) continue;
            add(a,b);
        }
        for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);
        if(cnt==1)
		{
		    cout<<"No"<<endl;
			continue;
		}
        int ans=0;
		for(int i=1;i<=n;i++)
		    if(bel[i]==1) ans++;
        cout<<"Yes"<<endl<<ans<<" "<<n-ans<<endl;
        for(int i=1;i<=n;i++) if(bel[i]==1) cout<<i<<" ";
        cout<<endl;
        for(int i=1;i<=n;i++) if(bel[i]!=1) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}