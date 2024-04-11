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


ll c;
ll get_ans(ll dy, ll my, ll ai)
{
    if(my>=c) return dy;
    ll needed=c-my;
    ll d=needed/ai;
    if(needed%ai==0) return dy+d;
    else return dy+d+1;
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
        cin>>n>>c;
        vll a(n);
        vll b(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n-1; i++)
        {
            cin>>b[i];
        }
        ll best=c/a[0];
        if(c%a[0]!=0) best++;
        ll dy=0;
        ll my=0;
        for(int i=1; i<n; i++)
        {
            if(my>=b[i-1])
            {
                dy++;
                my-=b[i-1];
                best=min(best, get_ans(dy, my, a[i]));
                continue;
            }
            ll needed=b[i-1]-my;
            ll d=needed/a[i-1];
            if(needed%a[i-1]!=0) d++;
            dy+=d;
            my+=d*a[i-1];
            dy++;
            my-=b[i-1];
            best=min(best, get_ans(dy, my, a[i]));
        }
        cout<<best<<'\n';
    }
    return 0;
}