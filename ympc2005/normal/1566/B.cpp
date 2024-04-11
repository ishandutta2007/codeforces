#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int T;

char s[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%s", s + 1);

        bool ok = 0;

        for (int i = 1; s[i]; i++)
            if (s[i] == '0')
                ok = 1;
        
        if (!ok)
            puts("0");
        else {
            int ans = 0;

            for (int j = 1; s[j]; j++)
                if (s[j] == '0')
                    ans += s[j] != s[j - 1];
            
            printf("%d\n", min(ans, 2));
        }
    }
}