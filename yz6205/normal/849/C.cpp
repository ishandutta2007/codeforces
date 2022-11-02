#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    char x = 'a';
    putchar('z');
    while (n) {
        int inc = 1;
        while (inc * (inc - 1) / 2 <= n) inc++;
        inc--;
        n -= inc * (inc - 1) / 2;
        for (int i=0;i<inc;i++) putchar(x);
        x++;
    }
    return 0;
}