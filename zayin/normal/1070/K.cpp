#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
int n,k,tot;
vector<int> ans;

bool solve() {
    tot /= k;
    int c = 0, s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
        c++;
        if (s == tot) {
            ans.push_back(c);
            s = 0;
            c = 0;
        }
        else if (s > tot) return false;
    }
    if (ans.size() != k) return false;
    puts("Yes");
    for (int i = 0; i < k; i++) printf("%d%c", ans[i], " \n"[i==k-1]);    
    return true;
}


int main() {
    scanf("%d%d", &n, &k);
    tot = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        tot += a[i];    
    }
    if (tot % k != 0) return puts("No"), 0;
    if (!solve()) {
        puts("No");
    }
}