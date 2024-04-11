#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long t[100009];
long long db[11];
long long jegyek[100009];
long long h10[25];
long long MOD=998244353;
int n;
ll ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    h10[0]=1;
    for(int i=1; i<=21; i++)
    {
        h10[i]=(h10[i-1]*10ll)%MOD;
    }
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        ll p10=1;
        for(int j=1; j<=10; j++)
        {
            p10*=10ll;
            if(p10>t[i])
            {
                jegyek[i]=j;
                db[j]++;
                break;
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        long long w=t[i];
        for(int j=1; j<=10; j++)
        {
            ll jegy=w%10;
            w/=10;
            if(jegy==0) continue;
            //cout<<jegy<<endl;
            //cout<<db[10]<<endl;
            for(int k=1; k<=10; k++)
            {
                if(k>=j)
                {
                    ans=(ans+(ll)db[k]*jegy*h10[2*j-2])%MOD;
                }
                else
                {
                    ans=(ans+(ll)db[k]*jegy*h10[j+k-1])%MOD;
                }
                if(k>=j)
                {
                    ans=(ans+(ll)db[k]*jegy*h10[2*j-1])%MOD;
                }
                else
                {
                    ans=(ans+(ll)db[k]*jegy*h10[j+k-1])%MOD;
                }
                //cout<<"k "<<k<<": "<<ans<<endl;
            }
        }
        //cout<<ans<<endl;
    }

    cout<<ans<<endl;


    return 0;
}