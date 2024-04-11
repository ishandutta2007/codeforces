#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
bool was[100009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        ll n;
        cin>>n;
        ll start=1;
        while(4*start<=n) start*=4;
        n-=start;
        ll group=(n)/3;
        ll tp=(n)%3;
        ll small=start+group;
        if(tp==0)
        {
            cout<<small<<'\n';
            continue;
        }
        ll step=start/4;
        ll mid=2*start;
        while(step>0)
        {
            ll fullstep=group/step;
            if(fullstep==1) mid+=(2*step);
            else if(fullstep==2) mid+=(3*step);
            else if(fullstep==3) mid+=step;
            group%=step;
            step/=4;
        }
        if(tp==1) cout<<mid<<'\n';
        else cout<<(small^mid)<<'\n';
    }

    return 0;
}