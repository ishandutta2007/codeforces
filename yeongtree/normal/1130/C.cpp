#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct p
{
    short x, y;
};

struct mq
{
    p arr[(size_t)1e4 + 5];
    size_t len = 0;
    void push(short _x, short _y){arr[len].x = _x; arr[len++].y = _y;}
    void pop(void){--len;}
    p& top(void){return arr[len - 1];}
};

inline void bemin(short &x, const short &y)
{
    if(x > y) x = y;
    return;
}

int main()
{
    const short dx[4] = {0, 1, 0, -1};
    const short dy[4] = {-1, 0, 1, 0};

    short n, r1, c1, r2, c2; cin >> n >> r1 >> c1 >> r2 >> c2; --r1; --c1; --r2; --c2;
    bool arr[n][n];
    for(short i = 0; i < n; ++i)
    {
        for(short j = 0; j < n; ++j)
        {
            char a; cin >> a;
            arr[i][j] = (a == '1');
        }
    }

    short chc1[n][n]{};
    mq q; q.push(r1, c1);
    while(q.len)
    {
        short ix = q.top().x;
        short iy = q.top().y;
        q.pop();
        if(ix < 0 || ix >= n || iy < 0 || iy >= n || chc1[ix][iy] || arr[ix][iy])
            continue;
        chc1[ix][iy] = 1;
        for(int i = 0; i < 4; ++i)
            q.push(ix + dx[i], iy + dy[i]);
    }
    if(chc1[r2][c2]) {cout << '0'; return 0;}
    q.push(r2, c2);
    while(q.len)
    {
        short ix = q.top().x;
        short iy = q.top().y;
        q.pop();
        if(ix < 0 || ix >= n || iy < 0 || iy >= n || chc1[ix][iy] || arr[ix][iy])
            continue;
        chc1[ix][iy] = -1;
        for(int i = 0; i < 4; ++i)
            q.push(ix + dx[i], iy + dy[i]);
    }

    short ans = (short)1e4;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            if(chc1[i][j] != 1) continue;
            for(int k = 0; k < n; ++k)
            {
                for(int l = 0; l < n; ++l)
                {
                    if(chc1[k][l] != -1) continue;
                    short x = (i - k) * (i - k) + (j - l) * (j - l);
                    if(ans > x) ans = x;
                }
            }
        }
    }

    cout << ans;

    return 0;
}