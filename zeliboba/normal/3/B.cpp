#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main () {
    int n, V;
    scanf("%d%d", &n, &V);
    vector<pii> v(n);
    vi w(n), c(n);
    for (int i = 0; i < n; ++i) {
        int a,b;
        scanf("%d%d", &a, &b);
        w[i] = a;
        c[i] = b;
        if (a == 1) {
            v[i] = pii(2 * b, i);
        } else {
            v[i] = pii(b, i);
        }
    }
    sort(v.begin(), v.end());
    vector<vi> res(2);
    vi out2;
    for (vector<pii>::iterator it = v.end() - 1; it >= v.begin(); --it) {
        if (V >= w[it->second]) {
            V -= w[it->second];
            res[w[it->second] - 1].push_back(it->second);
        } else if (V == 1) {
            out2.push_back(it->second);
        }
    }
    if (out2.size() > 0 && V + res[0].size() >= 2) {
        int tocomp = c[res[0].back()];
        if (V == 0)
            tocomp += c[res[0][res[0].size() - 2]];
        if (tocomp < c[out2[0]]) {
            res[1].push_back(out2[0]);
            res[0].pop_back();
            if (V == 0)
                res[0].pop_back();
        }
    }
    int sum = 0;
    for (int l = 0; l < 2; ++l)
        for (int i = 0; i < res[l].size(); ++i)
            sum += c[res[l][i]];
    printf("%d\n", sum);
    for (int l = 0; l < 2; ++l)
        for (int i = 0; i < res[l].size(); ++i)
            printf("%d ", res[l][i] + 1);
    return 0;
}