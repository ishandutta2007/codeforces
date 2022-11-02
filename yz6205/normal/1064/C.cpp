#include <bits/stdc++.h>
using namespace std;

const int N = 500005;
char x[N];

int main(){
    int n;
    cin >> n >> x;
    sort(x,x+n);
    cout << x << endl;
    return 0;
}