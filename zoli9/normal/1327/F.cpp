#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, k, m;
int kum[500009];
vector<pair<pii, int>> w;
ll MOD=998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k>>m;
    for(int i=0; i<m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        w.push_back({{a, b}, c});
    }
    ll ans=1;
    for(int dg=0; dg<k; dg++)
    {
        for(int i=1; i<=n; i++) kum[i]=0;
        vi left(n+1);
        vll d(n+1);
        for(pair<pii, int> pp: w)
        {
            if((pp.S&(1<<dg))>0)
            {
                kum[pp.F.F]++;
                kum[pp.F.S+1]--;
            }
            else
            {
                left[pp.F.S]=max(left[pp.F.S], pp.F.F);
            }
        }
        for(int i=2; i<=n; i++) kum[i]+=kum[i-1];
        for(int i=2; i<=n; i++) left[i]=max(left[i], left[i-1]);
        d[0]=1;
        for(int i=1; i<=n; i++)
        {
            if(kum[i]==0)
            {
                if(left[i-1]==0) d[i]=d[i-1];
                else d[i]=(d[i-1]-d[left[i-1]-1]+MOD)%MOD;
            }
            d[i]=(d[i]+d[i-1])%MOD;
        }
        ll pl;
        if(left[n]==0) pl=d[n];
        else pl=(d[n]-d[left[n]-1]+MOD)%MOD;
        ans=(ans*pl)%MOD;
    }
    cout<<ans<<endl;

    return 0;
}