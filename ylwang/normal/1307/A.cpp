#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 105;
int T , n , d;
int a[MAXN];
int main() {
    scanf("%d" , &T);
    while(T -- > 0) {
        scanf("%d %d" , &n , &d);
        for (int i = 1; i <= n; ++i) {
            scanf("%d" , &a[i]);
        }
        int ans = a[1];
        for (int i = 2; i <= n; ++i) {
            if(a[i] * (i - 1) <= d) {
                d -= a[i] * (i - 1);
                ans += a[i];
            }
            else {
                ans += d / (i - 1);
                break;
            }
        }
        printf("%d\n" , ans);
    }
    return 0;
}