#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long LL;

int main(){
    LL a, b, c, r;
    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> r;
        if(a > b)
            swap(a, b);
        LL L = c - r, R = c + r;
        LL L1 = max(L, a), R1 = min(R, b);
        LL cover = max(0LL, R1 - L1);
        cout << (b - a) - cover << endl;
    }
    return 0;
}