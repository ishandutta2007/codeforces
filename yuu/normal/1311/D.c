#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    // answer is at most 10000
    int ans = c - a;
    int ans_a = b, ans_b = b, ans_c = b;
    int limit = b + ans;
    for (int target_a = 1; target_a <= limit; target_a++) {
        if (abs(a - target_a) > ans) continue;
        for (int target_b = target_a; target_b <= limit; target_b += target_a) {
            if (abs(a - target_a) + abs(b - target_b) > ans) continue;
            int lower_c = (c / target_b) * target_b;
            int higher_c = lower_c + target_b;
            if (lower_c)
                if (abs(target_a - a) + abs(target_b - b) + abs(lower_c - c) < ans) {
                    ans = abs(target_a - a) + abs(target_b - b) + abs(lower_c - c);
                    ans_a = target_a;
                    ans_b = target_b;
                    ans_c = lower_c;
                }
            if (abs(target_a - a) + abs(target_b - b) + abs(higher_c - c) < ans) {
                ans = abs(target_a - a) + abs(target_b - b) + abs(higher_c - c);
                ans_a = target_a;
                ans_b = target_b;
                ans_c = higher_c;
            }
        }
    }
    printf("%d\n%d %d %d\n", ans, ans_a, ans_b, ans_c);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}