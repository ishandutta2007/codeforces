#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        if(x > y)
            swap(x, y);
        long long ans;
        if(x <= 0 and y >= 0){
            ans = (y - x) * a;
        }
        if(y <= 0){
            ans = (y - x) * a + (-y) * min(2 * a, b);
        }
        if(x >= 0){
            ans = (y - x) * a + x * min(2 * a, b);
        }
        cout << ans << endl;
    }
    return 0;
}