#include <bits/stdc++.h>
using namespace std;
long long n;
long long K;
vector<long long> szam;
vector<int> db;
int maxi=1;
long long MOD=1000000007;
long long d[109][10009];
long long inve[59];

long long mpower(long long x, long long y)
{
    long long res = 1;
    while (y > 0)
    {
        if (y & 1)
        {
            res = res*x;
            res%=MOD;
        }

        y = y>>1;
        x = x*x;
        x%=MOD;
    }
    return res;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>K;
    int cnt=0;
    for(long long i=2; i*i<=n; i++)
    {
        while(n%i==0)
        {
            cnt++;
            n/=i;
        }
        if(cnt>0)
        {
            szam.push_back(i);
            db.push_back(cnt);
            maxi=max(cnt, maxi);
            cnt=0;
        }
    }
    if(n>1)
    {
        szam.push_back(n);
        db.push_back(1);
    }


    for(long long i=1; i<=maxi+2; i++)
    {
        inve[i]=mpower(i, MOD-2);
    }
    long long ans=1;
    for(int i=0; i<szam.size(); i++)
    {
        d[0][0]=1;
        for(int j1=1; j1<=db[i]; j1++)
        {
            d[j1][0]=((szam[i]%MOD)*d[j1-1][0])%MOD;
        }
        for(int kk=0; kk<=K; kk++)
        {
            d[0][kk]=1;
        }

        for(int kk=1; kk<=K; kk++)
        {
            for(int j=1; j<=db[i]; j++)
            {
                d[j][kk]=0;
                for(int u=0; u<=j; u++)
                {
                    d[j][kk]+=d[u][kk-1];
                    d[j][kk]%=MOD;
                }
                d[j][kk]*=inve[j+1];
                d[j][kk]%=MOD;
            }
        }

        ans*=d[db[i]][K];
        ans%=MOD;

    }
    cout<<ans<<endl;

    return 0;
}