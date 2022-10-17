#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        bool arr[n][m];
        char tmp; for(auto &i : arr) for(auto &j : i) {cin >> tmp; j = (tmp == '.');}

        int rm = m + 1; vector<int> rl;
        for(int i = 0; i < n; ++i)
        {
            int sum = 0;
            for(int j = 0; j < m; ++j)
                if(arr[i][j]) ++sum;
            if(sum < rm) {rl.clear(); rm = sum;}
            if(sum == rm) rl.push_back(i);
        }

        int cm = n + 1; vector<int> cl;
        for(int j = 0; j < m; ++j)
        {
            int sum = 0;
            for(int i = 0; i < n; ++i)
                if(arr[i][j]) ++sum;
            if(sum < cm) {cl.clear(); cm = sum;}
            if(sum == cm) cl.push_back(j);
        }

        bool flag = false;
        for(int i : rl) for(int j : cl) if(arr[i][j]) flag = true;

        cout << rm + cm - (flag ? 1 : 0) << '\n';
    }

    return 0;
}