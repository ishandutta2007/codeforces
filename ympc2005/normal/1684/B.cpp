#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int T, n;

int main() {
    cin>>T;

    while (T--) {
        int a, b, c;
        cin>>a>>b>>c;
        cout<<(a + b + c)<<' '<<(b + c)<<' '<<c<<'\n';
    }
}