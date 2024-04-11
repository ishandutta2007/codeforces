#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

typedef vector<int> vi;

int gcd (int a, int b) {
    while (a % b != 0) {
        a = a % b;
        swap(a, b);
    }
    return b;
}

int main() {
    int a;
    cin >> a;
    int sum = 0;
    for (int t = 2; t < a; ++t) {
        int cur = a;
        while (cur > 0) {
            sum += cur % t;
            cur /= t;
        }
    }
    int d = gcd(sum, a - 2);
    cout << sum / d << "/" << (a - 2) / d << endl;
    return 0;
}