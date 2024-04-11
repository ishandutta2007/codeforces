#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;

void check(int a, int b) { 
    assert(a == 0 || b == 0 || a % 2 != b % 2);
}

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    if (n > a * b) {
        printf("-1\n");
        return 0;
    }
    vector<int> even, odd;
    for (int i = 1; i <= a * b; i++) {
        ((i % 2 == 0) ? even : odd).push_back(i);
    }
    vector<vector<int>> field(a, vector<int>(b));
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            auto& lst = ((i ^ j) & 1) ? even : odd;
            field[i - 1][j - 1] = lst.back() * (lst.back() <= n);
            lst.pop_back();
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (i + 1 < a)
                check(field[i][j], field[i + 1][j]);
            if (j + 1 < b)
                check(field[i][j], field[i][j + 1]);
        }
    }
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d%c", field[i][j], " \n"[j + 1 == b]);
        }
    }
}