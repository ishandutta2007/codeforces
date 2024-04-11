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

int n;
vi a;
vi b;

bool ok(int k)
{
    int m=n+k;
    int tk=m-m/4;
    ll s1=0;
    ll s2=0;
    for(int i=0; i<tk; i++)
    {
        if(i<k) s1+=100;
        else s1+=a[i-k];
        if(i<n) s2+=b[i];
    }
    return (s1>=s2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        cin>>n;
        a.resize(n);
        b.resize(n);
        for(int i=0; i<n; i++) cin>>a[i];
        for(int j=0; j<n; j++) cin>>b[j];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int k1=0;
        int k2=n;
        while(k1<=k2)
        {
            int mid=(k1+k2)/2;
            if(ok(mid)) k2=mid-1;
            else k1=mid+1;
        }
        cout<<k1<<'\n';
    }
    return 0;
}