#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

ll a, b, n;

int m;

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    n = a + b;

    while (n > m) {
        n -= ++m;
    }

    vector <int> id1, id2;

    for (int i = m; i; i--) {
        if (a >= i) {
            a -= i;
            id1.push_back(i);
        } else {
            id2.push_back(i);
        }
    }

    cout<<id1.size()<<'\n';

    for (int x : id1) {
        cout<<x<<' ';
    }

    cout<<'\n';
    cout<<id2.size()<<'\n';

    for (int x : id2) {
        cout<<x<<' ';
    }
}