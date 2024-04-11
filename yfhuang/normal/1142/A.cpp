#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}

LL n, k;
LL a, b;

LL cal(LL step){
    step = abs(step);
    if(step == 0) return 1;
    LL g = gcd(step, n * k);
    return n * k  / g;
}
int main() {
    cin >> n >> k; 
    cin >> a >> b;
    LL x = 1e18, y = -1e18;
    for(LL i = 0;i < n;i++){
        x = min(x, cal(((a + b) + i * k) % (n * k)));
        y = max(y, cal(((a + b) + i * k) % (n * k)));
        x = min(x, cal(((a - b) + i * k) % (n * k)));
        y = max(y, cal(((a - b) + i * k) % (n * k)));
    }
    cout << x << " " << y << endl;
    return 0;
}