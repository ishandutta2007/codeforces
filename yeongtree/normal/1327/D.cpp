#include <iostream>
#include <vector>

using namespace std;

int col[202020];
int gph[202020];
bool chc[202020];
vector<vector<int>> cyc;

void mk(int x)
{
    cyc.back().push_back(x);
    int tmp = gph[x];
    while(tmp != x)
    {
        cyc.back().push_back(tmp);
        tmp = gph[tmp];
    }
}

void dfs(int x)
{
    if(chc[x])
    {
        cyc.push_back(vector<int>());
        mk(x);
        return;
    }

    chc[x] = true;
    dfs(gph[x]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i = 0; i < n; ++i) cin >> gph[i], --gph[i];
        for(int i = 0; i < n; ++i) cin >> col[i];
        for(int i = 0; i < n; ++i) chc[i] = false;
        vector<vector<int>>().swap(cyc);
        for(int i = 0; i < n; ++i) if(!chc[i]) dfs(i);
        int ans = (int)1e9;
        for(auto &V : cyc)
        {
            int N = V.size();
            for(int i = 1; i <= N; ++i)
            {
                if(N % i) continue;
                int t = N / i;
                for(int j = 0; j < t; ++j)
                {
                    bool flag = true;
                    int pr = -1;
                    for(int k = j; k < N; k += t)
                    {
                        if(pr == -1 || col[V[k]] == pr)
                            pr = col[V[k]];
                        else { flag = false; break; }
                    }
                    if(flag) ans = min(ans, t);
                }
            }
        }
        cout << ans << '\n';
    }
}