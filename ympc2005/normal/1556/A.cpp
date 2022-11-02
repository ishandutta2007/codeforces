#include <bits/stdc++.h>
using namespace std;

int T, a, b;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &a, &b);

        if ((a + b)&1) 
            puts("-1");
        else {
            if (!a && !b) 
                puts("0");
            else if (a == b)
                puts("1");
            else
                puts("2");
        }
    }
}