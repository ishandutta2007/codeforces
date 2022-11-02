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

ll MOD=998244353;
ll n, m;

ll ans[200009];

ll modpow(ll x)
{
    ll res=1;
    ll ep=MOD-2;
    while(ep>0)
    {
        if(ep%2) res=(res*x)%MOD;
        ep/=2;
        x=(x*x)%MOD;
    }
    return res;
}

vll monsters;
struct shield
{
    int id;
    ll a;
    ll b;
    ll bigger;
};
vector<shield> sh;

bool cmpsh(shield x, shield y)
{
    return x.b<y.b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    monsters.resize(n);
    ll msum=0;
    for(int i=0; i<n; i++)
    {
        cin>>monsters[i];
        msum=(msum+monsters[i])%MOD;
    }
    sort(monsters.begin(), monsters.end());
    sh.resize(m);
    for(int i=0; i<m; i++)
    {
        cin>>sh[i].a;
        cin>>sh[i].b;
        sh[i].id=i+1;
    }
    sort(sh.begin(), sh.end(), cmpsh);
    int mcnt=0;
    ll monsterssum=0;
    for(int i=0; i<m; i++)
    {
        while(mcnt<n && monsters[mcnt]<sh[i].b)
        {
            monsterssum=(monsterssum+monsters[mcnt])%MOD;
            mcnt++;
        }
        sh[i].bigger=n-mcnt;
        ll sum1=monsterssum;
        ll sum2=(msum-sum1+MOD)%MOD;


        ans[sh[i].id]=0;
        if(sh[i].a>sh[i].bigger)
        {
            continue;
        }
        ll pl=(sh[i].bigger-sh[i].a);
        pl=(pl*modpow(sh[i].bigger))%MOD;
        pl=(pl*sum2)%MOD;
        ans[sh[i].id]=(ans[sh[i].id]+pl)%MOD;

        pl=(sh[i].bigger+1-sh[i].a);
        pl=(pl*modpow(sh[i].bigger+1))%MOD;
        pl=(pl*sum1)%MOD;
        ans[sh[i].id]=(ans[sh[i].id]+pl)%MOD;



    }
    for(int i=1; i<=m; i++)
    {
        cout<<ans[i]<<'\n';
    }
    return 0;
}