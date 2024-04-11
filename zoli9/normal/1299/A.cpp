#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n;

ll a[100009];
ll maxb=30;
ll db[39];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        ll x=a[i];
        for(int j=0; j<30; j++)
        {
            if(x%2) db[j]++;
            x/=2;
        }
    }
    int bestx=1;
    ll bestans=0;
    for(int i=1; i<=n; i++)
    {
        ll cans=0;
        ll x=a[i];
        for(ll j=0; j<30; j++)
        {
            if(x%2 && db[j]==1)
            {
                cans+=((ll)(1LL<<j));
            }
            x/=2;
        }
        if(cans>bestans)
        {
            bestans=cans;
            bestx=i;
        }
    }
    swap(a[1], a[bestx]);
    for(int i=1; i<=n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;


    return 0;
}