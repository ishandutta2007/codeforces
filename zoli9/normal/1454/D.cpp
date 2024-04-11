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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        ll n;
        ll m;
        cin>>n;
        m=n;
        ll best=-1;
        ll bestcnt=-1;
        for(ll i=2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                ll cur=0;
                while(n%i==0)
                {
                    n/=i;
                    cur++;
                }
                if(cur>bestcnt)
                {
                    bestcnt=cur;
                    best=i;
                }
            }
        }
        if(bestcnt<0)
        {
            cout<<1<<'\n';
            cout<<m<<'\n';
            continue;
        }
        n=m;
        cout<<bestcnt<<'\n';
        for(int i=1; i<bestcnt; i++)
        {
            cout<<best<<" ";
            n/=best;
        }
        cout<<n<<'\n';
    }
    return 0;
}