# include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int l = 1, r = n;
    bool first = true;
    while (l <= r) {
        if (first) {
            printf("%d ", l++);
        }
        else {
            printf("%d ", r--);
        }
        first = !first;
    }
}