#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

long long dp[42][42][42][42];
string tab[64];
int last[42][42][42][42];

int main()
{
    //freopen("B.in","r",stdin);
    memset(dp, 0, sizeof(dp));

    int n, m, q;
    cin >> n >> m >> q;
    for(int i=0; i<n; i++)
        cin >> tab[i];


    memset(last, 0, sizeof(last));
    for(int a=1; a<=n; a++)
        for(int b=1; b<=m; b++)
    for(int i=a; i<=n; i++)
        for(int j=b; j<=m; j++)
        {
            last[a][b][i][j]=last[a][b][i-1][j]+1;
            if(tab[i-1][j-1]=='1')
                last[a][b][i][j]=0;
        }

    for(int a=1; a<=n; a++)
        for(int b=1; b<=m; b++)
            for(int c=a; c<=n; c++)
                for(int d=b; d<=m; d++)
                {
                    int add=100000;
                    for(int i=d; i>=b; i--)
                    {
                        add=min(add, last[a][b][c][i]);
                        dp[a][b][c][d]+=add;
                    }
                    dp[a][b][c][d]+=dp[a][b][c][d-1]+dp[a][b][c-1][d]-dp[a][b][c-1][d-1];
                }


    for(int i=0; i<q; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << dp[a][b][c][d] << endl;
    }
}