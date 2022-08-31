#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <cassert>
#include <set>
#include <cstring>
#include <complex>

using namespace std;

typedef long long ll;

const int MN = 500500;
int a[MN];
bool f[MN];
int bac[MN], nex[MN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a+i);
    }

    f[0] = f[n-1] = true;
    for (int i = 1; i < n-1; i++) {
        if (a[i] == a[i-1] || a[i] == a[i+1]) f[i] = true;
    }

    int ma = 0, ba = 0;
    for (int i = 0; i < n; i++) {
        if (f[i]) {
            ma = max(ma, i - ba);
            for (int j = ba; j < i; j++) {
                bac[j] = ba-1;
                nex[j] = i;
            }
            ba = i+1;
        }
    }

    printf("%d\n", (ma+1) / 2);

    for (int i = 0; i < n; i++) {
        if (f[i]) {
            printf("%d ", a[i]);
        } else {
//            fprintf(stderr, "%d %d\n", bac[i], nex[i]);
            if (a[bac[i]] == a[nex[i]]) {
                printf("%d ", a[bac[i]]);
            } else {
                if (i - bac[i] < nex[i] - i) {
                    printf("%d ", a[bac[i]]);
                } else {
                    printf("%d ", a[nex[i]]);
                }
            }
        }
    } 
    printf("\n");
	return 0;
}