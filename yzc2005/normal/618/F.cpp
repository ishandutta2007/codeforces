#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const int N = 1e6 + 5;
int n, a[N], b[N], buki[N], bukj[N], ok;
ll sa[N], sb[N];

int main() {
    memset(buki, -1, sizeof(buki));
    memset(bukj, -1, sizeof(bukj));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]), sa[i] = sa[i - 1] + a[i];
    for(int i = 1; i <= n; i++)
        scanf("%d", &b[i]), sb[i] = sb[i - 1] + b[i];
    if(sa[n] > sb[n]) {
        ok = 1;
        for(int i = 1; i <= n; i++)
            swap(a[i], b[i]), swap(sa[i], sb[i]);
    }
    for(int i = 0, j = 0; i <= n; i++) {
        while(j + 1 <= n && sa[i] >= sb[j + 1]) j++;
        if(buki[sa[i] - sb[j]] != -1) {
            if(!ok) {
                printf("%d\n", i - buki[sa[i] - sb[j]]);
                for(int k = buki[sa[i] - sb[j]] + 1; k <= i; k++) printf("%d ", k);
                printf("\n%d\n", j - bukj[sa[i] - sb[j]]);
                for(int k = bukj[sa[i] - sb[j]] + 1; k <= j; k++) printf("%d ", k);
                printf("\n");   
            } else {
                printf("%d\n", j - bukj[sa[i] - sb[j]]);
                for(int k = bukj[sa[i] - sb[j]] + 1; k <= j; k++) printf("%d ", k);
                printf("\n%d\n", i - buki[sa[i] - sb[j]]);
                for(int k = buki[sa[i] - sb[j]] + 1; k <= i; k++) printf("%d ", k);
                printf("\n");
            }
            return 0;
        }
        buki[sa[i] - sb[j]] = i, bukj[sa[i] - sb[j]] = j;
    }
    return 0;
}