#include<bits/stdc++.h>
#define maxn 305
using namespace std;

const int inf=1e8;

int n,m;
int mp[maxn][maxn],dis[maxn][maxn];

int col[maxn];

bool check()    {
    for (int i=1;i<=n;++i) col[i]=0;

    queue<int> q;
    q.push(1),col[1]=1;
    while (q.size())    {
        int i=q.front(); q.pop();
        for (int j=1;j<=n;++j)  {
            if (mp[i][j]==inf||i==j) continue;
            if (!col[j])
                q.push(j),col[j]=-col[i];
            else
            if (col[i]==col[j]) {
                // cout<<"wrong:"<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
    return 1;
}

void solve()    {
    // cout<<"in"<<endl;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            dis[i][j]=mp[i][j];

    for (int k=1;k<=n;++k)  {
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                if (i!=k&&j!=k&&i!=j&&dis[i][j]+mp[k][i]+mp[j][k]<0)  {
                    // cout<<i<<" "<<k<<" "<<j<<" "<<dis[i][j]<<"+"<<mp[i][k]<<"+"<<mp[j][k]<<endl;
                    return puts("NO"),void(0);
                }
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                if (i!=k&&j!=k&&i!=j)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        
        // cout<<"k:"<<k<<endl;
        // for (int i=1;i<=n;++i)  {
        //     for (int j=1;j<=n;++j)
        //         cout<<dis[i][j]<<" ";
        //     cout<<endl;
        // }
    }

    int p=1,q=1;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (dis[i][j]>=dis[p][q])
                p=i,q=j;
    
    puts("YES");
    printf("%d\n",dis[p][q]);
    for (int i=1;i<=n;++i)
        printf("%d ",dis[p][i]);
    puts("");
}

int main()  {
    int T=1;
    // scanf("%d",&T);
    while (T--) {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                mp[i][j]=inf*(i!=j);
        while (m--) {
            int i,j,b;
            scanf("%d%d%d",&i,&j,&b);
            if (b)
                mp[i][j]=1,mp[j][i]=-1;
            else
                mp[i][j]=mp[j][i]=1;
        }

        if (!check())
            puts("NO");
        else
            solve();
    }
    return 0;
}