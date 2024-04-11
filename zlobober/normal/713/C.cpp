#include <cstdio>
#include <cassert>
#include <algorithm>
#include <map>
using namespace std;

typedef long long llong;

const int inf = 3050;

int main() {
    int n;
    scanf("%d", &n);
    map<int, llong> D;
    D[-inf] = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        x -= i;
        auto it = D.lower_bound(x);
        assert(it != D.begin());
        auto pit = it;
        --pit;
        llong k;
        if (it == D.end()) {
            k = 0;
        } else {
            k = (it->second - pit->second);
            assert((it->first - pit->first) != 0);
            assert(k % (it->first - pit->first) == 0);
            k /= (it->first - pit->first);
        }
        llong dx = pit->second + (x - pit->first) * k;
        D[x] = dx;
        for (map<int, llong>::iterator cit = D.begin(); cit != D.end(); cit++) {
             cit->second += abs(x - cit->first);
        }
        while (D.size() >= 2) {
            auto it2 = --D.end();
            auto it1 = it2;
            --it1;
            if (it2->second >= it1->second)
                D.erase(it2);
            else
                break;
        }
    }
    llong ans = D.rbegin()->second;
    printf("%lld\n", ans);
}