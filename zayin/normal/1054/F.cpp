#include<bits/stdc++.h>
#define shrink(A)   (sort(A.begin(),A.end()),A.resize(unique(A.begin(),A.end())-A.begin()))
#define renew(A,x) (x=lower_bound(A.begin(),A.end(),x)-A.begin())
#define maxn 1050
using namespace std;

struct point {
    int x,y;
}   P[maxn];

int n;

vector<int> X,Y;
vector<int> px[maxn],py[maxn];

int Ix,idx[maxn][maxn];
int Iy,idy[maxn][maxn];

void init()
{
    //s'b
    scanf("%d",&n);
    for (int i=0;i<n;++i)
        scanf("%d%d",&P[i].x,&P[i].y),
        X.push_back(P[i].x),Y.push_back(P[i].y);
    shrink(X),shrink(Y);
    for (int i=0;i<n;++i)
        renew(X,P[i].x),renew(Y,P[i].y),
        px[P[i].x].push_back(P[i].y),py[P[i].y].push_back(P[i].x);
}

vector<int> G[maxn];

void join(int u,int v)
{
    if (!u||!v) return ;
    G[u].push_back(v);
    // cout<<u<<" -> "<<v<<endl;
}

void build()
{
    for (int i=0;i<X.size();++i)
    {
        sort(px[i].begin(),px[i].end());
        for (int y,j=1;j<px[i].size();++j)
            if ((y=px[i][j-1]+1)!=px[i][j])
                for (++Ix;y<px[i][j];++y)
                    idx[i][y]=Ix;
    }
    for (int i=0;i<Y.size();++i)
    {
        sort(py[i].begin(),py[i].end());
        for (int x,j=1;j<py[i].size();++j)
            if ((x=py[i][j-1]+1)!=py[i][j])
                for (++Iy;x<py[i][j];++x)
                    idy[x][i]=Iy;
    }

    // for (int i=0;i<X.size();++i)
    //     for (int j=0;j<Y.size();++j)
    //         printf("%d%c",idx[i][j]," \n"[j==Y.size()-1]);
    // for (int i=0;i<X.size();++i)
    //     for (int j=0;j<Y.size();++j)
    //         printf("%d%c",idy[i][j]," \n"[j==Y.size()-1]);

    for (int i=0;i<X.size();++i)
        for (int j=0;j<Y.size();++j)
            join(idx[i][j],idy[i][j]);
}

int ans;

int lx[maxn],ly[maxn];
int vx[maxn],vy[maxn];

bool hungary(int i)
{
    if (!i)    return 1;
    vx[i]=1;
    for (int j:G[i])
        if (!vy[j])
        {
            vy[j]=1;
            if (hungary(ly[j]))
                return lx[ly[j]=i]=j,1;
        }
    return 0;
}

void solve()
{
    build();
    for (int i=1;i<=Ix;++i)
    {
        memset(vx,0,sizeof(vy));
        memset(vy,0,sizeof(vy));
        if (hungary(i))
            ++ans;
    }

    int cx=X.size(),cy=Y.size();
    memset(vx,0,sizeof(vx));
    memset(vy,0,sizeof(vy));
    for (int i=1;i<=Ix;++i)
        if (!lx[i])
            hungary(i);

    for (int i=1;i<=Ix;++i)
        if (!vx[i])
            ++cx;
    for (int i=1;i<=Iy;++i)
        if (vy[i])
            ++cy;

    assert(cx+cy==X.size()+Y.size()+ans);
    
    printf("%d\n",cy);
    for (int i=0;i<Y.size();++i)
        for (int k,j=0;j<py[i].size();j=k+1)
        {
            for (k=j;k+1<py[i].size();++k)
            {
                if (py[i][k]+1!=py[i][k+1])
                    // cout<<i<<" "<<py[i][k]<<" "<<py[i][k+1]<<" "<<idy[i][py[i][k]+1]<<endl;
                    assert(idy[py[i][k]+1][i]);
                if (py[i][k]+1!=py[i][k+1]&&vy[idy[py[i][k]+1][i]])
                    break;
            }
            printf("%d %d %d %d\n",X[py[i][j]],Y[i],X[py[i][k]],Y[i]);
        }
    printf("%d\n",cx);
    for (int i=0;i<X.size();++i)
        for (int k,j=0;j<px[i].size();j=k+1)
        {
            for (k=j;k+1<px[i].size();++k)
                if (px[i][k]+1!=px[i][k+1]&&!vx[idx[i][px[i][k]+1]])
                    break;
            printf("%d %d %d %d\n",X[i],Y[px[i][j]],X[i],Y[px[i][k]]);
        }
}

int main()
{
    init();
    solve();
    return 0;
}