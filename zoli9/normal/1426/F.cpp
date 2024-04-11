#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;
int n;
string s;
ll MOD=1e9+7;
vll h3;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    h3.resize(n+2);
    h3[0]=1;
    for(int i=1; i<=n; i++)
    {
        h3[i]=(h3[i-1]*3)%MOD;
    }
    ll ans=0;
    vll cs(n+1);
    vll as(n+1);
    vll k1(n+1);
    vll k2(n+1);
    cs[n]=0;
    k2[n]=0;
    for(int i=n-1; i>=0; i--)
    {
        cs[i]=cs[i+1];
        if(s[i]=='c') cs[i]++;
        k2[i]=k2[i+1];
        if(s[i]=='?') k2[i]++;
    }
    as[0]=0;
    k1[n]=0;
    for(int i=1; i<=n; i++)
    {
        as[i]=as[i-1];
        if(s[i-1]=='a') as[i]++;
        k1[i]=k1[i-1];
        if(s[i-1]=='?') k1[i]++;
    }
    for(int i=1; i+1<n; i++)
    {
        if(s[i]=='a' || s[i]=='c') continue;
        int k=k2[0];
        if(s[i]=='?') k--;

        ll cur=(as[i]*cs[i+1])%MOD;
        cur=(cur*h3[k])%MOD;
        //cout<<cur<<""<<endl;
        ans=(ans+cur)%MOD;

        if(k2[i+1]>0)
        {
            cur=(as[i]*k2[i+1])%MOD;
            cur=(cur*h3[k-1])%MOD;
            //cout<<cur<<"c"<<endl;
            ans=(ans+cur)%MOD;
        }

        if(k1[i]>0)
        {
            cur=(k1[i]*cs[i+1])%MOD;
            cur=(cur*h3[k-1])%MOD;
            //cout<<cur<<"a"<<endl;
            ans=(ans+cur)%MOD;
        }

        if(k1[i]>0 && k2[i+1]>0)
        {
            cur=(k1[i]*k2[i+1])%MOD;
            cur=(cur*h3[k-2])%MOD;
            //cout<<cur<<"ac"<<endl;
            ans=(ans+cur)%MOD;
        }

        //cout<<ans<<"."<<endl;

    }
    cout<<ans<<endl;
    return 0;
}