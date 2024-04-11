#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 2*1006;

int c[N][N];

int a[N];

int get_pos(int x)
{
    return x+1006;
}

int main ()
{
    int n;
    scanf("%d",&n);
    int nowx = 0,nowy = 0;
    int sum_a = 0;
    int max_y = -123456789, min_y = 123456789;
    memset(c,0,sizeof(c));
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        sum_a += a[i];
        int cnt=a[i];
        int dx=1;
        int dy=(i%2==1?1:-1);
        char now = (i%2==1?'/' : '\\');
        while (cnt--)
        {
            nowx += dx;
            nowy += dy;
            c[ get_pos(nowx) ][ get_pos(nowy) ] = (now);
            max_y = max(max_y,nowy);
            min_y = min(min_y,nowy);
        }
        nowy += dy;
    }
    for (int i=max_y;i>=min_y;i--)
    {
        for (int j=1;sum_a>=j;j++)
        {
            if (c[get_pos(j)][get_pos(i)] == 0) printf(" ");
            else printf("%c",char(c[get_pos(j)][get_pos(i)]));
        }
        puts("");
    }
}