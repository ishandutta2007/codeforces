#include <bits/stdc++.h>

#define Fori(x) for(int i=0;i<x;i++)
#define Forj(x) for(int j=0;j<x;j++)
#define maxn 1110007
#define inf 0x3f3f3f3f
#define ONES(x) __builtin_popcount(x)
using namespace std;

typedef long long ll ;
const double eps =1e-8;
const int mod = 10007;
const double PI = acos(-1.0);
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bitset<2017> dp[2];
int a[2017];
int main()
{
    int n,m,x;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i){
        scanf("%d",&x), a[x] = true;
    }
    int now = 0;
    dp[now][1000] = 1;
    for(int i = 1; i<=2000; i++){
        now = 1-now;//
        dp[now].reset();
        for(int j = 0; j<=1000; j++)
        {
            if(a[j]){
                dp[now] |= (dp[1-now]<<j)>>n;// j-n 
            }
            if(dp[now][1000])
                return 0*printf("%d\n",i);
        }
    }
    puts("-1");
    return 0;
}