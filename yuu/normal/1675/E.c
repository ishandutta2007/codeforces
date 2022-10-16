#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n, k;
char s[200001];
bool done[256];
char map[256];
void solve() {
    scanf("%d %d", &n, &k);
    scanf("%s", s);
    for (int i = 'a'; i <= 'z'; i++) done[i] = 0;
    for (int i = 'a'; i <= 'z'; i++) map[i] = i;
    done['a'] = 1;
    for (int i = 0; i < n; i++) {
        if (!done[s[i]]) {
            char min = s[i];
            while (k && (!done[min])) {
                k--;
                min--;
            }
            char map_to = s[i];
            if (!done[min]) map_to = min;
            else map_to = map[min];

            for (int c = min; c <= s[i]; c++) {
                done[c] = 1;
                map[c] = map_to;
            }
        }
        s[i] = map[s[i]];
    }
    printf("%s\n", s);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}