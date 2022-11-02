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
ll MOD1=1e9+7;
ll MOD2=1e9+9;
ll p1=237;
ll p2=239;
ll pws1[500009];
ll pws2[500009];
ll ans;
int a[500009];
int db[500009];
int db2[500009];
map<pair<ll, ll>, int> m;
pair<ll, ll> hshs[500009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    pws1[0]=1;
    pws2[0]=1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        pws1[i]=(p1*pws1[i-1])%MOD1;
        pws2[i]=(p2*pws2[i-1])%MOD2;
    }
    m[{0, 0}]=1;
    hshs[0]={0, 0};
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        db[a[i]]++;
        db2[a[i]]++;
        while(db2[a[i]]>3)
        {
            m[hshs[cnt]]--;
            cnt++;
            db2[a[cnt]]--;
        }
        if(db[a[i]]%3==0)
        {
            hshs[i].F=(hshs[i-1].F-2*pws1[a[i]]+2*MOD1)%MOD1;
            hshs[i].S=(hshs[i-1].S-2*pws2[a[i]]+2*MOD2)%MOD2;
        }
        else
        {
            hshs[i].F=(hshs[i-1].F+pws1[a[i]])%MOD1;
            hshs[i].S=(hshs[i-1].S+pws2[a[i]])%MOD2;
        }
        ans+=m[hshs[i]];
        m[hshs[i]]++;
    }
    cout<<ans<<endl;
    return 0;
}