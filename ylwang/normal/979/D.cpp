#include <bits/stdc++.h>
using namespace std;
const int N = 100000+5;
int Q;
set<int>s[N]; 
int main() {
    scanf("%d", &Q);
    while (Q--) {
        int t; scanf("%d", &t);
        if (t == 1) {
            int u; scanf("%d", &u);// set u u  
            for (int i = 1; i <= (int)sqrt(u); i ++ ) 
                if (u % i == 0) s[i].insert(u), s[u/i].insert(u);
        }//
        else {
            int x, k, ss, ans = -1, maxn = -1; scanf("%d%d%d", &x, &k, &ss);
            if (x % k) {printf("-1\n"); continue;} // x  k  =>  -1 
            set<int>::iterator it = s[k].upper_bound(ss - x);// > x 
            if(s[k].empty() || it == s[k].begin()) {printf("-1\n"); continue;} // =>  =>  -1 
            --it;
            for (; it != s[k].begin(); --it) { 
                int v = *it;
                if (maxn > x + v) break;//v xor x  x + v v  
                if (maxn < (v ^ x)) maxn = v ^ x, ans = v;// 
            }
            if (maxn < (*it ^ x)) ans = *it;//s[k].begin() 
            printf("%d\n", ans);
        }
    }
    return 0;
}