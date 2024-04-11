#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

const int MN = 1100100;
int p[MN];
bool q[MN], r[MN];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", p+i);
    }
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        q[x-1] = true;
    }

    stack<int> st;
    for (int i = n-1; i >= 0; i--) {
        int d = p[i];
        if (q[i] || st.size() == 0 || st.top() != d) {
            r[i] = true;
            st.push(d);
        } else {
            st.pop();
        }
    }
    if (st.size()) {
        printf("NO\n");
    } else {
        printf("YES\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", r[i] ? -p[i] : p[i]);
        }
        printf("\n");
    }
    return 0;
}