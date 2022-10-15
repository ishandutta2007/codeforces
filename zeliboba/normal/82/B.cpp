#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int, int> pii;

vi merge (const vi & a, const vi & b) {
    int it1 = 0, it2 = 0;
    vi res;
    while (it1 < a.size() && it2 < b.size()) {
        if (a[it1] == b[it2]) {
            res.push_back(a[it1]);
        }
        if (a[it1] <= b[it2])
            ++it1;
        else ++it2;
    }
    return res;
}

void out (const vi & v) {
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
}

int main() {
    int n;
    cin >> n;
    vector<vi> pairs((n * n - n) / 2);
    for (int i = 0; i < pairs.size(); ++i) {
        int k;
        scanf("%d", &k);
        pairs[i].resize(k);
        for (int j = 0; j < k; ++j)
            scanf("%d", &pairs[i][j]);
        sort(pairs[i].begin(), pairs[i].end());
    }
    if (n == 2) {
        printf("1 %d\n%d", pairs[0][0], pairs[0].size() - 1);
        for (int i = 1; i < pairs[0].size(); ++i)
            printf(" %d", pairs[0][i]);
        printf("\n");
        return 0;
    }
    sort(pairs.begin(), pairs.end());
/*    printf("\n");
    for (int i = 0; i < pairs.size(); ++i)
        out(pairs[i]);
    printf("\n");*/
    vector<vi> res;
    int it = 0;
    for (int i = 0; i + 2 < n; ++i) {
        res.push_back(merge(pairs[it], pairs[it + 1]));
        it += n - i - 1;
    }
    res.push_back(merge(pairs.back(), pairs[pairs.size() - 3]));
    res.push_back(merge(pairs.back(), pairs[pairs.size() - 2]));
    for (int i = 0; i < res.size(); ++i) {
        printf("%d", (int)res[i].size());
        for (int j = 0; j < res[i].size(); ++j)
            printf(" %d", res[i][j]);
        printf("\n");
    }
    return 0;
}