#include <bits/stdc++.h>
using namespace std;
long long n;
long long t[109];
long long ans=1;
int main()
{
    cin>>n;
    for(long long i=1; i<=n; i++) cin>>t[i];
    for(long long s=1; s<=n; s++)
    {
        long long akt=t[s];
        long long co=1;
        while(akt!=s)
        {
            co++;
            akt=t[akt];
            if(co>n+1)
            {
                cout<<-1<<endl;
                return 0;
            }
        }
        if(co%2==0) co/=2;
        long long lnko=__gcd(ans, co);
        long long lkkt=ans*co;
        lkkt/=lnko;
        ans=lkkt;
    }
    cout<<ans<<endl;
    return 0;
}