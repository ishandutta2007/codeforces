#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const int N = 69;
const int M = 8;

ld p[N][M];  //p[i][j] --> i wins at round j
ld dp[N][M];  //select i as round j's winner's expect value
bool vis[N][M];

ld a[N][N];

ld solve(int i,int j)
{
    if (vis[i][j]) return dp[i][j];
    vis[i][j] = true;
    if (!j) return dp[i][j] = p[i][j];
    ld &ret = dp[i][j];
    ret = p[i][j] * (1<<j);
    ld tmp=0;
    int mask = (i^(1<<j));
    for (int opponent = ((mask >> j) << j);(((mask >> j) << j)|((1<<j)-1) )>=opponent;opponent++)
    {
        tmp = max(tmp,solve(i,j-1) + solve(opponent,j-1));
    }
    ret += tmp;
    return ret;
}

int main ()
{
    int n;
    cin >> n;
    for (int i=0;(1<<n)>i;i++)
    {
        for (int j=0;(1<<n)>j;j++)
        {
            cin >> a[i][j];
            a[i][j] /= 100;
        }
    }
    for (int j=0;n>j;j++)
    {
        for (int i=0;(1<<n)>i;i++)
        {
            //i has enemy from
            int mask = (i^(1<<j));
            ld pre;
            if (!j) pre=1;
            else pre = p[i][j-1];
            for (int opponent = ((mask >> j) << j);(((mask >> j) << j)|((1<<j)-1) )>=opponent;opponent++)
            {
                p[i][j] += (j?p[opponent][j-1]:1)*a[i][opponent];
                //cout << i << " versus "<<opponent << " , in round "<<j<<endl;
            }
            p[i][j] *= pre;
            //cout << "i = "<<i<<" , j = "<<j<<" , p = "<<p[i][j] << endl;
        }
    }
    ld mx=0;
    for (int i=0;(1<<n)>i;i++)
    {
        mx = max(mx,solve(i,n-1));
    }
    cout <<fixed << setprecision(15) << mx << endl;
}