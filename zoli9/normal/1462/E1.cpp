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

ll MOD=1e9+7;

ll modpow(ll a)
{
  ll res=1;
  ll xp=MOD-2;
  while(xp>0)
  {
    if(xp%2) res=(res*a)%MOD;
    a=(a*a)%MOD;
    xp/=2;
  }
  return res;
}

ll fact[200009];
ll factinv[200009];

ll choose(ll x, ll y)
{
  ll res=1;
  for(int i=1; i<=y; i++)
  {
    res*=(x-i+1);
    res/=i;
  }  
  return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    fact[0]=1;
    fact[1]=1;
    factinv[0]=1;
    factinv[1]=1;
    for(int i=2; i<=200005; i++)
    {
      fact[i]=(fact[i-1]*i)%MOD;
      factinv[i]=modpow(fact[i]);
    }
    while(test--)
    {
      int n, m, k;
      //cin>>n>>m>>k;
      cin>>n;
      k=2;
      m=3;
      vi a(n);
      for(int i=0; i<n; i++)
      {
        cin>>a[i];
      }
      if(m==1)
      {
        cout<<n<<'\n';
        continue;
      }
      ll ans=0;
      sort(a.begin(), a.end());
      int v=0;
      for(int e=0; e<n; e++)
      {
        while(v<n && a[v]-a[e]<=k) v++;
        int cnt=v-e;
        //cout<<"cnt: "<<cnt<<endl;
        if(cnt>=m)
        {
          ans+=choose(cnt-1, m-1);
        }
      }
      cout<<ans<<'\n';
    }
    return 0;
}