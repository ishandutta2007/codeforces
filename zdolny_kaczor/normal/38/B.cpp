# include <cstdio>
bool ava[8][8];
int dx[8]={1, 1, -1, -1, 2, 2, -2, -2};
int dy[8]={2, -2, -2, 2, 1, -1, -1, 1};
bool onboard(int x, int y)
{
    return x>=0 && x<=7 && y>=0 && y<=7;
}
void knight(int x, int y)
{
    ava[x][y]=0;
    for (int i=0; i<8; ++i)
        if (onboard(x+dx[i], y+dy[i]))
            ava[x+dx[i]][y+dy[i]]=0;
}
void rook(int x, int y)
{
    for (int i=0; i<8; ++i)
        ava[x][i]=ava[i][y]=0;
}
void getcoo(int *a, int *b)
{
    int x;
    char y[2];
    scanf("%1s%d", y, &x);
    *a=x-1;
    *b=y[0]-'a';
}
int main()
{
    for (int i=0; i<8; ++i)
        for (int k=0; k<8; ++k)
            ava[i][k]=1;
    int rx, ry, nx, ny;
    getcoo(&rx, &ry);
    getcoo(&nx, &ny);
// 		printf("(%d %d) (%d %d)\n", rx, ry, nx, ny);
    rook(rx, ry);
    knight(rx, ry);
    knight(nx, ny);
    int amo=0;
    for (int i=0; i<8; ++i)
        for (int k=0; k<8; ++k)
            amo+=ava[i][k];
    printf("%d\n", amo);
}