#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
const int MM = 2200;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int res[MM] = {};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            switch (s[j]) {
            case 'U':
                if (!(i%2)) {
                    res[j]++;
                }
                break;
            case 'L':
                if (j-i >= 0) {
                    res[j-i]++;
                }
                break;
            case 'R':
                if (j+i < m) {
                    res[j+i]++;
                }
                break;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d", res[i]);
        if (i != m-1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}