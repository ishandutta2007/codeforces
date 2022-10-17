#include<bits/stdc++.h>
using namespace std;

const int N=301;

int T;

int n,m,occ[N][N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii cho[N*N];

map<int,vector<int> >g;

vector<pii>can;

bool cmp(pii a,pii b)
{
    if(a.fs!=b.fs)
        return a.fs<b.fs;
    return a.sd>b.sd;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        g.clear();
        for(int i=1;i<=n*m;i++)
        {
            int x;
            scanf("%d",&x);
            g[x].push_back(i);
        }
        auto it=g.end();
        int nx=n,ny=m;
        while(1)
        {
            it--;
            auto v=it->sd;
            // reverse(v.begin(),v.end());
            can.clear();
            for(auto x:v)
            {
                can.push_back(mp(nx,ny));
                ny--;
                if(ny==0)
                    nx--,ny=m;
            }
            sort(can.begin(),can.end(),cmp);
            int t=0;
            for(auto x:v)
                cho[x]=can[t++];
            if(it==g.begin())
                break;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                occ[i][j]=0;
        int ans=0;
        for(int i=1;i<=n*m;i++)
        {
            for(int j=1;j<cho[i].sd;j++)
                if(occ[cho[i].fs][j])
                    ans++;
            occ[cho[i].fs][cho[i].sd]=1;
        }
        printf("%d\n",ans);
    }
}