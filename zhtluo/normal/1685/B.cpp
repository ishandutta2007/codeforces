#include <bits/stdc++.h>

int A, B, C, D;
char str[210000];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d", &A, &B, &C, &D);
        scanf(" %s", str);
        int s = strlen(str), acnt = 0, bcnt = 0;
        for (int i = 0; i < s; ++i) {
            if (str[i] == 'A') ++acnt; else ++bcnt;
        }
        if (A * 1 + B * 0 + C * 1 + D * 1 == acnt && A * 0 + B * 1 + C * 1 + D * 1 == bcnt) {
            std::vector<int> lens, lens2, lens3;
            for (int i = 0; i + 1 < s; ++i) {
                if (str[i] == 'A' && str[i + 1] == 'B') {
                    int j = i + 1; while (j < s && str[j] != str[j - 1]) ++j;
                    int len = j - i;
                    if (len % 2 == 0) lens.push_back(len);
                    else lens3.push_back(len);
                    i = j - 1;
                } else if (str[i] == 'B' && str[i + 1] == 'A') {
                    int j = i + 1; while (j < s && str[j] != str[j - 1]) ++j;
                    int len = j - i;
                    if (len % 2 == 0) lens2.push_back(len);
                    else lens3.push_back(len);
                    i = j - 1;
                }
            }
            std::sort(lens.begin(), lens.end());
            std::sort(lens2.begin(), lens2.end(), std::greater<int>());
            /*
            for (int i: lens) printf(": %d\n", i);
            for (int i: lens2) printf(":: %d\n", i);
            for (int i: lens3) printf("::: %d\n", i);
            */
            for (int i = 0; i < lens.size(); ++i) {
                if (C >= lens[i] / 2) {
                    C -= lens[i] / 2;
                } else {
                    D -= lens[i] / 2 - 1 - C;
                    C = 0;
                }
            }
            for (int i = 0; i < lens3.size(); ++i) {
                if (C >= lens3[i] / 2) {
                    C -= lens3[i] / 2;
                } else {
                    D -= lens3[i] / 2 - C;
                    C = 0;
                }
            }
            for (int i = 0; i < lens2.size(); ++i) {
                if (C > 0) {
                    if (C >= lens2[i] / 2 - 1) {
                        C -= lens2[i] / 2 - 1;
                    } else {
                        D -= lens2[i] / 2 - 1 - C;
                        C = 0;
                    }
                } else {
                    D -= lens2[i] / 2;
                }
            }
            if (C <= 0 && D <= 0) {
                puts ("YES");
            } else {
                puts ("NO");
            }
        } else {
            puts ("NO");
        }
    }
}