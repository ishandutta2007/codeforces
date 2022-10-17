#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=101;

int n,m;

int g[N][N];

int l,r;

typedef vector<int> vi;

vector<vi>v[32],pat;

vi end;

int main()
{
    scanf("%d%d",&l,&r);
    if(l==r)
    {
        puts("YES");
        puts("2 1");
        printf("1 2 %d\n",l);
        return 0;
    };
    for(int i=1;i<=32;i++)
        for(int j=i+1;j<=32;j++)
            g[i][j]=-1;
    int x=r-l;
    for(int i=2;i<=21;i++)
    {
        g[1][i]=1;
        for(int j=2;j<i;j++)
            g[j][i]=(1<<j-2);
    }
    int d=0;
    g[1][22]=1;
    for(int i=0;i<=19;i++)
        if(x&(1<<i))
        {
            g[i+2][22]=d+1;
            d+=1<<i;
        }
    n=22;
    if(l>1)
    {
        n=23;
        g[22][23]=l-1;
    }
    vector<pair<int,int> >vm;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(g[i][j]!=-1)
                vm.push_back(make_pair(i,j));
    puts("YES");
    printf("%d %d\n",n,vm.size());
    for(auto [x,y]:vm)
        printf("%d %d %d\n",x,y,g[x][y]);
}