#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;
int f[N];

bool gao[N];

ll rnd() {
    return (((rand() << 14) ^ rand()) & ((1ll << 30) - 1));
}

int main () {
    srand(time(NULL));
    int n; scanf("%d", &n);
    vector<int> pos;
    vector<int> val;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &f[i]);
        if (f[i] == 0) pos.push_back(i);
        gao[ f[i] ] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (!gao[i]) {
            val.push_back(i);
        }
    }
    while (true) {
        //random_shuffle(val.begin(), val.end());
        int nn = (int)val.size();
        for (int i = nn - 1; i >= 1; --i) {
            swap(val[i], val[rnd() % i]);
        }
        bool x = false;
        for (int i = 0; i < pos.size(); ++i) {
            if (pos[i] == val[i]) {
                x = true;
                break;
            }
        }
        if (!x) {
            for (int i = 0; i < pos.size(); ++i) {
                f[ pos[i] ] = val[i];
            }
            for (int i = 1; i <= n; ++i) {
                cout << f[i] << " \n"[i == n];
            }
            return 0;
        }
    }
}