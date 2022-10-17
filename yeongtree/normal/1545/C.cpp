#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG
const int Q = 998'244'353;

using namespace std;

int N;
bool gph[1010][1010];
int col[1010];
bool vst[1010];
int mat[1010];

bool dfs(int x)
{
    vst[x] = true;
    if(col[x] == 1)
    {
        if(mat[x] == -1) return true;
        else return dfs(mat[x]);
    }
    else
    {
        for(int y = 0; y < N; ++y) if(gph[x][y] && col[y] == 1 && !vst[y])
        {
            if(dfs(y))
            {
                mat[y] = x;
                return true;
            }
        }
        return false;
    }
}

int vst2[1010];
bool dfs2(int x, int ret, int c)
{
    vst2[x] = c;
    if(col[x] == 1)
    {
        return dfs2(mat[x], ret, c);
    }
    else
    {
        for(int y = 0; y < N; ++y) if(gph[x][y])
        {
            if(col[y] == -1 && vst2[y] == c) ret = false;
            if(col[y] == 1 && vst2[y] == 0) ret = dfs2(y, ret, c);
        }
        return ret;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n; N = 2 * n;
        for(int i = 0; i < 2 * n; ++i) col[i] = 0, vst2[i] = 0, mat[i] = -1;
        vector<int> A[2 * n];
        for(int i = 0; i < 2 * n; ++i)
        {
            A[i].resize(n);
            for(auto &j : A[i]) cin >> j, --j;
        }
        for(int i = 0; i < 2 * n; ++i)
        {
            for(int j = 0; j < 2 * n; ++j)
            {
                if(i == j) gph[i][j] = false;
                else if(i > j) gph[i][j] = gph[j][i];
                else
                {
                    bool flag = false;
                    for(int k = 0; k < n; ++k)
                    {
                        if(A[i][k] == A[j][k])
                        {
                            flag = true;
                            break;
                        }
                    }
                    gph[i][j] = flag;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; ++i)
        {
            int x = -1;
            for(int k = 0; k < n; ++k)
            {
                int cnt[n]; for(int j = 0; j < n; ++j) cnt[j] = -1;
                for(int j = 0; j < 2 * n; ++j) if(!col[j])
                {
                    if(cnt[A[j][k]] != -1) cnt[A[j][k]] = -2;
                    else cnt[A[j][k]] = j;
                }
                for(int j = 0; j < n; ++j) if(cnt[j] >= 0) { x = cnt[j]; break; }
                if(x != -1) break;
            }

            if(x == -1)
            {
                ++ans;
                for(int j = 0; j < 2 * n; ++j) if(!col[j]) { x = j; break; }
            }

            col[x] = 1;
            for(int j = 0; j < 2 * n; ++j) if(col[j] == 0 && gph[x][j]) col[j] = -1;
        }

        for(int j = 0; j < 2 * n; ++j) if(col[j] == 0) col[j] = -1;

//        for(int i = 0; i < 2 * n; ++i) if(col[i] == -1)
//        {
//            for(int j = 0; j < 2 * n; ++j) vst[j] = false;
//            dfs(i);
//        }
//
//        int ans = 0, cc = 1;
//        for(int j = 0; j < 2 * n; ++j) if(!vst2[j])
//        {
//            if(dfs2(j, true, cc)) ++ans;
//            ++cc;
//        }

        int ret = 1;
        for(int i = 0; i < ans; ++i) ret = 2ll * ret % Q;
        cout << ret << '\n';
        for(int j = 0; j < 2 * n; ++j) if(col[j] == 1) cout << j + 1 << ' ';
        cout << '\n';
    }
}