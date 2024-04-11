#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,k;
    cin >> n >> k;
    priority_queue<int> pq;
    for (int i=0;i<=30;++i) {
        if (((1<<i)&n) != 0) {
            pq.push((1<<i));
        }
    }
    while (pq.size() < k) {
        int _ = pq.top();
        pq.pop();
        if (_ == 1) {
            pq.push(_);
            break;
        }
        pq.push(_/2);
        pq.push(_/2);
    }
    if (pq.size() != k) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
        while (!pq.empty()) {
            cout << pq.top() << ' ';
            pq.pop();
        }
    }
}