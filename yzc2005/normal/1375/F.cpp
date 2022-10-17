#include <bits/stdc++.h>

long long a[5];

bool check() {
    if (a[1] == a[2]) { return true; }
    if (a[1] == a[3]) { return true; }
    if (a[2] == a[3]) { return true; }
    return false;
}

int main() {
    std::cin >> a[1] >> a[2] >> a[3];
    std::cout << "First" << std::endl;
    std::cout << (int) 2e9 << std::endl;
    int p;
    std::cin >> p;
    a[p] += 2e9;
    if (check()) { return 0; }
    long long max = *std::max_element(a + 1, a + 4);
    long long d = max * 3 - a[1] - a[2] - a[3];
    std::cout << d << std::endl;
    std::cin >> p;
    a[p] += d;
    if (check()) { return 0; }
    max = *std::max_element(a + 1, a + 4);
    long long min = *std::min_element(a + 1, a + 4);
    std::cout << (max - min) / 2 << std::endl;
    std::cin >> p;
    return 0;
}