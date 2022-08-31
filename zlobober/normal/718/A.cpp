#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

const int N = 500500;
char str[N];

int main() {
    int n, t;
    scanf("%d %d", &n, &t);
    scanf("%s", str);
    int dot = find(str, str + n, '.') - str;
    assert(dot != n);
    assert(dot != n - 1);
    int pos = dot + 1;
    while (pos < n) {
        if (str[pos] >= '5')
            break;
        pos++;
    }
    if (pos == n) {
        printf("%s\n", str);
    } else {
        while (t > 0 && pos > dot) {
            if (str[pos] < '5') {
                break;
            }
            int npos = pos - 1;
            while (str[npos] == '9' || str[npos] == '.')
                --npos;
            if (npos >= 0) {
                str[npos]++;
                pos = npos;
            } else {
                printf("1");
                for (int i = 0; i < dot; i++) {
                    printf("0");
                }
                printf("\n");
                return 0;
            }
            --t;
        }
        if (pos < dot) {
            for (int i = 0; i <= pos; i++) {
                printf("%c", str[i]);
            }
            for (int i = pos + 1; i < dot; i++)
                printf("0");
            printf("\n");
        } else {
            for (int i = 0; i <= pos; i++) {
                printf("%c", str[i]);
            }
            printf("\n");
        }
    }
}