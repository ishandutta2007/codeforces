#include<bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    while(T--) {
        int n, ans = 0, cur;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &cur);
            ans = ans + (cur != 2);
        }
        cout << ans << endl; 
    }
    return 0;
}