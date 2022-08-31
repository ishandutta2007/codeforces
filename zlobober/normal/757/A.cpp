#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 100500;
char buf[N];

int cnt[128];

int main() {
    scanf("%s", buf);
    int n = strlen(buf);
    for (int i = 0; i < n; i++) {
        cnt[buf[i]]++;
    }
    int ans = min({cnt['B'], cnt['u'] / 2, cnt['l'], cnt['b'], cnt['a'] / 2, cnt['s'], cnt['r']});
    printf("%d\n", ans);
}