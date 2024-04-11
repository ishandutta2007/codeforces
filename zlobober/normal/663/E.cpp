#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100500;
char buf[N];

typedef long long llong;

vector<llong> conv(const vector<llong>& v1, const vector<llong>& v2) {
    if (v1.size() == 1 && v2.size() == 1)
        return { v1[0] * v2[0] };
    vector<llong> a1(v1.begin(), v1.begin() + v1.size() / 2);
    vector<llong> b1(v1.begin() + v1.size() / 2, v1.end());
    vector<llong> a2(v2.begin(), v2.begin() + v2.size() / 2);
    vector<llong> b2(v2.begin() + v2.size() / 2, v2.end());
    vector<llong> sum1(a1.size()), dif1(a1.size());
    for (int i = 0; i < a1.size(); i++)
        sum1[i] = a1[i] + b1[i], dif1[i] = a1[i] - b1[i];
    vector<llong> sum2(a2.size()), dif2(a2.size());
    for (int i = 0; i < a2.size(); i++)
        sum2[i] = a2[i] + b2[i], dif2[i] = a2[i] - b2[i];
    vector<llong> sum = conv(sum1, sum2);
    vector<llong> dif = conv(dif1, dif2);
    vector<llong> res(v1.size());
    for (int i = 0; i < sum.size(); i++) {
        res[i] = (sum[i] + dif[i]);
        res[i + res.size() / 2] = (sum[i] - dif[i]);
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    vector<llong> G(1 << n);
    vector<llong> P(1 << n);
    for (int i = 1; i < (1 << n); i++)
        P[i] = 1 + P[i & (i - 1)];
    for (int i = 0; i < (1 << n); i++)
        G[i] = min(P[i], n - P[i]);
    vector<llong> A(m);
    vector<llong> F(1 << n);
    for (int i = 0; i < n; i++) {   
        scanf("%s", buf);
        for (int j = 0; j < m; j++) {
            if (buf[j] == '1')
                A[j] |= (1 << i);
        }       
    }
    for (int x : A)
        F[x]++;
    vector<llong> res = conv(F, G);
    llong ans = *min_element(res.begin(), res.end());
    printf("%lld\n", ans >> n);
}