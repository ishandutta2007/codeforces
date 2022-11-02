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

int numdigs(int x)
{
    int res=0;
    while(x>0)
    {
        res++;
        x/=10;
    }
    return res;
}

vi digits(int x)
{
    vi res;
    while(x>0)
    {
        res.push_back(x%10);
        x/=10;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int digs=numdigs(n);
        int ans=9*(digs-1);
        vi d=digits(n);
        int si=d.size();
        si--;
        bool ok=true;
        for(int i=si; i>=0; i--)
        {
            if(d[i]>d[si])
            {
                ok=true;
                break;
            }
            if(d[i]<d[si])
            {
                ok=false;
                break;
            }
        }
        ans+=(d[si]-1);
        if(ok) ans++;
        cout<<ans<<'\n';
    }
    return 0;
}