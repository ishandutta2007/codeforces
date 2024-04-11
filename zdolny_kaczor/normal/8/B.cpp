# include <cstdio>
const int MN = 111;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
char input[MN];
bool visited[MN * 2][MN * 2];
int main()
{
    scanf("%s", input);
    int x = MN, y = MN;
    visited[x][y] = true;
    for (int i = 0; input[i]; ++i)
    {
        int newx = x, newy = y;
        switch(input[i])
        {
            case 'U':
                newx++;
            break;
            case 'D':
                newx--;
            break;
            case 'L':
                newy++;
            break;
            case 'R':
                newy--;
            break;
        }
        if (visited[newx][newy])
        {
            printf("BUG\n");
            return 0;
        }
        for (int d = 0; d < 4; ++d)
            if (visited[newx + dx[d]][newy + dy[d]] && (newx + dx[d] != x || newy + dy[d] != y))
            {
                printf("BUG\n");
                return 0;
            }
        visited[newx][newy] = true;
        x = newx;
        y = newy;
    }
    printf("OK\n");
}