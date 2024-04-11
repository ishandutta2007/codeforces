#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using ll = long long;

const int MN = 100100;

using T = tuple<ll, ll, ll>;

int main() {
    int n;
    cin >> n;
    priority_queue<T> q;
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a-d <= 0 && b-c <= 0) continue;
        if (a+b >= c+d) {
            q.push(T(a+b, a, b));
            q.push(T(c+d, c, d));
        } else {
            if (a-d > 0) {
                sm += a;
                sm -= d;
            } else {
                sm -= b;
                sm += c;
            }
        }
    }

    while (q.size()) {
        T t = q.top(); q.pop();
        sm += get<1>(t);
        t = q.top(); q.pop();
        sm -= get<2>(t);        
    }

    cout << sm << endl;
    return 0;
}