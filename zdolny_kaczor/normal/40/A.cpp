# include <cstdio>
enum {white, black};
int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    bool ans;
    if (x == 0 || y == 0)
        ans = black;
    else
    {
        int dist = x * x + y * y;
        int root;
        for (root = 0; root * root < dist; ++root)
            ;
        if (root * root == dist)
            ans = black;
        else
        {
            ans = (root % 2) ? black : white;
            if (x * y < 0)
                ans = !ans;
        }
    }
    if (ans == white)
        printf("white\n");
    else
        printf("black\n");
}