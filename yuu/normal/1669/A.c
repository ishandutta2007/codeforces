#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int rating;
    scanf("%d", &rating);
    int div = 4;
    if (rating >= 1400) div--;
    if (rating >= 1600) div--;
    if (rating >= 1900) div--;
    printf("Division %d\n", div);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}