#include <bits/stdc++.h>
using namespace std;

int get_rnd() {
    int x = rand();
    x <<= 13;
    x ^= rand();
    return abs(x);
}

int main () {
    srand(clock());
    int n;
    cin >> n;
    int l=-1,r=1000000001;
    int cnt=60;
    while (r-l!=1) {
        int mid=(l+r)>>1;
        cout << "> " << mid << endl;
        cout.flush();
        --cnt;
        int ret;
        cin >> ret;
        if (ret == 1) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    //r is the highest
    //try to find d
    int gcd = -1;
    int gg = r;
    while (cnt--) {
        int x = get_rnd() % (n) + 1;
        cout << "? " << x << endl;
        cout.flush();
        int r;
        cin >> r;
        if (r ==gg) continue;
        if (gcd == -1) {
            gcd = gg - r;
        }
        else {
            gcd = __gcd(gcd,gg - r);
        }
    }
    cout << "! " << r - (n-1) * gcd << ' ' << gcd << endl;
    cout.flush();
}