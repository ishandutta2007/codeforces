#include<cstdio>
#include<iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 2) {
        printf("-1\n");
    } else {
        long long t = 2 * 3 * 5;
        for (int i = 0; i < n - 3; ++i) {
            cout << t << endl;
            t *= 2;
        }
        printf("%d\n%d\n%d\n", 3 * 5, 2 * 3, 2 * 5);
    }
    return 0;
}