#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

#define ll long long

using namespace std;

int t, n, m, x;

int ans[1234567];

int h[1234567];


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        priority_queue<pair<int, int>> pq;
        cin >> n >> m >> x;
        cout << "YES" << endl;
        for(int i = 0; i < n; i++)
            cin >> h[i];
        for(int i = 0; i < m; i++)
            pq.push({0, i+1});
        for(int i = 0; i < n; i++)
        {
            pair<int, int> p = pq.top();
            pq.pop();
            ans[i] = p.second;
            p.first -= h[i];
            pq.push(p);
        }
        for(int i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}