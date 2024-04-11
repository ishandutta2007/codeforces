#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200500;

int A[N];
int incl[N];
int n;
int cur = 0;
void add(int i, int s) {
    if (i + 1 == n || i == -1)
        return;
    if (s == 1 && incl[i])
        return;
    if (s == -1 && !incl[i])
        return;
    incl[i] += s;
    int sat = (i % 2 == 0 && A[i] < A[i + 1]) || (i % 2 == 1 && A[i] > A[i + 1]);
    cur += sat * s;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    vector<int> inter;
    int was = 0;
    for (int i = 0; i < n; i++) {
        add(i, 1);
        if ((i % 2 == 0 && A[i] >= A[i + 1]) || (i % 2 == 1 && A[i] <= A[i + 1])) {
            ++was;
            for (int d = -3; d <= 3; d++) {
                if (i + d >= 0 && i + d < n)
                    inter.push_back(i + d);
            }
        }
    }
    int icur = cur;
    sort(inter.begin(), inter.end());
    if (was > 10) {
        puts("0");
        return 0;
    }
    inter.resize(unique(inter.begin(), inter.end()) - inter.begin());
        
    vector<pair<int, int>> res;
    for (int i : inter) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            add(i - 1, -1);
            add(i, -1);
            add(j - 1, -1);
            add(j, -1);
            swap(A[i], A[j]);
            add(i - 1, 1);
            add(i, 1);
            add(j - 1, 1);
            add(j, 1);
            if (cur == n - 1)
                res.push_back(make_pair(min(i, j), max(i, j)));
            add(i - 1, -1);
            add(i, -1);
            add(j - 1, -1);
            add(j, -1);
            swap(A[i], A[j]);
            add(i - 1, 1);
            add(i, 1);
            add(j - 1, 1);
            add(j, 1);
            assert(cur == icur);
        }
    }
    sort(res.begin(), res.end());
    res.resize(unique(res.begin(), res.end()) - res.begin());
    printf("%d\n", (int)res.size());
}