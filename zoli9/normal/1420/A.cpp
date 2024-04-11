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
        bool ans=false;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(i>0)
            {
                if(a[i]>=a[i-1])
                {
                    ans=true;
                }
            }
        }
        if(ans) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}