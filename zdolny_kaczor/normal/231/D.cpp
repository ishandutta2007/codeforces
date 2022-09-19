# include <cstdio>
int x, y, z, x1, y1, z1;
int a, b, c, d, e, f;
int main() {
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d", &x, &y, &z, &x1, &y1, &z1, &a, &b, &c, &d, &e, &f);
    int res = 0;
    if (y < 0) res += a;
    if (y > y1) res += b;
    if (z < 0) res += c;
    if (z > z1) res += d;
    if (x < 0) res += e;
    if (x > x1) res += f;
    printf("%d\n", res);
    
}