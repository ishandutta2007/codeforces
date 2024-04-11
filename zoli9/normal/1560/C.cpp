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
        ll k;
        cin>>k;
        ll p=0;
        while(p*p<k) p++;
        p--;
        k-=(p*p);
        if(k<=p+1)
        {
            cout<<k<<" "<<p+1<<'\n';
        }
        else
        {
            k-=(p+1);
            cout<<p+1<<" "<<p-k+1<<'\n';
        }
    }
    return 0;
}