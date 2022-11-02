#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    int w1, h1, w2, h2;
    while(cin >> w1 >> h1 >> w2 >> h2){
        long long ans = 0;
        ans += 1LL * (h1 + 2) * (w1 + 2);
        ans += 1LL * h2 * (w2 + 2);
        ans -= 1LL * w1 * h1 + 1LL * w2 * h2;
        cout << ans << endl;
    }
    return 0;
}