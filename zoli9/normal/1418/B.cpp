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
        vi a(n);
        vi lo(n);
        vi w;
        for(int i=0; i<n; i++) cin>>a[i];
        for(int i=0; i<n; i++)
        {
            cin>>lo[i];
            if(lo[i]==0) w.push_back(a[i]);
        }
        sort(w.begin(), w.end());
        reverse(w.begin(), w.end());
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            if(lo[i]==0)
            {
                a[i]=w[cnt++];
            }
        }
        for(int x: a) cout<<x<<" ";
        cout<<'\n';
    }
    return 0;
}