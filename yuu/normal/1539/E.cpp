#include <bits/stdc++.h>
using namespace std;
map<int, int> trace_l, trace_r;
set<pair<int, int>> l, r;
int k[100001];
int n, m;

void backtrace_r(int, int);
void backtrace_l(int left, int right) {
    assert(left > right);
    // we hold left currently, the card on the right
    if (left > right + 1) {
        backtrace_l(left - 1, right);
    } else {
        if (left > 1) backtrace_r(trace_l.at(left), right);
    }
    cout << "0 ";
}
void backtrace_r(int left, int right) {
    assert(left < right);
    if (right > left + 1) {
        backtrace_r(left, right - 1);
    } else {
        if (right > 1) backtrace_l(left, trace_r.at(right));
    }
    cout << "1 ";
}

void solve() {
    cin >> n >> m;
    l.insert({0, 0});
    r.insert({0, 0});
    for (int i = 1, al, bl, ar, br; i <= n; i++) {
        cin >> k[i];
        cin >> al >> bl >> ar >> br;
        bool insert_l = false, insert_r = false;
        if ((k[i] >= al) && (k[i] <= bl)) {
            // k[i] can be on the left
            if ((k[i - 1] >= ar) && (k[i - 1] <= br)) {
                // k[i-1] can be on the right
                if (!r.empty()) {  // there is a valid way to play from 1 to i-1 with k[i-1] on the right
                    trace_l[i] = r.begin()->second;
                    insert_l = true;
                }
            }
        }
        if ((k[i] >= ar) && (k[i] <= br)) {
            // k[i] can be on the right
            if ((k[i - 1] >= al) && (k[i - 1] <= bl)) {
                // k[i-1] can be on the left
                if (!l.empty()) {  // there is a valid way to play from 1 to i-1 with k[i-1] on the right
                    trace_r[i] = l.begin()->second;
                    insert_r = true;
                }
            }
        }

        // use the same hand as last time, prune the bad values
        if ((k[i] >= al) && (k[i] <= bl)) {
            while (!l.empty()) {
                if (l.begin()->first < ar)
                    l.erase(l.begin());
                else if (l.rbegin()->first > br)
                    l.erase(*l.rbegin());
                else
                    break;
            }
        } else {
            l.clear();
        }

        if ((k[i] >= ar) && (k[i] <= br)) {
            while (!r.empty()) {
                if (r.begin()->first < al)
                    r.erase(r.begin());
                else if (r.rbegin()->first > bl)
                    r.erase(*r.rbegin());
                else
                    break;
            }
        } else {
            r.clear();
        }

        if (insert_l) l.insert({k[i - 1], i - 1});
        if (insert_r) r.insert({k[i - 1], i - 1});
    }
    if (l.empty() && r.empty()) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
        if (!l.empty())
            backtrace_l(n, l.begin()->second);
        else
            backtrace_r(r.begin()->second, n);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}