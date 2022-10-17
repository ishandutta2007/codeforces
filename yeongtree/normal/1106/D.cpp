#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int> > edge(n);
    for(int i = 0; i < m; ++i)
    {
        int a, b; cin >> a >> b;
        --a; --b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector<int> ans;
    priority_queue<int, vector<int>, greater<int> > pq(1,0);
    bool check[n] = {};
    while(ans.size() != n)
    {
        int here = pq.top(); pq.pop();
        check[here] = true; ans.push_back(here);
        while(!pq.empty() && pq.top() == here) pq.pop();
        for(const auto &i : edge[here])
            if(!check[i]) pq.push(i);
    }

    for(const auto &i : ans) cout << i + 1 << ' ';
    return 0;
}