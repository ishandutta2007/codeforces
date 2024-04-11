#include<bits/stdc++.h>
using namespace std;

const int N=2e3+1e2+7;

int n,k;

int a[N][N];

char ans[N][N];

vector<pair<int,int> >pos;

bool cmp(pair<int,int> x,pair<int,int> y)
{
    return a[x.first][x.second]>a[y.first][y.second];
}

int mx[4];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    int p,q;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j]==n*n)
                ans[i][j]='M',p=i,q=j;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(abs(i-p)+abs(j-q)>k)
                ans[i][j]='G';
            else if(a[i][j]!=n*n)
                pos.push_back({i,j});
    sort(pos.begin(),pos.end(),cmp);
    fill(mx,mx+4,-1e9);
    for(auto [x,y]:pos)
    {
        int dis=-1e9;
        for(int S=0;S<4;S++)
        {
            int val=x*(S&1?1:-1)+y*(S&2?1:-1);
            dis=max(dis,val+mx[S^3]);
        }
        if(dis<=k)
        {
            ans[x][y]='M';
            for(int S=0;S<4;S++)
            {
                int val=x*(S&1?1:-1)+y*(S&2?1:-1);
                mx[S]=max(mx[S],val);
            }
        }
        else
            ans[x][y]='G';
    }
    for(int i=1;i<=n;i++)
        puts(ans[i]+1);
}