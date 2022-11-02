#include<bits/stdc++.h>
#define maxn 1050
using namespace std;

int n;
int a[maxn][maxn],mp[maxn][maxn];

vector<int> seq;

void dfs(int x)  {
    for (int i=1;i<=n;++i)
        if (mp[x][i])  {
            mp[x][i]=mp[i][x]=0;
            dfs(i);
        }
    seq.push_back(x);
}

int main()  {
    int T;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                a[i][j]=0,mp[i][j]=(i!=j);
        if (~n&1)
            for (int i=1;i<=n;++i) mp[i][n-i+1]=0;
        seq.clear();
        dfs(1);
        for (int i=1;i<seq.size();++i)
            a[seq[i]][seq[i-1]]=1,a[seq[i-1]][seq[i]]=-1;
        for (int i=1;i<=n;++i)
            for (int j=i+1;j<=n;++j)
                printf("%d ",a[i][j]);
        puts("");
    }
    return 0;
}