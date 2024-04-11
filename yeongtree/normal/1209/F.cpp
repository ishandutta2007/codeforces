#include <iostream>
#include <utility>
#define pii pair<int, int>
#define pll pair<long long, long long>
#define ff first
#define ss second
#include <queue>

using namespace std;

const long long QQ = 1e9 + 7;

struct X
{
    int fst, digit, x;
    long long val;
};

    bool operator< (const X &x, const X &y)
    {
        return x.fst > y.fst;
    }

vector<pii> gph[2020202];
long long len[2020202];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int pt = n - 1;
    for(int i = 1; i <= m; ++i)
    {
        int x, y; cin >> x >> y; --x; --y;

        int k = i;
        int px = x;
        int py = y;
        while(k >= 10)
        {
            gph[++pt].push_back({px, k % 10});
            px = pt;
            gph[++pt].push_back({py, k % 10});
            py = pt;
            k /= 10;
        }
        gph[x].push_back({py, k});
        gph[y].push_back({px, k});
    }

    for(int i = 0; i < 2020202; ++i)
        len[i] = -1;
    len[0] = 0;

    queue<X> Q;
    priority_queue<X> PQ;
    for(auto &i : gph[0]) PQ.push({i.ss, 0, i.ff, (long long)i.ss});
    while(!PQ.empty()) {Q.push(PQ.top()); PQ.pop();}

    while(Q.front().fst != -1)
    {
        int fst = Q.front().fst;
        int digit = Q.front().digit;
        while(Q.front().fst == fst && Q.front().digit == digit)
        {
            X &tmp = Q.front();
            if(len[tmp.x] == -1)
            {
                len[tmp.x] = tmp.val;
                for(auto &i : gph[tmp.x])
                PQ.push({i.ss, digit + 1, i.ff, (tmp.val * 10 + i.ss) % QQ});
            }
            Q.pop();
        }
        while(!Q.empty() && Q.front().fst == -1) Q.pop();
        while(!PQ.empty()) {Q.push(PQ.top()); PQ.pop();}
        Q.push({-1, -1, -1, -1});
    }

    for(int i = 1; i < n; ++i)
        cout << len[i] << '\n';
    return 0;
}