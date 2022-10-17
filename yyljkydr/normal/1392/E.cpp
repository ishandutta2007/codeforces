#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=26;

int n,a[N][N],q;

vector<pair<int,int> >ans;

signed main()
{
    scanf("%lld",&n);
    for(int i=2;i<=n*2;i++)
    {
        int last=0;
        for(int j=1;j<=n;j++)
        {
            int k=i-j;
            if(k<1||k>n)
                continue;
            a[j][k]=last^(1ll<<(i-2));
            last=a[j][k];
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            printf("%lld%c",a[i][j]," \n"[j==n]);
    fflush(stdout);
    scanf("%lld",&q);
    while(q--)
    {
        int s;
        scanf("%lld",&s);
        ans.clear();
        ans.push_back(make_pair(1,1));
        for(int i=1;i<=n*2-2;i++)
        {
            int x=ans.back().first,y=ans.back().second;
            int d=a[x+1][y],r=a[x][y+1];
            int t=s&(1ll<<(i));
            if(t==d&&x+1<=n)
                ans.push_back(make_pair(x+1,y));
            else
                ans.push_back(make_pair(x,y+1));
        }
        for(auto [x,y]:ans)
            printf("%d %d\n",x,y);
        fflush(stdout);
    }
}