#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cout << "> " << #x << ": " << x << endl; //Debug

typedef long long ll;
const int INF = 1000000000;
const ll MOD = 1000000007;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<long long> vll;


int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
   ll prod1 = 1;
    for(int i = 0; i < n; i++)
    {
        prod1 *= 7;
        prod1 %= MOD;
    }
    ll prod2 = 1;
    for(int i = 0; i < n; i++)
    {
        prod2 *= 27;
        prod2 %= MOD;
    }
    long long ans = ((prod2%MOD)-(prod1%MOD))%MOD;
    if(ans < 0)
    {
    ans += MOD;
    }
    cout << ans;
    return 0;
}