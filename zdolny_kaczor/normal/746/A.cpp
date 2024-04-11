# include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("%d\n", 7 * min(a, min(b / 2, c / 4)));
}