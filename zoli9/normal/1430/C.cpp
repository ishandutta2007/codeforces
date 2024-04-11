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
        cout<<2<<'\n';
        cout<<n-1<<" "<<n<<'\n';
        for(int i=n-1; i>=2; i--)
        {
            cout<<i+1<<" "<<i-1<<'\n';
        }
    }
    return 0;
}