#include <iostream>
#include <vector>

using namespace std;

int mx[303030];
vector<int> ls[303030];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        for(int i = 0; i <= n; ++i) ls[i].clear(), ls[i].shrink_to_fit(), mx[i] = (int)1e9;
        for(int i = 0; i < n; ++i) ls[i].push_back(-1);
        for(int i = 0; i < n; ++i)
        {
            int x; cin >> x; --x;
            ls[x].push_back(i);
        }
        for(int i = 0; i < n; ++i) ls[i].push_back(n);
        for(int i = 0; i < n; ++i)
        {
            int mn = -1;
            for(int j = 1; j < (int)ls[i].size(); ++j)
                mn = max(mn, ls[i][j] - ls[i][j - 1]);
            mx[mn] = min(mx[mn], i);
        }
        for(int i = 1; i <= n; ++i)
        {
            if(mx[i] == (int)1e9) cout << "-1 ";
            else cout << mx[i] + 1 << ' ';
            mx[i + 1] = min(mx[i + 1], mx[i]);
        }
        cout << '\n';
    }
}