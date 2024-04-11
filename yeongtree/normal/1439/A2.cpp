#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define SS1 save(i, j, i, j + 1, i + 1, j)
#define SS2 save(i + 1, j, i, j + 1, i + 1, j + 1)
#define SS3 save(i + 1, j, i, j, i + 1, j + 1)
#define SS4 save(i, j + 1, i, j, i + 1, j + 1)

using namespace std;

bool A[101][101];
struct T{int a, b, c, d, e, f;};
vector<T> ans;

void flip(int x, int y) { A[x][y] = !A[x][y]; }
void save(int a, int b, int c, int d, int e, int f)
{
    ans.push_back({a + 1, b + 1, c +1, d + 1,  e + 1, f + 1});
    flip(a, b);
    flip(c, d);
    flip(e, f);
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        ans.clear();
        int n, m; cin >> n >> m;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                char c; cin >> c;
                A[i][j] = (c == '1');
            }
        }

        if(n & 1)
        {
            for(int j = 0; j < m - 1; ++j)
            {
                if(A[n - 1][j])
                {
                    save(n - 1, j, n - 1, j + 1, n - 2, j);
                }
            }
            if(A[n - 1][m - 1]) save(n - 1, m - 1, n - 2, m - 2, n - 2, m - 1);
            --n;
        }

        if(m & 1)
        {
            for(int i = 0; i < n - 1; ++i)
            {
                if(A[i][m - 1])
                {
                    save(i, m - 1, i + 1, m - 1, i, m - 2);
                }
                if(A[n - 1][m - 1]) save(n - 1, m - 1, n - 2, m - 2, n - 1, m - 2);
            }
            --m;
        }

        for(int i = 0; i < n; i += 2)
        {
            for(int j = 0; j < m; j += 2)
            {
                int t = 0;
                if(A[i][j]) t += 1;
                if(A[i][j + 1]) t += 2;
                if(A[i + 1][j]) t += 4;
                if(A[i + 1][j + 1]) t += 8;
                if(t == 1) SS1, SS3, SS4;
                if(t == 2) SS1, SS2, SS4;
                if(t == 4) SS1, SS2, SS3;
                if(t == 8) SS2, SS3, SS4;
                if(t == 3) SS2, SS3;
                if(t == 10) SS1, SS3;
                if(t == 12) SS1, SS4;
                if(t == 5) SS2, SS4;
                if(t == 9) SS1, SS2;
                if(t == 6) SS3, SS4;
                if(t == 7) SS1;
                if(t == 14) SS2;
                if(t == 13) SS3;
                if(t == 11) SS4;
                if(t == 15) SS1, SS2, SS3, SS4;
            }
        }

        cout << ans.size() << '\n';
        for(auto i : ans) cout << i.a << ' ' << i.b << ' ' << i.c << ' ' << i.d << ' ' << i.e << ' ' << i.f << '\n';
    }
}