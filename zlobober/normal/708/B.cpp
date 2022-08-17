#include <cstdio>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

typedef long long llong;

vector<int> getn(llong x) {
    if (x == 0)
        return {0, 1};
    int q = 2;
    while (q * (q - 1) / 2 < x)
        q++;
    if (q * (q - 1) / 2 == x)
        return {q};
    return {};
}

int main() {
    llong a00, a01, a10, a11;
    scanf("%lld %lld %lld %lld", &a00, &a01, &a10, &a11);
    auto vn1 = getn(a11), vn0 = getn(a00);
    vector<string> ans;
    for (int n1 : vn1) {
        for (int n0 : vn0) {
            if (n1 + n0 == 0)
                continue;
            int len = n0 + n1;
            if (a00 + a01 + a10 + a11 != (llong)len * ((llong)len - 1) / 2)
                continue;
            assert(a01 <= 1ll * n1 * n0 && a10 <= 1ll * n1 * n0);
            if (n0 == 0) {
                ans.push_back(string(n1, '1'));
            } else if (n1 == 0) {
                ans.push_back(string(n0, '0'));
            } else {
                assert(a10 / n0 <= n1);
                int bef = a10 / n0;
                int rem = a10 % n0;
                if (a10 < 1ll * n0 * n1) {
                    ans.push_back(string(bef, '1') + string(n0 - rem, '0') + string(1, '1') + string(rem, '0') + string(n1 - bef - 1, '1'));
                } else {
                    ans.push_back(string(n1, '1') + string(n0, '0'));
                }
            }
        }
    }
    if (ans.empty()) {
        puts("Impossible");
    } else {
        puts(ans.front().data());
    }
}