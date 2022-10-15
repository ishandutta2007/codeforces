#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;

int main () {
    int n;
    cin >> n;
    int d = (n + 1) / 3;
    cout << d / 12 << " " << d % 12 << endl;
    return 0;
}