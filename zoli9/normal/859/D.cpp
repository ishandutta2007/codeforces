#include <bits/stdc++.h>
using namespace std;
int n;
long double ny[130][130];
long double bejut[130][8];
long double summa[130];
long double dp[130][8]; //elso a blokkban, round i
long double nyero[130][130][8]; //ki nyer, elso a blokkban, round i
long double hoz[130][8];
int main()
{
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;
    cin>>n;
    for(int i=1; i<=(1<<n); i++)
    {
        for(int j=1; j<=(1<<n); j++)
        {
            cin>>ny[i][j];
            ny[i][j]/=(long double)100;
        }
        bejut[i][0]=(long double)1;
    }
    for(int r=1; r<=n; r++)
    {
        for(int i=1; i<=(1<<n); i++)
        {
            bejut[i][r]=bejut[i][r-1];
            summa[i]=(long double)0;
        }
        int cnt=1;
        while(cnt<=(1<<n))
        {
            for(int egyik=cnt; egyik<cnt+(1<<(r-1)); egyik++)
            {
                for(int masik=cnt+(1<<(r-1)); masik<cnt+(1<<(r)); masik++)
                {
                    summa[egyik]+=(bejut[masik][r-1]*ny[egyik][masik]);
                    summa[masik]+=(bejut[egyik][r-1]*ny[masik][egyik]);
                }
            }
            cnt+=(1<<(r));
        }
        for(int i=1; i<=(1<<n); i++)
        {
            bejut[i][r]*=summa[i];
            hoz[i][r]=((long double)(1<<(r-1))*bejut[i][r]);
        }
    }
    for(int r=1; r<=n; r++)
    {
        for(int i=1; i<=(1<<n); i+=(1<<r))
        {
            for(int akt=i; akt<i+(1<<r); akt++)
            {
                if(akt<i+(1<<(r-1)))
                {
                    nyero[akt][i][r]=hoz[akt][r]+dp[i+(1<<(r-1))][r-1]+nyero[akt][i][r-1];
                }
                else
                {
                    nyero[akt][i][r]=hoz[akt][r]+dp[i][r-1]+nyero[akt][i+(1<<(r-1))][r-1];
                }
                dp[i][r]=max(dp[i][r], nyero[akt][i][r]);
            }
        }
    }
    cout<<dp[1][n]<<endl;

    return 0;
}