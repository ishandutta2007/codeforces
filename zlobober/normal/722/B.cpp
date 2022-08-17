#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1050;

int P[N];

int S[N];

char buf[N];

char vow[] = "aeiouy";

int main() {
    int n;
    scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d ", &P[i]);
    }
    for (int i = 0; i < n; i++) {
        fgets(buf, N, stdin);
        int len = strlen(buf);
        int cnt = 0;
        for (int j = 0; j < len; j++) {
            char c = buf[j];
            if (find(vow, vow + 6, c) != vow + 6)
                cnt++;
        }
        S[i] = cnt;
    }
    bool good = true;
    for (int i = 0; i < n; i++) {
        good &= P[i] == S[i];
    }
    puts(good ? "YES" : "NO");
}