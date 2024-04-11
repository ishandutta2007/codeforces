#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 25;

int A[N][N];

bool good(int* B, int m) {
    int misplaced = 0;
    for (int j = 0; j < m; j++)
        misplaced += B[j] != j;
    return misplaced <= 2;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);
            --A[i][j];
        }
    }
    for (int a = 0; a < m; a++) {
        for (int b = 0; b < max(1, a); b++) {
            for (int i = 0; i < n; i++) {
                swap(A[i][a], A[i][b]);
            }

            bool ok = true;
            for (int i = 0; i < n; i++) {
                ok &= good(A[i], m);
            }

            if (ok) {
                puts("YES");
                return 0;
            }

            for (int i = 0; i < n; i++) {
                swap(A[i][a], A[i][b]);
            }
        }
    }
    puts("NO");
}