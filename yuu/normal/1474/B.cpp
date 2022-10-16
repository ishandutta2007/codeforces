#include <bits/stdc++.h>
using namespace std;
int p[30001];
vector<int> prime;
void prepare() {
    for (int i = 2; i <= 30000; i++)
        if (p[i] == 0)
            for (int j = i; j <= 30000; j += i)
                if (p[j] == 0) p[j] = i;
    for (int i = 1; i <= 30000; i++)
        if (p[i] == i) prime.push_back(i);
}
void solve() {
    int d;
    cin >> d;
    int low = 0;
    while (prime[low] < 1 + d) low++;
    int high = low;
    while (prime[high] < prime[low] + d) high++;
    cout << prime[low] * prime[high] << '\n';
}
int main() {
    prepare();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}