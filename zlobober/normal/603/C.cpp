#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int mex(vector<int> V) {
    int ans = 0;
    while (true) {
        if (find(V.begin(), V.end(), ans) == V.end())
            break;
        ans++;
    }
    return ans;
}

int myfunc_odd(int x) {
    if (x <= 3)
        return x % 2;
    else if (x % 2 == 1)
        return 0;
    else {
        int res = 0;
        while (x % 4 != 2)
            res ^= 1, x >>= 1;
        if (x == 6)
            res ^= 1;
        return res + 1;
    }
}

int myfunc_even(int x) {
    return (x <= 2) ? x : !(x % 2);
}

void stup() {
    vector<int> D(1000);
    D[0] = 0;
    for (int i = 1; i < D.size(); i++) {
        vector<int> T;
        T.push_back(D[i - 1]);
        if (i % 2 == 0) {
            T.push_back(0);
        }
        D[i] = mex(T);
    }
    for (int i = 0; i < D.size(); i++) {
        int my = myfunc_even(i);
        printf("%d %d %d\n", i, D[i], my);
        assert(my == D[i]);
    }
    exit(0);
}

int main() {
    //stup();
    int n, k;
    scanf("%d %d", &n, &k);
    int xr = 0;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        xr ^= ((k % 2) ? myfunc_odd : myfunc_even)(t);
    }
    printf("%s\n", xr ? "Kevin" : "Nicky");
}