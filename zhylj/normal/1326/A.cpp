#include <bits/stdc++.h>

int main() {
    int n, t;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if(n == 1) printf("-1\n");
        else if((n - 1) % 3 == 0) {
            for(int i = 1; i < n - 1; ++i) printf("2");
            printf("33\n");
        } else {
            for(int i = 1; i < n; ++i) printf("2");
            printf("3\n");
        }
    }
    return 0;
}