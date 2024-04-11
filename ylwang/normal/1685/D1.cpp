#include <bits/stdc++.h>
using namespace std;
const int N = 405; 
int n, a[N], b[N], p[N]; 
void works() {
    scanf("%d", &n); 
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i]); 
    while(1) {
        for (int i = 1; i <= n; ++i) p[a[i]] = i; 
        int cnt = 0; 
        memset(b, 0, sizeof(b)); 
        for (int i = 1; i <= n; ++i) {
            if (!b[i]) {
                cnt++; 
                int u = i; 
                do {
                    b[u] = cnt; 
                    u = a[u]; 
                } while(u != i); 
            }
        }
        if (cnt == 1) break; 
        for (int i = 1; i < n; ++i)
            if (b[p[i]] != b[p[i + 1]]) {swap(a[p[i]], a[p[i + 1]]); break; }
        
    }
    for (int i = 1; i <= n; i++) b[a[i]] = i; 
    int lst = 1; printf("%d ", lst);  
    for (int i = 2; i <= n; ++i) {
        lst = b[lst];
        printf("%d ", lst); 
    }
    printf("\n"); 
}
int main() {
    int T; scanf("%d", &T); 
    while (T--)
        works(); 
    return 0; 
}