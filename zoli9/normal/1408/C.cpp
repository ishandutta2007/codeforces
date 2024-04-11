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

ll n;
ll L;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(10);
    cout<<fixed;
    int test;
    cin>>test;
    while(test--)
    {
        //cout<<test<<endl;
        cin>>n>>L;
        vector<ll> t(n+2);
        t[0]=0;
        for(int i=1; i<=n; i++)
        {
            cin>>t[i];
        }
        t[n+1]=L;
        vector<long double> a(n+2);
        vector<long double> b(n+2);
        a[0]=0.0;
        for(ll i=1; i<=n+1; i++)
        {
            a[i]=a[i-1]+(t[i]-t[i-1])*1.0/i;
        }
        b[n+1]=0.0;
        for(ll i=n; i>=0; i--)
        {
            b[i]=b[i+1]+(t[i+1]-t[i])*1.0/(n-i+1);
        }
        long double small=0.0;
        long double large=1000000000.0;
        long double eps=0.00000001;
        while(small+eps<=large)
        {
            long double mid=(small+large)/2.0;
            int ai=0;
            while(ai<=n+1 && a[ai]<=mid)
            {
                ai++;
            }
            int bi=n+1;
            while(bi>=0 && b[bi]<=mid)
            {
                bi--;
            }
            ai--;
            bi++;
            if(ai>=bi)
            {
                large=mid;
                continue;
            }
            if(bi-ai>1)
            {
                small=mid;
                continue;
            }
            long double dist=t[bi]-t[ai];
            if((mid-a[ai])*(ai+1)+(mid-b[bi])*(n-bi+2)>=dist) large=mid;
            else small=mid;
        }
        cout<<small<<'\n';
    }
    return 0;
}