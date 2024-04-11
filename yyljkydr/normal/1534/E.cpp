#include<bits/stdc++.h>
using namespace std;

const int N=5e2+1e1+7;

int n,k,d[N],pre[N],ne[N];

queue<int>q;

void bfs()
{
    fill(d+1,d+n+1,-1);
    q.push(0);
    d[0]=0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<=k;i++)
        {
            if(i>x||k-i>n-x)
                continue;
            int v=x-i+(k-i);
            if(d[v]!=-1)
                continue;
            d[v]=d[x]+1;
            q.push(v);
            pre[v]=x;
        }
    }
}

vector<int>qr;

int vis[N];

int main()
{
    scanf("%d%d",&n,&k);
    bfs();
    if(d[n]==-1)
    {
        puts("-1");
        fflush(stdout);
        return 0;
    }
    int x=n;
    while(x)
        ne[pre[x]]=x,x=pre[x];
    int ans=0;
    while(x!=n)
    {
        int y=ne[x];
        //x - in + k - in = y
        assert((x+k-y)%2==0);
        int in=(x+k-y)/2;
        qr.clear();
        int out=k-in;
        for(int i=1;i<=n;i++)
        {
            if(vis[i])
            {
                if(in)
                    qr.push_back(i),in--,vis[i]=0;
            }
            else
            {
                if(out)
                    qr.push_back(i),out--,vis[i]=1;
            }
        }
        printf("? ");
        for(auto x:qr)
            printf("%d ",x);
        puts("");
        fflush(stdout);
        int now;
        scanf("%d",&now);
        ans^=now;
        x=y;
    }
    printf("! %d\n",ans);
    fflush(stdout);
}