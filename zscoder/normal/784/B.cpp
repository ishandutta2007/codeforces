#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int res = 0;
    scanf("%d", &n);
    if (n == 0) {
        res = 1;
    } else {
        while (n > 0) {
            int val = n % 16;
            if (val == 0 || val == 4 || val == 6 || val == 8 || val == 9 || val == 10 || val == 11 || val == 13) {            
                res++;
            }
            if (val == 8 || val == 11) {
                res++;
            }
            n /= 16;
        }
    }

    printf("%d\n", res);
    return 0;
}