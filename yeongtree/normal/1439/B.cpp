#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

struct myHash
{
    int operator() (int x) const
    {
        return x ^ (x << 1);
    }
};

unordered_set<int, myHash> gph[101010];
int deg[101010];
bool vst[101010];
queue<int> Q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m, k; cin >> n >> m >> k;
        for(int i = 0; i < n; ++i) unordered_set<int, myHash>().swap(gph[i]), deg[i] = 0, vst[i] = false;
        while(Q.size()) Q.pop();
        for(int i = 0; i < m; ++i)
        {
            int x, y; cin >> x >> y; --x; --y;
            gph[x].insert(y); ++deg[x];
            gph[y].insert(x); ++deg[y];
        }
        for(int i = 0; i < n; ++i) if(deg[i] < k - 1) Q.push(i);
        while(Q.size())
        {
            int x = Q.front(); Q.pop();
            deg[x] = 0;
            vst[x] = true;
            for(auto y : gph[x]) if(!vst[y])
            {
                if(--deg[y] == k - 2)
                {
                    Q.push(y);
                }
            }
        }
        for(int i = 0; i < n; ++i) if(deg[i] == k - 1) Q.push(i);

        bool bigflag = true;
        while(Q.size())
        {
            int x = Q.front(); Q.pop();
            deg[x] = 0;
            vst[x] = true;
            vector<int> V;
            for(int y : gph[x]) if(!vst[y]) V.push_back(y);
            bool flag = ((int)V.size() == k - 1);
            if(flag)
            {
                for(int i : V)
                {
                    for(int j : V)
                    {
                        if(i != j && gph[i].count(j) == 0)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) break;
                }
            }

            if(flag)
            {
                cout << "2\n" << x + 1 << ' ';
                for(auto y : V) cout << y + 1 << ' ';
                cout << '\n';
                bigflag = false;
                break;
            }
            for(auto y : gph[x]) if(!vst[y])
            {
                if(--deg[y] == k - 1)
                {
                    Q.push(y);
                }
            }
        }

        if(bigflag)
        {
            int cnt = 0;
            for(int i = 0; i < n; ++i) if(!vst[i]) ++cnt;
            if(cnt == 0) cout << "-1\n";
            else
            {
                cout << "1 " << cnt << '\n';
                for(int i = 0; i < n; ++i) if(!vst[i]) cout << i + 1 << ' ';
                cout << '\n';
            }
        }
    }
}