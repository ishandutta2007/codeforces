#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int, int> pii;

const int MAX = 1000000000;

int main () {
    int n;
    scanf("%d", &n);
    int p[2];
    p[0] = 2;
    p[1] = 5;
    bool haszero = false;
    pii zero(0, 0);
    vector<vi> m(n, vi(n));
    vector<vector<vi> > mp(2, vector<vi>(n, vi(n, 0)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &m[i][j]);
            if (m[i][j] == 0) {
                mp[0][i][j] = mp[1][i][j] = MAX;
                haszero = true;
                zero = pii(i, j);
            } else {
                for (int l = 0; l < 2; ++l) {
                    while (!(m[i][j] % p[l])) {
                        m[i][j] /= p[l];
                        ++mp[l][i][j];
                    }
                }
            }
        }
    }
    vector<vector<vi> > res(2, vector<vi>(n, vi(n, MAX)));
    vector<vector<vc> > path(2, vector<vc>(n, vc(n, 0)));
    res[0][0][0] = mp[0][0][0];
    res[1][0][0] = mp[1][0][0];
    for (int l = 0; l < 2; ++l) {
        for (int j = 1; j < n; ++j) {
            if (res[l][0][j] > res[l][0][j - 1] + mp[l][0][j]) {
                res[l][0][j] = res[l][0][j - 1] + mp[l][0][j];
                path[l][0][j] = 'R';
            }
        }
        for (int i = 1; i < n; ++i) {
            if (res[l][i][0] > res[l][i - 1][0] + mp[l][i][0]) {
                res[l][i][0] = res[l][i - 1][0] + mp[l][i][0];
                path[l][i][0] = 'D';
            }
        }
    }
    for (int l = 0; l < 2; ++l) {
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                if (res[l][i][j] > res[l][i - 1][j] + mp[l][i][j]) {
                    res[l][i][j] = res[l][i - 1][j] + mp[l][i][j];
                    path[l][i][j] = 'D';
                }
                if (res[l][i][j] > res[l][i][j - 1] + mp[l][i][j]) {
                    res[l][i][j] = res[l][i][j - 1] + mp[l][i][j];
                    path[l][i][j] = 'R';
                }
            }
        }
    }
    int l0 = 0;
    if (res[1][n - 1][n - 1] < res[0][n - 1][n - 1])
        l0 = 1;
    pii cur(n - 1, n - 1);
    vc output;
    while (cur != pii(0, 0)) {
        output.push_back(path[l0][cur.first][cur.second]);
        if (output.back() == 'D')
            cur.first--;
        else
            cur.second--;
    }
    if (haszero && res[l0][n - 1][n - 1] > 1) {
        printf("1\n");
        for (int i = 0; i < zero.first; ++i)
            printf("D");
        for (int i = 0; i < zero.second; ++i)
            printf("R");
        for (int i = zero.first; i + 1 < n; ++i)
            printf("D");
        for (int i = zero.second; i + 1 < n; ++i)
            printf("R");
        return 0;
    }
    printf("%d\n", res[l0][n - 1][n - 1]);
    for (int i = 0; i < output.size(); ++i)
        printf("%c", output[output.size() - 1 - i]);
    printf("\n");
    return 0;
}