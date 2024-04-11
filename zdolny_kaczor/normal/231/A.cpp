# include <cstdio>
int main() {
    int n;
    scanf("%d", &n);
    int r = 0;
    for (int i = 0; i < n; ++i) {
        int h, t, n;
        scanf("%d%d%d", &h, &t, &n);
        r += (h + t + n) / 2;
    }
    printf("%d\n", r);
}