#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        if(n > m)
            swap(n, m);
        if(n == 1 and m == 1){
            cout << 0 << endl;
        }else{
            int ans = (n - 1) * 2 + (m - 1) + 1;
            cout << ans << endl;
        }
    }
    return 0;
}