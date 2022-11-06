#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

#define ll long long

using namespace std;

int n, t;
ll a[1234567];

ll mod = 1e9+7;

ll bitsum[123];

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll ans = 0;
        for(int i = 0; i < 123; i++)
            bitsum[i] = 0;
        for(int i = 0; i < n; i++)
        {
            cin>>a[i];
            ll aa = a[i];
            int ind = 0;
            while(aa)
            {
                if(aa&1)
                    bitsum[ind] = (bitsum[ind]+((1LL)<<ind)%mod)%mod;
                aa /= 2;
                ind++;
            }
        }
        for(int j = 0; j < n; j++)
        {
            ll sumi = 0;
            ll aa = a[j];
            ll sumk = (n*(aa%mod))%mod;
            int ind = 0;
            while(ind < 62)
            {
                if(aa&1)
                    sumi = (sumi+bitsum[ind])%mod;
                else
                    sumk = (sumk+bitsum[ind])%mod;
                aa /= 2;
                ind++;
            }
            ans = (ans+(sumi*sumk)%mod)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}