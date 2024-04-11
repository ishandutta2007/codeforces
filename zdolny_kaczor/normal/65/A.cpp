# include <cstdio>
int main()
{
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    bool ans;
    if (d == 0)
        ans = false;
    else if (c == 0)
        ans = true;
    else if (b == 0)
        ans = false;
    else if (a == 0)
        ans = true;
    else if (f == 0)
        ans = false;
    else if (e == 0)
        ans = true;
    else
        ans = a * c * e < b * d * f;
    if (ans)
        printf("Ron\n");
    else
        printf("Hermione\n");
}