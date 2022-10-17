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
    int n, ans = 0, flag = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x){
            flag = 1;
        }else{
            if(flag)
                ans++;
            flag = 0;
        }
    }
    if(flag)
        ans++;
    ans = min(ans, 2);
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