#include <iostream>
typedef long long LL;//LL
using namespace std;
bool ans(LL r, LL g, LL b) {
    if(r - 1 > g + b || g - 1 > r + b || b - 1 > g + r) return 0;//false
    return 1;//true
}
int main() {
    ios::sync_with_stdio(0);
    LL r, g, b;
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> r >> g >> b;
        if(ans(r, g, b)) {
            cout << "Yes\n";
        }//
        else cout << "No\n";
    }
    return 0;
}