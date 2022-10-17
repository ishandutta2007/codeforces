#include <iostream>
#include <vector>

using namespace std;

bool isCycle(const vector<vector<int> > &road, const vector<vector<int> > &cost,
             const int& t, vector<int> &visit, vector<int> &cmp, int node, int &level)
{
    if(visit[node] == 1) return false;
    else if(visit[node] == -1) return true;

    visit[node] = -1;

    int M = road[node].size();
    for(int i = 0; i < M; ++i)
        if(cost[node][i] > t && isCycle(road, cost, t, visit, cmp, road[node][i], level))
            return true;

    cmp[node] = --level;
    visit[node] = 1;
    return false;
}

bool isCycle(const vector<vector<int> > &road, const vector<vector<int> > &cost,
             const int& t, vector<int> &cmp)
{
    int N = road.size();
    vector<int> visit(N);
    int level = N;

    for(int i = 0; i < N; ++i)
        if(isCycle(road, cost, t, visit, cmp, i, level)) return true;

    return false;
}

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int> > road(n), cost(n);
    vector<int> S, E;
    for(int i = 0; i < m; ++i)
    {
        int s, e, c; cin >> s >> e >> c;
        --s; --e;
        road[s].push_back(e);
        cost[s].push_back(c);
        S.push_back(s);
        E.push_back(e);
    }

    int f = -1 , r = (int)1e9 + 1;
    vector<int> cmp(n);
    while(f + 1 < r)
    {
        int mid = (f + r) / 2;
        if(isCycle(road, cost, mid, cmp)) f = mid;
        else r = mid;
    }
    isCycle(road, cost, r, cmp);

    vector<int> ans;
    for(int i = 0; i < m; ++i)
        if(cmp[S[i]] > cmp[E[i]])
            ans.push_back(i+1);

    cout << r << ' ' << ans.size() << '\n';
    for(const auto& i : ans) cout << i << ' ';
    cout << endl;

    return 0;
}