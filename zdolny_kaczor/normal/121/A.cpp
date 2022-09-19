# include <bits/stdc++.h>
using namespace std;
vector <long long> lucky;
long long make(int len, int mask) {
    long long res = 0;
    for (int i = 0; i < len; ++i) {
        if (mask & (1 << i))
            res = res * 10 + 4;
        else
            res = res * 10 + 7;
    }
    return res;
}
int main() {
    for (int len = 1; len <= 10; ++len) {
        for (int i = 0; i < (1 << len); ++i) {
            lucky.push_back(make(len, i));
        }
    }
    lucky.push_back(0);
    sort(lucky.begin(), lucky.end());
    long long l, r;
    scanf("%lld%lld", &l, &r);
    long long res = 0;
    for (int i = 1; i < lucky.size(); ++i) {
        long long a = lucky[i - 1], b = lucky[i];
        res += b * max(0ll, (min(b, r) - max(a, l - 1)));
    }
    printf("%lld\n", res);
}