#include <bits/stdc++.h>
using namespace std;
int n;
int ans;
int sor[109];
int oszlop[109];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            char c;
            cin>>c;
            if(c=='C')
            {
                sor[i]++;
                oszlop[j]++;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        int akt=sor[i]*(sor[i]-1);
        akt/=2;
        ans+=akt;
        akt=oszlop[i]*(oszlop[i]-1);
        akt/=2;
        ans+=akt;
    }
    cout<<ans;
    return 0;
}