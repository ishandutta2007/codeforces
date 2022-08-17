#include <cstdio>
#include <algorithm>
using namespace std;

char buf[10];

int main() {
    int type;
    scanf("%d", &type);
    scanf("%s", buf);
    int d[4] = {buf[0] - '0', buf[1] - '0', buf[3] - '0', buf[4] - '0'};
    int f[4];
    pair<int, int> best(100, -1);
    for (f[0] = 0; f[0] < 10; f[0]++) {
        for (f[1] = 0; f[1] < 10; f[1]++) {
            for (f[2] = 0; f[2] < 10; f[2]++) {
                for (f[3] = 0; f[3] < 10; f[3]++) {
                    int h = f[0] * 10 + f[1];
                    int m = f[2] * 10 + f[3];
                    bool correct;
                    if (type == 24) {
                        correct = h >= 0 && h <= 23 && m >= 0 && m <= 59;
                    } else {
                        correct = h >= 1 & h <= 12 && m >= 0 && m <= 59;
                    }
                    if (correct) {
                        int df = 0;
                        for (int i = 0; i < 4; i++)
                            df += f[i] != d[i];
                        best = min(best, make_pair(df, f[0] * 1000 + f[1] * 100 + f[2] * 10 + f[3]));
                    }
                }
            }
        }
    }
    printf("%02d:%02d\n", best.second / 100, best.second % 100);
}