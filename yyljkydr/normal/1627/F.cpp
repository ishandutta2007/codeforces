#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7,K=511;

int n,k;

vector<pair<pair<int,int>,int>>g[K][K];

void add(int a,int b,int c,int d,int w)
{
    bool fd=0;
    for(auto &[p,w0]:g[a][b])
        if(p==make_pair(c,d))
            w0+=w,fd=1;
    if(!fd)
        g[a][b].push_back({{c,d},w});
}

void bd(int a,int b,int c,int d,int w)
{
    add(a,b,c,d,w);
    add(c,d,a,b,w);
    add(k+2-a,k+2-b,k+2-c,k+2-d,w);
    add(k+2-c,k+2-d,k+2-a,k+2-b,w);
}

void build(int r1,int c1,int r2,int c2)
{
    if(r1>r2||c1>c2)
        swap(r1,r2),swap(c1,c2);
    if(r1==r2)
        bd(r1,c2,r1+1,c2,1);
    else
        bd(r2,c1,r2,c1+1,1);
}

struct Nd{
    int x,y,d;
};

bool operator <(const Nd &a,const Nd &b)
{
    return a.d>b.d;
}

priority_queue<Nd>q;

int d[K][K];

int dx[]={1,0,-1,0},dy[]={0,1,0,-1};

int T;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=k+1;i++)
            for(int j=1;j<=k+1;j++)
                g[i][j].clear();
        for(int i=1;i<=n;i++)
        {
            int r1,r2,c1,c2;
            scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
            build(r1,c1,r2,c2);
        }
        for(int i=1;i<=k+1;i++)
            for(int j=1;j<=k+1;j++)
                for(int t=0;t<4;t++)
                {
                    int ni=i+dx[t],nj=j+dy[t];
                    if(ni<1||ni>k+1||nj<1||nj>k+1)
                        continue;
                    add(i,j,ni,nj,0);
                }
        for(int i=1;i<=k+1;i++)
            for(int j=1;j<=k+1;j++)
                d[i][j]=1e9;
        d[k/2+1][k/2+1]=0;
        q.push({k/2+1,k/2+1,0});
        while(!q.empty())
        {
            auto [x,y,dw]=q.top();
            q.pop();
            if(dw!=d[x][y])
                continue;
            for(auto [p,w]:g[x][y])
            {
                auto [nx,ny]=p;
                if(d[nx][ny]>dw+w)
                {
                    d[nx][ny]=dw+w;
                    q.push({nx,ny,dw+w});
                }
            }
        }
        int ans=1e9;
        for(int i=1;i<=k;i++)
            ans=min(ans,min({d[1][i],d[k+1][i],d[i][1],d[i][k+1]}));
        printf("%d\n",n-ans);
    }
}