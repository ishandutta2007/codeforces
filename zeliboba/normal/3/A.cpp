#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main () {
    string s1, s2;
    cin >> s1 >> s2;
    int x1 = s1[0] - 'a', x2 = s2[0] - 'a', y1 = s1[1] - 1, y2 = s2[1] - 1;
    int res = max(abs(x1 - x2), abs(y1 - y2));
    printf("%d\n", res);
    for (int i = 0; i < res; ++i) {
        if (x1 < x2) {
            printf("R");
            ++x1;
        }
        if (x1 > x2) {
            printf("L");
            --x1;
        }
        if (y1 < y2) {
            printf("U");
            ++y1;
        }
        if (y1 > y2) {
            printf("D");
            --y1;
        }
        printf("\n");
    }
    return 0;
}