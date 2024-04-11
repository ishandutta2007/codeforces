#include <iostream>

using namespace std;

int N;

inline int dist(int x, int y)
{
    if(x <= y) return y - x;
    else return N + y - x;
}

int main()
{
    cin >> N; int m; cin >> m;
    int len[N]{}, min[N]; for(int i = 0; i < N; ++i) min[i] = N + 5;
    for(int i = 0; i < m; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;
        ++(len[x]);
        if(min[x] > dist(x, y)) min[x] = dist(x, y);
    }

    for(int i = 0; i < N; ++i)
    {
        int ans = 0;
        for(int j = 0; j < N; ++j)
        {
            if(len[j])
            {
                int k = (len[j] - 1) * N + dist(i, j) + min[j];
                if(ans < k) ans = k;
            }
        }
        cout << ans << ' ';
    }

    return 0;
}