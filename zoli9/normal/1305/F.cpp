#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<ll> t;
int n;
bool osszetett[1000009];
vi primes;
bool tried[1000009];
int ans;

int checking(ll p)
{
    if(p<=1000000LL && tried[p]) return n;
    if(p<=1000000LL) tried[p]=true;
    ll res=0;
    //cout<<"c: "<<p<<endl;
    for(ll x: t)
    {
        if(x<p)
        {
            res+=(p-x);
        }
        else
        {
            ll re=x%p;
            res+=(min(re, p-re));
        }
        if(res>=n) return n;
    }
    return res;
}

void fact(ll x)
{
    for(int p: primes)
    {
        if(x==1) return;
        if(x%p==0)
        {
            ans=min(ans, checking(p));
            while(x%p==0) x/=p;
        }
    }
    if(x>1)
    {
        ans=min(ans, checking(x));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("of.txt", "r", stdin);
    cin>>n;
    t.resize(n);
    for(int i=0; i<n; i++)
    {
        cin>>t[i];
    }
    shuffle(t.begin(), t.end(), rng);
    for(int i=2; i<=100001; i++)
    {
        if(osszetett[i]) continue;
        primes.push_back(i);
        for(int j=2*i; j<=100001; j+=i) osszetett[j]=true;
    }
    ans=n;
    ans=min(ans, checking(2));
    ans=min(ans, checking(3));
    ans=min(ans, checking(5));
    ans=min(ans, checking(7));
    ans=min(ans, checking(11));
    ans=min(ans, checking(13));
    ans=min(ans, checking(17));

    while((double)clock() / CLOCKS_PER_SEC < 2.3)
    {
        ll x=t[rng()%n];
        if(x-1>17) fact(x-1);
        if(x>17) fact(x);
        if(x+1>17) fact(x+1);
    }

    cout<<ans<<endl;





    return 0;
}