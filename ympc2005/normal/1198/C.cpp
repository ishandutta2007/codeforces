#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, m;

bool vis[N];

vector <int> id;

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        cin>>n>>m;

        for (int i = 1; i <= 3*n; i++) {
            vis[i] = 0;
        }

        id.clear();

        for (int u, v, i = 1; i <= m; i++) {
            cin>>u>>v;

            if (!vis[u] && !vis[v]) {
                vis[u] = vis[v] = 1;
                id.push_back(i);
            }
        }

        if (id.size() >= n) {
            cout<<"Matching"<<'\n';

            for (int i = 0; i < n; i++) {
                cout<<id[i]<<' ';
            }

            cout<<'\n';
        } else {
            cout<<"IndSet"<<'\n';

            for (int i = 1, j = n; i <= 3*n; i++) {
                if (!vis[i] && j) {
                    j--;
                    cout<<i<<' ';
                } 
            }

            cout<<'\n';
        }
    }
}