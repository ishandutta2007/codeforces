#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500;

void solve() {
    int n, z;
    int ans = 0;
    cin >> n >> z;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ans = max(ans, x | z);
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}