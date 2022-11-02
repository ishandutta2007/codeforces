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
        int n;
        cin>>n;
        vpii a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i].F;
            a[i].S=i+1;
        }
        sort(a.begin(), a.end());
        if(n==1)
        {
            cout<<1<<'\n';
            continue;
        }
        int ans=-1;
        for(int i=0; i<n; i++)
        {
            if(i==0 && a[i].F!=a[i+1].F)
            {
                ans=a[i].S;
                break;
            }
            if(i==n-1 && a[i].F!=a[i-1].F)
            {
                ans=a[i].S;
                break;
            }
            if(a[i].F!=a[i-1].F && a[i].F!=a[i+1].F)
            {
                ans=a[i].S;
                break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}